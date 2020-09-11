// Generated from Expr.g4 by ANTLR 4.8
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link ExprParser}.
 */
public interface ExprListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link ExprParser#prog}.
	 * @param ctx the parse tree
	 */
	void enterProg(ExprParser.ProgContext ctx);
	/**
	 * Exit a parse tree produced by {@link ExprParser#prog}.
	 * @param ctx the parse tree
	 */
	void exitProg(ExprParser.ProgContext ctx);
	/**
	 * Enter a parse tree produced by {@link ExprParser#literal}.
	 * @param ctx the parse tree
	 */
	void enterLiteral(ExprParser.LiteralContext ctx);
	/**
	 * Exit a parse tree produced by {@link ExprParser#literal}.
	 * @param ctx the parse tree
	 */
	void exitLiteral(ExprParser.LiteralContext ctx);
	/**
	 * Enter a parse tree produced by {@link ExprParser#variable}.
	 * @param ctx the parse tree
	 */
	void enterVariable(ExprParser.VariableContext ctx);
	/**
	 * Exit a parse tree produced by {@link ExprParser#variable}.
	 * @param ctx the parse tree
	 */
	void exitVariable(ExprParser.VariableContext ctx);
	/**
	 * Enter a parse tree produced by {@link ExprParser#varAssign}.
	 * @param ctx the parse tree
	 */
	void enterVarAssign(ExprParser.VarAssignContext ctx);
	/**
	 * Exit a parse tree produced by {@link ExprParser#varAssign}.
	 * @param ctx the parse tree
	 */
	void exitVarAssign(ExprParser.VarAssignContext ctx);
	/**
	 * Enter a parse tree produced by {@link ExprParser#varDecl}.
	 * @param ctx the parse tree
	 */
	void enterVarDecl(ExprParser.VarDeclContext ctx);
	/**
	 * Exit a parse tree produced by {@link ExprParser#varDecl}.
	 * @param ctx the parse tree
	 */
	void exitVarDecl(ExprParser.VarDeclContext ctx);
	/**
	 * Enter a parse tree produced by {@link ExprParser#block}.
	 * @param ctx the parse tree
	 */
	void enterBlock(ExprParser.BlockContext ctx);
	/**
	 * Exit a parse tree produced by {@link ExprParser#block}.
	 * @param ctx the parse tree
	 */
	void exitBlock(ExprParser.BlockContext ctx);
	/**
	 * Enter a parse tree produced by {@link ExprParser#functionArgument}.
	 * @param ctx the parse tree
	 */
	void enterFunctionArgument(ExprParser.FunctionArgumentContext ctx);
	/**
	 * Exit a parse tree produced by {@link ExprParser#functionArgument}.
	 * @param ctx the parse tree
	 */
	void exitFunctionArgument(ExprParser.FunctionArgumentContext ctx);
	/**
	 * Enter a parse tree produced by {@link ExprParser#functionDecl}.
	 * @param ctx the parse tree
	 */
	void enterFunctionDecl(ExprParser.FunctionDeclContext ctx);
	/**
	 * Exit a parse tree produced by {@link ExprParser#functionDecl}.
	 * @param ctx the parse tree
	 */
	void exitFunctionDecl(ExprParser.FunctionDeclContext ctx);
	/**
	 * Enter a parse tree produced by {@link ExprParser#functionCall}.
	 * @param ctx the parse tree
	 */
	void enterFunctionCall(ExprParser.FunctionCallContext ctx);
	/**
	 * Exit a parse tree produced by {@link ExprParser#functionCall}.
	 * @param ctx the parse tree
	 */
	void exitFunctionCall(ExprParser.FunctionCallContext ctx);
	/**
	 * Enter a parse tree produced by {@link ExprParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterExpr(ExprParser.ExprContext ctx);
	/**
	 * Exit a parse tree produced by {@link ExprParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitExpr(ExprParser.ExprContext ctx);
	/**
	 * Enter a parse tree produced by {@link ExprParser#statement}.
	 * @param ctx the parse tree
	 */
	void enterStatement(ExprParser.StatementContext ctx);
	/**
	 * Exit a parse tree produced by {@link ExprParser#statement}.
	 * @param ctx the parse tree
	 */
	void exitStatement(ExprParser.StatementContext ctx);
}