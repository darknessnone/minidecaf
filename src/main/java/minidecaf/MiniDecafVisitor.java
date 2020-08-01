package minidecaf;

import minidecaf.parser.*;
import minidecaf.parser.MiniDecafParser.ProgramContext;

public class MiniDecafVisitor extends MiniDecafParserBaseVisitor<StringBuilder> {
    @Override
    public StringBuilder visitProgram(ProgramContext ctx) {
        // TODO: what if the number is too large?
        Integer num = Integer.valueOf(ctx.NUM().getText());
        
        StringBuilder sb = new StringBuilder();
        sb.append(".global main\n");
        sb.append("main:\n");
        sb.append(String.format("\tli a0, %d\n", num));
        sb.append("\tret\n");
        return sb;
    }
}