package minidecaf;

import minidecaf.parser.*;
import minidecaf.parser.MiniDecafParser.ProgramContext;

import org.antlr.v4.runtime.tree.*;

public class MiniDecafVisitor extends MiniDecafParserBaseVisitor<StringBuilder> {
    @Override
    public StringBuilder visitProgram(ProgramContext ctx) {
        StringBuilder sb = new StringBuilder();
        sb.append(".global main\n");
        sb.append("main:\n");

        // TODO: what if some number is too large?
        Integer result = Integer.valueOf(ctx.NUM(0).getText());

        for (int i = 2; i < ctx.children.size(); i += 2) {
            Integer x = Integer.valueOf(ctx.children.get(i).getText());
            if (ctx.children.get(i - 1).getText().equals("+")) result += x;
            else result -= x;
        }

        sb.append(String.format("\tli a0, %d\n", result));
        sb.append("\tret\n");
        return sb;
    }

    public StringBuilder push(Integer x) {
        StringBuilder sb = new StringBuilder();
        sb.append("# push " + x + "\n");
        sb.append("\t\tli t1, " + x + "\n");
        sb.append("\taddi sp, sp, -8");
        sb.append("\tsd t1, 0(sp)");
        return sb;
    }
}