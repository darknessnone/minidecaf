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

        sb.append(visit(ctx.mul(0)));
        for (int i = 2; i < ctx.children.size(); i += 2) {
            sb.append(visit(ctx.children.get(i)));

            sb.append("\tld t2, 0(sp)\n");
            sb.append("\tld t1, 8(sp)\n");
            sb.append("\t" +
                    (ctx.children.get(i - 1).getText().equals("+") ? "add" : "sub")
                + " t1, t1, t2\n");
            sb.append("\taddi sp, sp, 8\n");
            sb.append("\tsd t1, 0(sp)\n");
        }

        sb.append("\tld a0, 0(sp)\n");
        sb.append("\taddi sp, sp, 8\n");
        sb.append("\tret\n");
        return sb;
    }

    @Override
    public StringBuilder visitMul(MulContext ctx) {
        StringBuilder sb = new StringBuilder();
        
        sb.append(push(Integer.valueOf(ctx.NUM(0).getText())));
        for (int i = 2; i < ctx.children.size(); i += 2) {
            sb.append(push(Integer.valueOf(ctx.children.get(i).getText())));

            sb.append("\tld t2, 0(sp)\n");
            sb.append("\tld t1, 8(sp)\n");
            sb.append("\t" +
                    (ctx.children.get(i - 1).getText().equals("*") ? "mul" : "div")
                + " t1, t1, t2\n");
            sb.append("\taddi sp, sp, 8\n");
            sb.append("\tsd t1, 0(sp)\n");
        }

        return sb;
    }

    private StringBuilder push(Integer x) {
        StringBuilder sb = new StringBuilder();
        sb.append("# push " + x + "\n");
        sb.append("\tli t1, " + x + "\n");
        sb.append("\taddi sp, sp, -8\n");
        sb.append("\tsd t1, 0(sp)\n");
        return sb;
    }
}