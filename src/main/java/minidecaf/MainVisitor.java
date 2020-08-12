package minidecaf;

import minidecaf.MiniDecafParser.*;

import java.util.*;

import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.tree.*;

public class MainVisitor extends MiniDecafBaseVisitor<Void> {
    private StringBuilder sb;
    MainVisitor(StringBuilder sb) {
        this.sb = sb;
    }

    @Override
    public Void visitProgram(ProgramContext ctx) {
        for (var func: ctx.func())
            visit(func);
        return null;
    }

    @Override
    public Void visitFunc(FuncContext ctx) {
        currentFunc = ctx.IDENT().get(0).getText();

        sb.append(".global " + currentFunc + "\n")
          .append(currentFunc + ":\n");
        funcTable.add(currentFunc);

        // open a new scope
        symbolTable.add(new HashMap<>());
        currentOffset.add(2 * 8);
        
        sb.append("# prologue\n");
        push("ra");
        push("fp");
        sb.append("\tmv fp, sp\n");

        for (int i = 1; i < ctx.IDENT().size(); ++i) {
            String paraName = ctx.IDENT().get(i).getText();
            if (symbolTable.peek().get(paraName) != null)
                reportError("two parameters have the same names", ctx);
            
            if (i < 9) {
                push("a" + (i - 1));
                symbolTable.peek().put(paraName, currentOffset.peek());
            } else {
                symbolTable.peek().put(paraName, (i - 9 + 2) * 8);
            }
        }
        
        // emit body
        for (var stmt: ctx.stmt()) visit(stmt);

        // close the scope
        symbolTable.pop();
        currentOffset.pop();

        sb.append("# epilogue\n")
          .append("_exit_" + currentFunc + ":\n")
          .append("\tld a0, 0(sp)\n")
          .append("\tmv sp, fp\n");
        pop("fp");
        pop("ra");
        sb.append("\tret\n\n");
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
        sb.append("\tj _exit_" + currentFunc + "\n");
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

    int ifNo = 0;
    @Override
    public Void visitIfStmt(IfStmtContext ctx) {
        sb.append("# # if\n");
        visit(ctx.expr());
        sb.append("\tld t1, 0(sp)\n")
          .append("\tbeqz t1, _else" + ifNo + "\n");
        visit(ctx.stmt().get(0));
        sb.append("\tj _afterIf" + ifNo + "\n")
          .append("_else" + ifNo + ":\n");
        if (ctx.stmt().size() > 1)
            visit(ctx.stmt().get(1));
        sb.append("_afterIf" + ifNo + ":\n");
        ++ifNo;
        return null;
    }

    int loopNo = 0;
    @Override
    public Void visitWhileStmt(WhileStmtContext ctx) {
        sb.append("# while\n");
        sb.append("_beforeLoop" + loopNo + ":\n");
        visit(ctx.expr());
        sb.append("\tld t1, 0(sp)\n")
          .append("\tbeqz t1, _afterLoop" + loopNo + "\n");
        visit(ctx.stmt());
        sb.append("\tj _beforeLoop" + loopNo + "\n")
          .append("_afterLoop" + loopNo + ":\n");
        ++loopNo;
        return null;
    }

    int forNo = 0;
    @Override
    public Void visitForStmt(ForStmtContext ctx) {
        sb.append("# for\n");
        
        ExprContext initExpr = null;
        ExprContext condExpr = null;
        ExprContext afterExpr = null;
        for (int i = 0; i < ctx.children.size(); ++i)
            if (ctx.children.get(i) instanceof ExprContext) {
                ExprContext expr = (ExprContext)(ctx.children.get(i));
                if (ctx.children.get(i - 1).getText().equals("("))
                    initExpr = expr;
                else if (ctx.children.get(i + 1).getText().equals(";"))
                    condExpr = expr;
                else
                    afterExpr = expr;
            }
        
        if (initExpr != null) visit(initExpr);
        sb.append("_beforeLoop" + loopNo + ":\n");
        if (condExpr != null) {
            visit(condExpr);
            sb.append("\tld t1, 0(sp)\n")
              .append("\tbeqz t1, _afterLoop" + loopNo + "\n");
        }
        visit(ctx.stmt());
        if (afterExpr != null) visit(afterExpr);
        sb.append("\tj _beforeLoop" + loopNo + "\n")
          .append("_afterLoop" + loopNo + ":\n");
        ++forNo;
        return null;
    }

    @Override
    public Void visitExpr(ExprContext ctx) {
        if (ctx.children.size() == 1) visit(ctx.relational());
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
            currentOffset.push(currentOffset.peek() - 8);

            var optionOffset = lookupSymbol(v);
            if (optionOffset.isPresent()) {
                sb.append("\tld t1, 0(sp)\n")
                  .append("\tsd t1, " + optionOffset.get() + "(fp)\n");
            } else {
                // create a new symbol
                symbolTable.peek().put(v, currentOffset.peek());
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
        if (ctx.children.get(0).getText().equals('-')) {
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
        Optional<Integer> optionOffset = lookupSymbol(v);
        if (optionOffset.isEmpty())
            reportError("use variable that is not defined", ctx);
        sb.append("# read variable\n")
          .append("\tld t1, " + optionOffset.get() + "(fp)\n")
          .append("\taddi sp, sp, -8\n")
          .append("\tsd t1, 0(sp)\n");
        return null;
    }
    
    @Override
    public Void visitParenthesizePrimary(ParenthesizePrimaryContext ctx) {
        visit(ctx.expr());
        return null;
    }

    @Override
    public Void visitCallPrimary(CallPrimaryContext ctx) {
        String name = ctx.IDENT().getText();
        if (!funcTable.contains(name))
            reportError("try calling a undeclared function", ctx);
        sb.append("# prepare arguments\n");
        for (int i = ctx.expr().size() - 1; i >= 0; --i) {
            var expr = ctx.expr().get(i);
            visit(expr);
            if (i < 8) pop("a" + i);
        }

        sb.append("\tcall " + name + "\n");

        for (int i = ctx.expr().size() - 1; i >= 8; --i) pop();
        push("a0");
        return null;
    }

    Stack<Map<String, Integer>> symbolTable = new Stack<>();
    Stack<Integer> currentOffset = new Stack<>();

    // look the symbol up for the offset (0 means non-existence)
    private Optional<Integer> lookupSymbol(String v) {
        for (int i = symbolTable.size() - 1; i >= 0; --i) {
            var map = symbolTable.elementAt(i);
            if (map.containsKey(v))
                return Optional.of(map.get(v));
        }
        return Optional.empty();
    }

    Set<String> funcTable = new HashSet<>();
    String currentFunc;

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

    private void push(String reg) {
        sb.append("# push " + reg + "\n")
          .append("\taddi sp, sp, -8\n")
          .append("\tsd " + reg + ", 0(sp)\n");
        currentOffset.push(currentOffset.pop() - 8);
    }

    private void pop(String reg) {
        sb.append("# pop " + reg + "\n")
          .append("\tld " + reg + ", 0(sp)\n")
          .append("\taddi sp, sp, 8\n");
    }
    private void pop() {
        currentOffset.push(currentOffset.pop() + 8);
    }
}

// TODO: how large could the intermediate number in the assembly be?