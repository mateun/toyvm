// Generated from Expr.g4 by ANTLR 4.7
import org.antlr.v4.runtime.tree.ParseTreeVisitor;

/**
 * This interface defines a complete generic visitor for a parse tree produced
 * by {@link ExprParser}.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
public interface ExprVisitor<T> extends ParseTreeVisitor<T> {
	/**
	 * Visit a parse tree produced by {@link ExprParser#module}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitModule(ExprParser.ModuleContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ass}
	 * labeled alternative in {@link ExprParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAss(ExprParser.AssContext ctx);
	/**
	 * Visit a parse tree produced by the {@code termonly}
	 * labeled alternative in {@link ExprParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTermonly(ExprParser.TermonlyContext ctx);
	/**
	 * Visit a parse tree produced by the {@code subtraction}
	 * labeled alternative in {@link ExprParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitSubtraction(ExprParser.SubtractionContext ctx);
	/**
	 * Visit a parse tree produced by the {@code addition}
	 * labeled alternative in {@link ExprParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAddition(ExprParser.AdditionContext ctx);
	/**
	 * Visit a parse tree produced by {@link ExprParser#assignment}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAssignment(ExprParser.AssignmentContext ctx);
	/**
	 * Visit a parse tree produced by the {@code division}
	 * labeled alternative in {@link ExprParser#term}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitDivision(ExprParser.DivisionContext ctx);
	/**
	 * Visit a parse tree produced by the {@code factoronly}
	 * labeled alternative in {@link ExprParser#term}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFactoronly(ExprParser.FactoronlyContext ctx);
	/**
	 * Visit a parse tree produced by the {@code multiplication}
	 * labeled alternative in {@link ExprParser#term}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMultiplication(ExprParser.MultiplicationContext ctx);
	/**
	 * Visit a parse tree produced by {@link ExprParser#factor}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFactor(ExprParser.FactorContext ctx);
}