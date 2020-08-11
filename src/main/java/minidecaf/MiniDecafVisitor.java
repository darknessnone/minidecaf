package minidecaf;

import minidecaf.parser.*;
import minidecaf.parser.MiniDecafParser.*;

import java.util.*;

import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.tree.*;

public class MiniDecafVisitor extends MiniDecafParserBaseVisitor<Void> {
    private StringBuilder sb;
    MiniDecafVisitor(StringBuilder sb) {
        this.sb = sb;
    }

    @Override
    public Void visitProgram(ProgramContext ctx) {
        sb.append(".global main\n")
          .append("main:\n");
        
        sb.append("# prologue\n")
          .append("\tmv fp, sp\n");

        // symbol
        symbolTable.add(new HashMap<>());
        
        // visit statements
        for (var stmt: ctx.stmt()) {
            visit(stmt);
            if (stmt instanceof ReturnStmtContext)
                break;
        }

        sb.append("# epilogue\n")
          .append("\tld a0, 0(sp)\n");
        
        sb.append("\tret\n");
        return null;
    }

    @Override
    public Void visitExprStmt(ExprStmtContext ctx) {
        // Although there's a possible useless value in the stack,
        // we'll remain it for convenience in the current implementation temporarily.
        visit(ctx.expr());
        return null;
    }

    @Override
    public Void visitReturnStmt(ReturnStmtContext ctx) {
        visit(ctx.expr());
        return null;
    }

    @Override
    public Void visitBlockStmt(BlockStmtContext ctx) {
        symbolTable.add(new HashMap<>());
        for (var stmt: ctx.stmt())
            visit(stmt);
        symbolTable.pop();
        return null;
    }

    @Override
    public Void visitIfStmt(IfStmtContext ctx) {
        int elseLabel = labelNo++;
        int afterLabel = labelNo++;
        sb.append("# # if\n");
        visit(ctx.expr());
        sb.append("\tld t1, 0(sp)\n")
          .append("\tbeqz t1, _L" + elseLabel + "\n");
        visit(ctx.stmt().get(0));
        sb.append("\tj _L" + afterLabel + "\n")
          .append("_L" + elseLabel + ":\n");
        if (ctx.ELSE() != null)
            visit(ctx.stmt().get(1));
        sb.append("_L" + afterLabel + ":\n");
        return null;
    }

    @Override
    public Void visitWhileStmt(WhileStmtContext ctx) {
        int beforeLabel = labelNo++;
        int afterLabel = labelNo++;
        sb.append("# while\n");
        sb.append("_L" + beforeLabel + ":\n");
        visit(ctx.expr());
        sb.append("\tld t1, 0(sp)\n")
          .append("\tbeqz t1, _L" + afterLabel + "\n");
        visit(ctx.stmt());
        sb.append("\tj _L" + beforeLabel + "\n")
          .append("_L" + afterLabel + ":\n");
        return null;
    }

    @Override
    public Void visitForStmt(ForStmtContext ctx) {
        int beforeLabel = labelNo++;
        int afterLabel = labelNo++;
        sb.append("# for\n");
        
        ExprContext initExpr = null;
        ExprContext condExpr = null;
        ExprContext afterExpr = null;
        for (int i = 0; i < ctx.children.size(); ++i)
            if (ctx.children.get(i) instanceof ExprContext) {
                ExprContext expr = (ExprContext)(ctx.children.get(i));
                if (ctx.children.get(i - 1).getText().equals("("))
                    initExpr = expr;
                else
                    if (ctx.children.get(i + 1).getText().equals(";"))
                        condExpr = expr;
                    else
                        afterExpr = expr;
            }
        
        if (initExpr != null) visit(initExpr);
        sb.append("_L" + beforeLabel + ":\n");
        if (condExpr != null) {
            visit(condExpr);
            sb.append("\tld t1, 0(sp)\n")
              .append("\tbeqz t1, _L" + afterLabel + "\n");
        }
        visit(ctx.stmt());
        if (afterExpr != null) visit(afterExpr);
        sb.append("\tj _L" + beforeLabel + "\n")
          .append("_L" + afterLabel + ":\n");
        return null;
    }

