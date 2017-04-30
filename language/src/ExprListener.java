// Generated from Expr.g4 by ANTLR 4.7
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link ExprParser}.
 */
public interface ExprListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link ExprParser#module}.
	 * @param ctx the parse tree
	 */
	void enterModule(ExprParser.ModuleContext ctx);
	/**
	 * Exit a parse tree produced by {@link ExprParser#module}.
	 * @param ctx the parse tree
	 */
	void exitModule(ExprParser.ModuleContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ass}
	 * labeled alternative in {@link ExprParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterAss(ExprParser.AssContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ass}
	 * labeled alternative in {@link ExprParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitAss(ExprParser.AssContext ctx);
	/**
	 * Enter a parse tree produced by the {@code termonly}
	 * labeled alternative in {@link ExprParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterTermonly(ExprParser.TermonlyContext ctx);
	/**
	 * Exit a parse tree produced by the {@code termonly}
	 * labeled alternative in {@link ExprParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitTermonly(ExprParser.TermonlyContext ctx);
	/**
	 * Enter a parse tree produced by the {@code subtraction}
	 * labeled alternative in {@link ExprParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterSubtraction(ExprParser.SubtractionContext ctx);
	/**
	 * Exit a parse tree produced by the {@code subtraction}
	 * labeled alternative in {@link ExprParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitSubtraction(ExprParser.SubtractionContext ctx);
	/**
	 * Enter a parse tree produced by the {@code addition}
	 * labeled alternative in {@link ExprParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterAddition(ExprParser.AdditionContext ctx);
	/**
	 * Exit a parse tree produced by the {@code addition}
	 * labeled alternative in {@link ExprParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitAddition(ExprParser.AdditionContext ctx);
	/**
	 * Enter a parse tree produced by {@link ExprParser#assignment}.
	 * @param ctx the parse tree
	 */
	void enterAssignment(ExprParser.AssignmentContext ctx);
	/**
	 * Exit a parse tree produced by {@link ExprParser#assignment}.
	 * @param ctx the parse tree
	 */
	void exitAssignment(ExprParser.AssignmentContext ctx);
	/**
	 * Enter a parse tree produced by the {@code division}
	 * labeled alternative in {@link ExprParser#term}.
	 * @param ctx the parse tree
	 */
	void enterDivision(ExprParser.DivisionContext ctx);
	/**
	 * Exit a parse tree produced by the {@code division}
	 * labeled alternative in {@link ExprParser#term}.
	 * @param ctx the parse tree
	 */
	void exitDivision(ExprParser.DivisionContext ctx);
	/**
	 * Enter a parse tree produced by the {@code factoronly}
	 * labeled alternative in {@link ExprParser#term}.
	 * @param ctx the parse tree
	 */
	void enterFactoronly(ExprParser.FactoronlyContext ctx);
	/**
	 * Exit a parse tree produced by the {@code factoronly}
	 * labeled alternative in {@link ExprParser#term}.
	 * @param ctx the parse tree
	 */
	void exitFactoronly(ExprParser.FactoronlyContext ctx);
	/**
	 * Enter a parse tree produced by the {@code multiplication}
	 * labeled alternative in {@link ExprParser#term}.
	 * @param ctx the parse tree
	 */
	void enterMultiplication(ExprParser.MultiplicationContext ctx);
	/**
	 * Exit a parse tree produced by the {@code multiplication}
	 * labeled alternative in {@link ExprParser#term}.
	 * @param ctx the parse tree
	 */
	void exitMultiplication(ExprParser.MultiplicationContext ctx);
	/**
	 * Enter a parse tree produced by {@link ExprParser#factor}.
	 * @param ctx the parse tree
	 */
	void enterFactor(ExprParser.FactorContext ctx);
	/**
	 * Exit a parse tree produced by {@link ExprParser#factor}.
	 * @param ctx the parse tree
	 */
	void exitFactor(ExprParser.FactorContext ctx);
}