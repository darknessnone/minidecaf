package minidecaf;

import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.tree.*;

import java.io.FileWriter;

public class Main {
    public static void main(String[] args) throws Exception {
        if (args.length != 2
            || args[0].equals("-h")
            || args[0].equals("--help")) {
            System.out.printf("Usage: minidecaf <input file> <output file>\n");
            return;
        }

        CharStream input = CharStreams.fromFileName(args[0]);
        MiniDecafLexer lexer = new MiniDecafLexer(input);
        CommonTokenStream tokens = new CommonTokenStream(lexer);
        MiniDecafParser parser = new MiniDecafParser(tokens);
        ParseTree tree = parser.program();
        StringBuilder asm = new StringBuilder();
        MainVisitor visitor = new MainVisitor(asm);
        visitor.visit(tree);
        FileWriter writer = new FileWriter(args[1]);
        writer.write(asm.toString());
        writer.close();
    }
}