    @Override
    public Void visitExpr(ExprContext ctx) {
        if (ctx.ASSIGN() == null) visit(ctx.relational());
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

            visit(ctx.expr());

            int offset = lookupSymbol(v);
            if (offset != 0) {
                sb.append("\tld t1, 0(sp)\n")
                  .append("\tsd t1, " + offset + "(fp)\n");
            } else {
                // create a new symbol
                symbolTable.lastElement().put(v, currentOffset);
                currentOffset -= 8;
            }
        }
        return null;
    }

    @Override
    public Void visitRelational(RelationalContext ctx) {
        visit(ctx.add(0));
        AddContext add1 = ctx.add(1);
        if (add1 != null) {
            visit(add1);
            sb.append("\tld t2, 0(sp)\n")
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
        return null;
    }

    @Override
    public Void visitAdd(AddContext ctx) {
        visit(ctx.mul(0));
        for (int i = 2; i < ctx.children.size(); i += 2) {
            visit(ctx.children.get(i));

            String op = ctx.children.get(i - 1).getText().equals("+") ? "add" : "sub";
            sb.append("# " + op + "\n")
              .append("\tld t2, 0(sp)\n")
              .append("\tld t1, 8(sp)\n")
              .append("\t" + op + " t1, t1, t2\n")
              .append("\taddi sp, sp, 8\n")
              .append("\tsd t1, 0(sp)\n");
        }
        return null;
    }

    @Override
    public Void visitMul(MulContext ctx) {
        visit(ctx.unary(0));
        for (int i = 2; i < ctx.children.size(); i += 2) {
            visit(ctx.children.get(i));

            String op = ctx.children.get(i - 1).getText().equals("*") ? "mul" : "div";
            sb.append("# " + op + "\n")
              .append("\tld t2, 0(sp)\n")
              .append("\tld t1, 8(sp)\n")
              .append("\t" + op + " t1, t1, t2\n")
              .append("\taddi sp, sp, 8\n")
              .append("\tsd t1, 0(sp)\n");
        }
        return null;
    }

    @Override
    public Void visitUnary(UnaryContext ctx) {
        visit(ctx.primary());
        TerminalNode sub = ctx.SUB();
        if (sub != null) {
            sb.append("\tld t1, 0(sp)\n")
              .append("\tneg t1, t1\n")
              .append("\tsd t1, 0(sp)\n");
        }
        return null;
    }

    @Override
    public Void visitNumPrimary(NumPrimaryContext ctx) {
        TerminalNode node = ctx.NUM();
        if (compare(Integer.toString(Integer.MAX_VALUE), node.getText()) == -1)
            reportError("too large number", ctx);
        sb.append("# number " + ctx.NUM().getText() + "\n")
          .append("\tli t1, " + ctx.NUM().getText() + "\n")
          .append("\taddi sp, sp, -8\n")
          .append("\tsd t1, 0(sp)\n");
        return null;
    }

    @Override
    public Void visitIdentPrimary(IdentPrimaryContext ctx) {
        String v = ctx.IDENT().getText();
        int offset = lookupSymbol(v);
        if (offset == 0)
            reportError("use variable that is not defined", ctx);
        sb.append("# read variable\n")
          .append("\tld t1, " + offset + "(fp)\n")
          .append("\taddi sp, sp, -8\n")
          .append("\tsd t1, 0(sp)\n");
        return null;
    }
    
    @Override
    public Void visitParenthesizePrimary(ParenthesizePrimaryContext ctx) {
        visit(ctx.expr());
        return null;
    }

    // Symbol table
    // So far, we only have global variables.
    // Therefore, here we only record an offset to the global fp.
    Stack<Map<String, Integer>> symbolTable = new Stack<>();
    Integer currentOffset = -8;

    // look the symbol up for the offset (0 means non-existence)
    private int lookupSymbol(String v) {
        int offset = 0;
        for (int i = symbolTable.size() - 1; i >= 0; --i) {
            var map = symbolTable.elementAt(i);
            if (map.containsKey(v)) {
                offset = map.get(v);
                break;
            }
        }
        return offset;
    }

    Integer labelNo = 0;

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

// TODO: how large could the intermediate number in the assembly be?