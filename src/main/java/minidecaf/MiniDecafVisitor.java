package minidecaf;

import minidecaf.parser.*;
import minidecaf.parser.MiniDecafParser.*;

import org.antlr.v4.runtime.tree.*;

public class MiniDecafVisitor extends MiniDecafParserBaseVisitor<StringBuilder> {
    @Override
    public StringBuilder visitProgram(ProgramContext ctx) {
        StringBuilder sb = new StringBuilder();
        sb.append(".global main\n");
        sb.append("main:\n");

        sb.append(visit(ctx.expr()));

        sb.append("\tld a0, 0(sp)\n");
        sb.append("\taddi sp, sp, 8\n");
        sb.append("\tret\n");
        return sb;
    }

    @Override
    public StringBuilder visitExpr(ExprContext ctx) {
        StringBuilder sb = new StringBuilder();
        sb.append(visit(ctx.mul(0)));
        for (int i = 2; i < ctx.children.size(); i += 2) {
            sb.append(visit(ctx.children.get(i)));

            String op = ctx.children.get(i - 1).getText().equals("+") ? "add" : "sub";
            sb.append("# " + op + "\n");
            sb.append("\tld t2, 0(sp)\n");
            sb.append("\tld t1, 8(sp)\n");
            sb.append("\t" + op + " t1, t1, t2\n");
            sb.append("\taddi sp, sp, 8\n");
            sb.append("\tsd t1, 0(sp)\n");
        }
        return sb;
    }

    @Override
    public StringBuilder visitMul(MulContext ctx) {
        StringBuilder sb = new StringBuilder();
        sb.append(visit(ctx.unary(0)));
        for (int i = 2; i < ctx.children.size(); i += 2) {
            sb.append(visit(ctx.children.get(i)));

            String op = ctx.children.get(i - 1).getText().equals("*") ? "mul" : "div";
            sb.append("# " + op + "\n");
            sb.append("\tld t2, 0(sp)\n");
            sb.append("\tld t1, 8(sp)\n");
            sb.append("\t" + op + " t1, t1, t2\n");
            sb.append("\taddi sp, sp, 8\n");
            sb.append("\tsd t1, 0(sp)\n");
        }
        return sb;
    }

    @Override
    public StringBuilder visitUnary(UnaryContext ctx) {
        StringBuilder sb = new StringBuilder();
        sb.append(visit(ctx.primary()));
        TerminalNode sub = ctx.SUB();
        if (sub != null) {
            sb.append("\tld t1, 0(sp)\n");
            sb.append("\tneg t1, t1\n");
            sb.append("\tsd t1, 0(sp)\n");
        }
        return sb;
    }

    @Override
    public StringBuilder visitNumPrimary(NumPrimaryContext ctx) {
        StringBuilder sb = new StringBuilder();
        TerminalNode node = ctx.NUM();
        if (compare(Integer.toString(Integer.MAX_VALUE), node.getText()) == -1) {
            System.err.println("Error(" + node.getSymbol().getLine() + "," + node.getSymbol().getCharPositionInLine() + "): too large number.");
            System.exit(1);
        }
        sb.append("# number " + ctx.NUM().getText() + "\n");
        sb.append("\tli t1, " + ctx.NUM().getText() + "\n");
        sb.append("\taddi sp, sp, -8\n");
        sb.append("\tsd t1, 0(sp)\n");
        return sb;
    }
    
    @Override
    public StringBuilder visitParenthesizePrimary(ParenthesizePrimaryContext ctx) {
        return visit(ctx.expr());
    }

    private int compare(String s, String t) {
        if (s.length() != t.length())
            return s.length() < t.length() ? -1 : 1;
        else {
            for (int i = 0; i < s.length(); ++i)
                if (s.charAt(i) != t.charAt(i))
                    return s.charAt(i) < t.charAt(i) ? -1 : 1;
            return 0;
        }
    }
}

// TODO: string across multiple lines for convenience?