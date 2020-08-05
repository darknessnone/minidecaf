package minidecaf.parser;

// Generated from MiniDecafParser.g4 by ANTLR 4.7.1
import org.antlr.v4.runtime.tree.ParseTreeVisitor;

/**
 * This interface defines a complete generic visitor for a parse tree produced
 * by {@link MiniDecafParser}.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
public interface MiniDecafParserVisitor<T> extends ParseTreeVisitor<T> {
	/**
	 * Visit a parse tree produced by {@link MiniDecafParser#program}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitProgram(MiniDecafParser.ProgramContext ctx);
	/**
	 * Visit a parse tree produced by {@link MiniDecafParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpr(MiniDecafParser.ExprContext ctx);
	/**
	 * Visit a parse tree produced by {@link MiniDecafParser#add}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAdd(MiniDecafParser.AddContext ctx);
	/**
	 * Visit a parse tree produced by {@link MiniDecafParser#mul}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMul(MiniDecafParser.MulContext ctx);
	/**
	 * Visit a parse tree produced by {@link MiniDecafParser#unary}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitUnary(MiniDecafParser.UnaryContext ctx);
	/**
	 * Visit a parse tree produced by the {@code numPrimary}
	 * labeled alternative in {@link MiniDecafParser#primary}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitNumPrimary(MiniDecafParser.NumPrimaryContext ctx);
	/**
	 * Visit a parse tree produced by the {@code parenthesizePrimary}
	 * labeled alternative in {@link MiniDecafParser#primary}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitParenthesizePrimary(MiniDecafParser.ParenthesizePrimaryContext ctx);
}