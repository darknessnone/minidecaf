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
        for (var child: ctx.children)
            visit(child);
        
        // 将未定义的全局变量放到 bss 段真的合理嘛？
        // 在 wiki 上看到 bss 段的初始化是平台相关的
        // 也许我们不该在此处作定义
        for (String global: declaredGlobalTable)
            if (!initializedGlobalTable.contains(global))
                sb.insert(0, "\t.comm " + global + ", 4, 4\n");

        return null;
    }

    @Override
    public Void visitDeclaredFunc(DeclaredFuncContext ctx) {
        String name = ctx.IDENT(0).getText();
        int paraSize = 0;
        for (int i = 1; i < ctx.children.size(); ++i)
            if (ctx.children.get(i).getText().equals("int"))
                ++paraSize;
        if (declaredFuncTable.get(name) != null && declaredFuncTable.get(name) != paraSize)
            reportError("declare a function with two different signatures", ctx);
        declaredFuncTable.put(name, paraSize);
        return null;
    }

    int localCount;
    @Override
    public Void visitCompleteFunc(CompleteFuncContext ctx) {
        // C++ 可以支持同名，但参数不同的函数；但 C 不能支持。

        // TODO: 可以尝试完全兼容 gcc 的 calling convention

        currentFunc = ctx.IDENT().get(0).getText();

        sb.append(".global " + currentFunc + "\n")
          .append(currentFunc + ":\n");
        if (definedFuncTable.get(currentFunc) != null)
            reportError("define two functions as a same name", ctx);
        if (declaredFuncTable.get(currentFunc) != null && declaredFuncTable.get(currentFunc) != ctx.IDENT().size() - 1)
            reportError("the number of parameters of the defined function is not the same as declared", ctx);
        
        declaredFuncTable.put(currentFunc, ctx.IDENT().size() - 1);
        definedFuncTable.put(currentFunc, ctx.IDENT().size() - 1);

        // open a new scope
        symbolTable.add(new HashMap<>());
        
        sb.append("# prologue\n");
        push("ra");
        push("fp");
        sb.append("\tmv fp, sp\n");
        int backtracePos = sb.length();
        localCount = 0;

        for (int i = 1; i < ctx.IDENT().size(); ++i) {
            String paraName = ctx.IDENT().get(i).getText();
            if (symbolTable.peek().get(paraName) != null)
                reportError("two parameters have the same name", ctx);
            
            if (i < 9) {
                ++localCount;
                sb.append("\tsd a" + (i - 1) + ", " + (-8 * i) + "(fp)\n");
                symbolTable.peek().put(paraName, i);
            } else
                symbolTable.peek().put(paraName, -(i - 9 + 2));
        }
        
        // emit body
        for (var blockItem: ctx.blockItem()) visit(blockItem);

        // TODO: 还需要做 return 的检查

        // backtrace the number of local variables
        sb.insert(backtracePos, "\taddi sp, sp, " + (-8 * localCount) + "\n");
        localCount = 0;

        // close the scope
        symbolTable.pop();

        if (currentFunc.equals("main")) {
            sb.append("\tli t1, 0\n")
              .append("\taddi sp, sp, -8\n")
              .append("\tsd t1, 0(sp)\n");
        }

        sb.append("# epilogue\n")
          .append(".exit." + currentFunc + ":\n")
          .append("\tld a0, 0(sp)\n")
          .append("\tmv sp, fp\n");
        pop("fp");
        pop("ra");
        sb.append("\tret\n\n");

        currentFunc = null;
        return null;
    }

    @Override
    public Void visitGlobal(GlobalContext ctx) {
        // C++ 可以支持用表达式初始化全局变量，但 C 只支持用常量初始化

        String name = ctx.IDENT().getText();
        if (declaredFuncTable.get(name) != null)
            reportError("a global variable and a function have the same name", ctx);

        declaredGlobalTable.add(name);

        var num = ctx.NUM();
        if (num != null) {
            if (initializedGlobalTable.contains(name))
                reportError("try initializing a global variable twice", ctx);
            initializedGlobalTable.add(name);

            // TODO: 64-bit intermediate for initialization of global variables
            sb.append(name + ":\n")
              .append("\t.word " + num.getText() + "\n");
        }
        return null;
    }

    @Override
    public Void visitBlockItem(BlockItemContext ctx) {
        visit(ctx.children.get(0));
        return null;
    }

    @Override
    public Void visitLocal(LocalContext ctx) {
        // use of uninitialized local variables is an undefined behavior

        String name = ctx.IDENT().getText();
        var expr = ctx.expr();
        if (expr != null) visit(expr);
        else {
            sb.append("\tli t1, 0\n")
              .append("\tsd t1, 0(sp)\n");
        }

        if (symbolTable.peek().get(name) != null)
            reportError("try declaring a declared variable", ctx);
        symbolTable.peek().put(name, ++localCount);
        sb.append("\tld t1, 0(sp)\n")
          .append("\tsd t1, " + (- 8 * localCount) + "(fp)\n");
        return null;
    }

    @Override
    public Void visitExprStmt(ExprStmtContext ctx) {
        visit(ctx.expr());
        return null;
    }

    @Override
    public Void visitReturnStmt(ReturnStmtContext ctx) {
        visit(ctx.expr());
        sb.append("\tj .exit." + currentFunc + "\n");
        return null;
    }

    @Override
    public Void visitBlockStmt(BlockStmtContext ctx) {
        symbolTable.add(new HashMap<>());
        for (var blockItem: ctx.blockItem())
            visit(blockItem);
        symbolTable.pop();
        return null;
    }

    int condNo = 0;
    @Override
    public Void visitIfStmt(IfStmtContext ctx) {
        int currentCondNo = condNo++;
        sb.append("# # if\n");
        visit(ctx.expr());
        sb.append("\tld t1, 0(sp)\n")
          .append("\tbeqz t1, .else" + currentCondNo + "\n");
        visit(ctx.stmt().get(0));
        sb.append("\tj .afterCond" + currentCondNo + "\n")
          .append(".else" + currentCondNo + ":\n");
        if (ctx.stmt().size() > 1)
            visit(ctx.stmt().get(1));
        sb.append(".afterCond" + currentCondNo + ":\n");
        return null;
    }

    @Override
    public Void visitWhileStmt(WhileStmtContext ctx) {
        int currentLoopNo = loopNo++;
        inLoop = true;

        sb.append("# while\n");
        sb.append(".beforeLoop" + currentLoopNo + ":\n");
        sb.append(".continueLoop" + currentLoopNo + ":\n");
        visit(ctx.expr());
        sb.append("\tld t1, 0(sp)\n")
          .append("\tbeqz t1, .afterLoop" + currentLoopNo + "\n");
        loopNos.push(currentLoopNo);
        visit(ctx.stmt());
        loopNos.pop();
        sb.append("\tj .beforeLoop" + currentLoopNo + "\n")
          .append(".afterLoop" + currentLoopNo + ":\n");
        
        inLoop = false;
        return null;
    }

    @Override
    public Void visitForStmt(ForStmtContext ctx) {
        int currentLoopNo = loopNo++;
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
        
        symbolTable.add(new HashMap<>());
        
        // the following two situations will not happen
        // simultaneously because of the grammar
        if (initExpr != null) visit(initExpr);
        if (ctx.local() != null) visit(ctx.local());

        inLoop = true;

        sb.append(".beforeLoop" + currentLoopNo + ":\n");
        if (condExpr != null) {
            visit(condExpr);
            sb.append("\tld t1, 0(sp)\n")
              .append("\tbeqz t1, .afterLoop" + currentLoopNo + "\n");
        }
        loopNos.push(currentLoopNo);
        symbolTable.add(new HashMap<>());
        visit(ctx.stmt());
        symbolTable.pop();
        loopNos.pop();

        sb.append(".continueLoop" + currentLoopNo + ":\n");
        if (afterExpr != null) visit(afterExpr);
        symbolTable.pop();
        sb.append("\tj .beforeLoop" + currentLoopNo + "\n")
          .append(".afterLoop" + currentLoopNo + ":\n");
        
        inLoop = false;
        return null;
    }

    @Override
    public Void visitDoStmt(DoStmtContext ctx) {
        int currentLoopNo = loopNo++;
        sb.append("# do-while\n");

        inLoop = true;

        sb.append(".beforeLoop" + currentLoopNo + ":\n");
        loopNos.push(currentLoopNo);
        visit(ctx.stmt());
        loopNos.pop();
        sb.append(".continueLoop" + currentLoopNo + ":\n");
        visit(ctx.expr());
        sb.append("\tld t1, 0(sp)\n")
          .append("\tbnez t1, .beforeLoop" + currentLoopNo + "\n")
          .append(".afterLoop" + currentLoopNo + ":\n");
        
        inLoop = false;
        return null;
    }

    @Override
    public Void visitBreakStmt(BreakStmtContext ctx) {
        if (!inLoop)
            reportError("break statement not within loop or switch", ctx);
        sb.append("\tj .afterLoop" + loopNos.peek() + "\n");
        return null;
    }

    @Override
    public Void visitContinueStmt(ContinueStmtContext ctx) {
        if (!inLoop)
            reportError("continue statement not within loop or switch", ctx);
        sb.append("\tj .continueLoop" + loopNos.peek() + "\n");
        return null;
    }

    @Override
    public Void visitEmptyStmt(EmptyStmtContext ctx) {
        return null;
    }

    @Override
    public Void visitExpr(ExprContext ctx) {
        if (ctx.children.size() > 1) {
            visit(ctx.expr());  
            
            String name = ctx.IDENT().getText();
            sb.append("# assign\n");
            var optionOffset = lookupSymbol(name);
            if (optionOffset.isPresent()) {
                sb.append("\tld t1, 0(sp)\n")
                  .append("\tsd t1, " + (- 8 * optionOffset.get()) + "(fp)\n");
            } else if (declaredGlobalTable.contains(name)) {
                sb.append("\tld t1, 0(sp)\n")
                  .append("\tsd t1, %lo(" + name + ")(t1)\n");
            } else {
                reportError("assign to a undeclared variable", ctx);
            }
        } else {
            visit(ctx.ternary());
        }

        return null;
    }

    @Override
    public Void visitTernary(TernaryContext ctx) {
        if (ctx.children.size() > 1) {
            // 这里可以加一些测三目运算符本身的结合性，
            // 以及测三目运算符和赋值符号的结合性和优先级的例子。

            int currentCondNo = condNo++;
            sb.append("# ternary conditional\n");
            visit(ctx.or());

            sb.append("\tld t1, 0(sp)\n")
              .append("\tbeqz t1, .else" + currentCondNo + "\n");
            visit(ctx.expr());
            sb.append("\tj .afterCond" + currentCondNo + "\n")
              .append(".else" + currentCondNo + ":\n");
            visit(ctx.ternary());
            sb.append(".afterCond" + currentCondNo + ":\n");
        } else {
            visit(ctx.or());
        }
        return null;
    }

    @Override
    public Void visitOr(OrContext ctx) {
        if (ctx.children.size() > 1) {
            visit(ctx.or(0));
            visit(ctx.or(1));

            // TODO: 短路
            sb.append("\tld t2, 0(sp)\n")
              .append("\tld t1, 8(sp)\n")
              .append("\taddi sp, sp, 8\n")
              .append("\tsnez t1, t1\n")
              .append("\tsnez t2, t2\n")
              .append("\tor t1, t1, t2\n")
              .append("\tsd t1, 0(sp)\n");
        } else {
            visit(ctx.and());
        }
        return null;
    }

    @Override
    public Void visitAnd(AndContext ctx) {
        if (ctx.children.size() > 1) {
            visit(ctx.and(0));
            visit(ctx.and(1));

            // TODO: 短路
            sb.append("\tld t2, 0(sp)\n")
              .append("\tld t1, 8(sp)\n")
              .append("\taddi sp, sp, 8\n")
              .append("\tsnez t1, t1\n")
              .append("\tsnez t2, t2\n")
              .append("\tand t1, t1, t2\n")
              .append("\tsd t1, 0(sp)\n");
        } else {
            visit(ctx.eq());
        }
        return null;
    }

    @Override
    public Void visitEq(EqContext ctx) {
        if (ctx.children.size() > 1) {
            visit(ctx.eq(0));
            visit(ctx.eq(1));
            
            sb.append("\tld t2, 0(sp)\n")
              .append("\tld t1, 8(sp)\n")
              .append("\taddi sp, sp, 8\n");
            String op = ctx.children.get(1).getText();
            if (op.equals("==")) {
                sb.append("# eq\n")
                  .append("\tsub t1, t1, t2\n")
                  .append("\tseqz t1, t1\n")
                  .append("\tsd t1, 0(sp)\n");
            } else {
                assert op.equals("!=");
                sb.append("# ne\n")
                  .append("\tsub t1, t1, t2\n")
                  .append("\tsnez t1, t1\n")
                  .append("\tsd t1, 0(sp)\n");
            }
        } else {
            visit(ctx.rel());
        }
        return null;
    }

    @Override
    public Void visitRel(RelContext ctx) {
        if (ctx.children.size() > 1) {
            visit(ctx.rel(0));
            visit(ctx.rel(1));

            sb.append("\tld t2, 0(sp)\n")
              .append("\tld t1, 8(sp)\n")
              .append("\taddi sp, sp, 8\n");

            String op = ctx.children.get(1).getText();
            if (op.equals("<")) {
                sb.append("# <\n")
                  .append("\tslt t1, t1, t2\n")
                  .append("\tsd t1, 0(sp)\n");
            } else if (op.equals("<=")) {
                sb.append("# <=\n")
                  .append("\tsgt t1, t1, t2\n")
                  .append("\txori t1, t1, 1\n")
                  .append("\tsd t1, 0(sp)\n");
            } else if (op.equals(">")) {
                sb.append("# >\n")
                  .append("\tsgt t1, t1, t2\n")
                  .append("\tsd t1, 0(sp)\n");
            } else {
                assert op.equals(">=");
                sb.append("# >=\n")
                  .append("\tslt t1, t1, t2\n")
                  .append("\txori t1, t1, 1\n")
                  .append("\tsd t1, 0(sp)\n");
            }
        } else {
            visit(ctx.add());
        }
        return null;
    }

    @Override
    public Void visitAdd(AddContext ctx) {
        if (ctx.children.size() > 1) {
            visit(ctx.add(0));
            visit(ctx.add(1));

            String op = ctx.children.get(1).getText().equals("+") ? "add" : "sub";
            sb.append("# " + op + "\n")
            .append("\tld t2, 0(sp)\n")
            .append("\tld t1, 8(sp)\n")
            .append("\t" + op + " t1, t1, t2\n")
            .append("\taddi sp, sp, 8\n")
            .append("\tsd t1, 0(sp)\n");
        } else {
            visit(ctx.term());
        }
        return null;
    }

    @Override
    public Void visitTerm(TermContext ctx) {
        if (ctx.children.size() > 1) {
            visit(ctx.term(0));
            visit(ctx.term(1));

            String op = ctx.children.get(1).getText();
            op = op.equals("*") ? "mul" : op.equals("/") ? "div" : "rem";
            sb.append("# " + op + "\n")
              .append("\tld t2, 0(sp)\n")
              .append("\tld t1, 8(sp)\n")
              .append("\t" + op + " t1, t1, t2\n")
              .append("\taddi sp, sp, 8\n")
              .append("\tsd t1, 0(sp)\n");
        } else {
            visit(ctx.unary());
        }
        return null;
    }

    @Override
    public Void visitUnary(UnaryContext ctx) {
        if (ctx.children.size() > 1) {
            visit(ctx.unary());
            String op = ctx.children.get(0).getText();
            if (op.equals("-")) {
                sb.append("\tld t1, 0(sp)\n")
                  .append("\tneg t1, t1\n")
                  .append("\tsd t1, 0(sp)\n");
            } else if (op.equals("!")) {
                sb.append("\tld t1, 0(sp)\n")
                  .append("\tseqz t1, t1\n")
                  .append("\tsd t1, 0(sp)\n");
            } else if (op.equals("~")) {
                sb.append("\tld t1, 0(sp)\n")
                  .append("\tnot t1, t1\n")
                  .append("\tsd t1, 0(sp)\n");
            }
        } else {
            visit(ctx.primary());
        }
        return null;
    }

    @Override
    public Void visitNumPrimary(NumPrimaryContext ctx) {
        TerminalNode node = ctx.NUM();
        if (compare(Integer.toString(Integer.MAX_VALUE), node.getText()) == -1)
            reportError("too large number", ctx);
        
        // TODO: 目前这里只能作 32 位的，将来需要改成 64 位

        sb.append("# number " + ctx.NUM().getText() + "\n")
          .append("\tli t1, " + ctx.NUM().getText() + "\n")
          .append("\taddi sp, sp, -8\n")
          .append("\tsd t1, 0(sp)\n");
        return null;
    }

    @Override
    public Void visitIdentPrimary(IdentPrimaryContext ctx) {
        String name = ctx.IDENT().getText();
        Optional<Integer> optionOffset = lookupSymbol(name);
        if (!optionOffset.isEmpty()) {
            sb.append("# read variable\n")
              .append("\tld t1, " + (- 8 * optionOffset.get()) + "(fp)\n")
              .append("\taddi sp, sp, -8\n")
              .append("\tsd t1, 0(sp)\n");    
        } else if (declaredGlobalTable.contains(name)) {
            sb.append("# read global variable\n")
              .append("\tlui t1, %hi(" + name + ")\n")
              .append("\tld t1, %lo(" + name + ")(t1)\n")
              .append("\taddi sp, sp, -8\n")
              .append("\tsd t1, 0(sp)\n");
        } else {
            reportError("use variable that is not defined", ctx);
        }
        
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
        if (declaredFuncTable.get(name) == null)
            reportError("try calling a undeclared function", ctx);
        else if (declaredFuncTable.get(name) != ctx.expr().size())
            reportError("the number of arguments is not equal to the number of parameters", ctx);
        sb.append("# prepare arguments\n");

        for (int i = ctx.expr().size() - 1; i >= 0; --i) {
            var expr = ctx.expr().get(i);
            visit(expr);
            if (i < 8) pop("a" + i);
        }

        sb.append("\tcall " + name + "\n");

        push("a0");
        return null;
    }

    /* symbol */
    Stack<Map<String, Integer>> symbolTable = new Stack<>(); // map to the number of the symbol in the function

    // look the symbol up for the offset (0 means non-existence)
    private Optional<Integer> lookupSymbol(String v) {
        for (int i = symbolTable.size() - 1; i >= 0; --i) {
            var map = symbolTable.elementAt(i);
            if (map.containsKey(v))
                return Optional.of(map.get(v));
        }
        return Optional.empty();
    }

    // map to the number of parameters of the function
    Map<String, Integer> declaredFuncTable = new HashMap<>();
    Map<String, Integer> definedFuncTable = new HashMap<>();
    String currentFunc;

    Set<String> declaredGlobalTable = new HashSet<>();
    Set<String> initializedGlobalTable = new HashSet<>();

    /* loop */
    int loopNo = 0;
    boolean inLoop = false;
    Stack<Integer> loopNos = new Stack<>();

    /* utils */
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
    }

    private void pop(String reg) {
        sb.append("# pop " + reg + "\n")
          .append("\tld " + reg + ", 0(sp)\n")
          .append("\taddi sp, sp, 8\n");
    }
}

// TODO: how large could the intermediate number in the assembly be?