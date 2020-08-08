package minidecaf;

import minidecaf.parser.*;
import minidecaf.parser.MiniDecafParser.*;

import java.util.*;

import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.tree.*;

public class MiniDecafVisitor extends MiniDecafParserBaseVisitor<StringBuilder> {
    @Override
    public StringBuilder visitProgram(ProgramContext ctx) {
        StringBuilder sb = new StringBuilder();
        sb.append(".global main\n")
          .append("main:\n")
          .append("# prologue\n");

        // To avoid possible awkward situation,
        // we save all control registers that we'll use.
        sb.append("\taddi sp, sp, -8\n")
          .append("\tsd fp, 0(sp)\n");
        
        sb.append("\tmv fp, sp\n");
        
        for (var stmt: ctx.stmt()) {
            sb.append(visit(stmt));
            if (stmt instanceof ReturnStmtContext)
                break;
        }

        sb.append("# epilogue\n")
          .append("\tld a0, 0(sp)\n")
          .append("\taddi sp, sp, 8\n");
        
        // To avoid possible awkward situation,
        // we restore all control registers that we'll use.
        sb.append("\tld fp, 0(sp)\n")
          .append("\taddi sp, sp, 8\n");
        
        sb.append("\tret\n");
        return sb;
    }

    @Override
    public StringBuilder visitExprStmt(ExprStmtContext ctx) {
        // Although there's a possible useless value in the stack,
        // we'll remain it for convenience in the current implementation temporarily.
        return visit(ctx.expr());
    }

    @Override
    public StringBuilder visitReturnStmt(ReturnStmtContext ctx) {
        return visit(ctx.expr());
    }

    @Override
    public StringBuilder visitExpr(ExprContext ctx) {
        if (ctx.ASSIGN() == null) return visit(ctx.relational());
        else {
            // Check if the left hand side of the equation symbol
            // is a complete variable name.
            // TODO: in the future maybe it's allowed that
            // the left hand side is no need to be a variable name.
            String v = ctx.relational().getText();
            boolean isVar = true;
            if (isAlpha(v.charAt(0))) { 
                for (char c: v.toCharArray())
                    if (!Character.isDigit(c) && !isAlpha(c))
                        isVar = false;
            }
            else isVar = false;
            if (!isVar) reportError("only a single variable could be assigned", ctx.relational());

            StringBuilder sb = new StringBuilder(visit(ctx.expr()));
            symbolTable.put(v, offset);
            offset -= 8;
            return sb;
        }
    }

    @Override
    public StringBuilder visitRelational(RelationalContext ctx) {
        StringBuilder sb = new StringBuilder(visit(ctx.add(0)));
        AddContext add1 = ctx.add(1);
        if (add1 != null) {
            sb.append(visit(add1))
              .append("\tld t2, 0(sp)\n")
              .append("\tld t1, 8(sp)\n")
              .append("\taddi sp, sp, 8\n");
            if (ctx.EQ() != null) {
                sb.append("# eq\n")
                  .append("\tsub t1, t1, t2\n")
                  .append("\tseqz t1, t1\n")
                  .append("\tsd t1, 0(sp)\n");
            } else if (ctx.NE() != null) {
                sb.append("# ne\n")
                  .append("\tsub t1, t1, t2\n")
                  .append("\tsnez t1, t1\n")
                  .append("\tsd t1, 0(sp)\n");
            } else if (ctx.LT() != null) {
                sb.append("\tslt t1, t1, t2\n")
                  .append("\tsd t1, 0(sp)\n");
            } else if (ctx.LE() != null) {
                sb.append("\tsgt t1, t1, t2\n")
                  .append("\txori t1, t1, 1\n")
                  .append("\tsd t1, 0(sp)\n");
            } else if (ctx.GT() != null) {
                sb.append("\tsgt t1, t1, t2\n")
                  .append("\tsd t1, 0(sp)\n");
            } else if (ctx.GE() != null) {
                sb.append("\tslt t1, t1, t2\n")
                  .append("\txori t1, t1, 1\n")
                  .append("\tsd t1, 0(sp)\n");
            }
        }
        return sb;
    }

    @Override
    public StringBuilder visitAdd(AddContext ctx) {
        StringBuilder sb = new StringBuilder();
        sb.append(visit(ctx.mul(0)));

        // System.out.printf("children of add:");
        // for (int i = 0; i < ctx.children.size(); ++i)
        //     System.out.printf(" " + ctx.children.get(i).getText());
        // System.out.println();

        for (int i = 2; i < ctx.children.size(); i += 2) {
            sb.append(visit(ctx.children.get(i)));

            String op = ctx.children.get(i - 1).getText().equals("+") ? "add" : "sub";
            sb.append("# " + op + "\n")
              .append("\tld t2, 0(sp)\n")
              .append("\tld t1, 8(sp)\n")
              .append("\t" + op + " t1, t1, t2\n")
              .append("\taddi sp, sp, 8\n")
              .append("\tsd t1, 0(sp)\n");
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
            sb.append("# " + op + "\n")
              .append("\tld t2, 0(sp)\n")
              .append("\tld t1, 8(sp)\n")
              .append("\t" + op + " t1, t1, t2\n")
              .append("\taddi sp, sp, 8\n")
              .append("\tsd t1, 0(sp)\n");
        }
        return sb;
    }

    @Override
    public StringBuilder visitUnary(UnaryContext ctx) {
        StringBuilder sb = new StringBuilder();
        sb.append(visit(ctx.primary()));
        TerminalNode sub = ctx.SUB();
        if (sub != null) {
            sb.append("\tld t1, 0(sp)\n")
              .append("\tneg t1, t1\n")
              .append("\tsd t1, 0(sp)\n");
        }
        return sb;
    }

    @Override
    public StringBuilder visitNumPrimary(NumPrimaryContext ctx) {
        StringBuilder sb = new StringBuilder();
        TerminalNode node = ctx.NUM();
        if (compare(Integer.toString(Integer.MAX_VALUE), node.getText()) == -1)
            reportError("too large number", ctx);
        sb.append("# number " + ctx.NUM().getText() + "\n")
          .append("\tli t1, " + ctx.NUM().getText() + "\n")
          .append("\taddi sp, sp, -8\n")
          .append("\tsd t1, 0(sp)\n");
        return sb;
    }

    @Override
    public StringBuilder visitIdentPrimary(IdentPrimaryContext ctx) {
        StringBuilder sb = new StringBuilder();
        sb.append("# read variable\n")
          .append("\tld t1, " + symbolTable.get(ctx.IDENT().getText()) + "(fp)\n")
          .append("\taddi sp, sp, -8\n")
          .append("\tsd t1, 0(sp)\n");
        return sb;
    }
    
    @Override
    public StringBuilder visitParenthesizePrimary(ParenthesizePrimaryContext ctx) {
        return visit(ctx.expr());
    }

    // Symbol table
    // So far, we only have global variables.
    // Therefore, here we only record an offset to the global fp.
    Map<String, Integer> symbolTable = new HashMap<>();
    Integer offset = -8;

    // Utils
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

    private boolean isAlpha(char c) {
        return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
    }

    private void reportError(String s, ParserRuleContext ctx) {
        System.err.printf("Error(%d, %d): %s.", ctx.getStart().getLine(), ctx.getStart().getCharPositionInLine(), s);
        System.exit(1);
    }
}

// TODO: only one StringBuilder?