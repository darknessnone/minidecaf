#ifndef __PARSER_H__
#define __PARSER_H__
#include <string.h>
#include <iostream>
#include "token.h"
#include "ast.h"
using std::string;
class Parser{
	vector<Token>& tokenlist;
	int pos;
	ProgramAst* ast;
public:
	Parser(vector<Token>& lists): tokenlist(lists) {pos = 0;}
	ProgramAst* getAst(){return ast;}
	void matchToken(string expected){
		if (tokenlist[pos].label() == expected){
			pos++;
		}else{
			std::cout << "expected " << expected << " when matching "<< tokenlist[pos].label() <<
			" token in row " << tokenlist[pos].row() << " column " << tokenlist[pos].column() << 
			std::endl;
			exit(-1) ;
		}
	}

	bool lookForward(string expected, int x = 0){
		if (tokenlist[pos+x].label() == expected)
			return true;
		return false;
	}

	void parserProgram(){
		ast = new ProgramAst(tokenlist[pos].row(), tokenlist[pos].column());
		FunctionAst* function_ast = parserFunction();
		ast->additem(function_ast);
	}

	FunctionAst* parserFunction(){
		FunctionAst* function_ast = new FunctionAst(tokenlist[pos].row(), tokenlist[pos].column());
		matchToken("int");
		matchToken("id");
		string name = tokenlist[pos-1].value();
		matchToken("(");
		matchToken(")");
		matchToken("{");
		vector<StmtAst*> stmtlist;
		int num = 0;
		stmtlist.clear();
		while (!lookForward("}")){
			StmtAst* stmt_ast = parserStmt(num);
			stmtlist.push_back(stmt_ast);
		}
		matchToken("}");
		function_ast->additem(name, num, stmtlist);
		return function_ast;
	}

	StmtAst* parserStmt(int& num){
		StmtAst* stmt_ast;
		if (lookForward("return"))
			stmt_ast = parserReturnStmt();
		else if (lookForward("int"))
			stmt_ast = parserLocalVariables(num);
		else if (lookForward("if"))
			stmt_ast = parserIfStmt(num);
		else{
			stmt_ast = parserExprStmt();
		}
		return stmt_ast;
	}

	StmtAst* parserExprStmt(){
		ExprStmt* stmt_ast = new ExprStmt(tokenlist[pos].row(), tokenlist[pos].column());
		ExprAst* expr_ast = parserExpr();
		matchToken(";");
		stmt_ast->additem(expr_ast);
		return stmt_ast;
	}

	StmtAst* parserIfStmt(int &num){
		IfStmt* stmt_ast = new IfStmt(tokenlist[pos].row(), tokenlist[pos].column());
		matchToken("if");
		matchToken("(");
		ExprAst* expr_ast = parserExpr();
		matchToken(")");
		StmtAst* stmt1_ast = parserStmt(num);
		StmtAst* stmt2_ast = NULL;
		if (lookForward("else")){
			matchToken("else");
			stmt2_ast = parserStmt(num);
		}
		stmt_ast->additem(expr_ast, stmt1_ast, stmt2_ast);
		return stmt_ast;
	}

	StmtAst* parserLocalVariables(int& num){
		LocalVariablesAst* stmt_ast = new LocalVariablesAst(tokenlist[pos].row(), tokenlist[pos].column());
		matchToken("int");
		matchToken("id");
		string name = tokenlist[pos-1].value();
		ExprAst* expr_ast = NULL;
		if (lookForward("=")){
			matchToken("=");
			expr_ast = parserExpr();
		}
		matchToken(";");
		num++;
		stmt_ast->additem(name, num, expr_ast);
		return stmt_ast;
	}

	ReturnStmtAst* parserReturnStmt(){
		ReturnStmtAst* return_stmt_ast = new ReturnStmtAst(tokenlist[pos].row(), tokenlist[pos].column());
		matchToken("return");
		ExprAst* expr_ast = parserExpr();
		matchToken(";");
		return_stmt_ast->additem(expr_ast);
		return return_stmt_ast;
	}

	ExprAst* parserExpr(){
		ExprAst* expr_ast;
		if (lookForward("=",1)){
			expr_ast = parserAssign();	
		}else
			expr_ast = parserLogicalExpr();
		return expr_ast;
	}

	ExprAst* parserAssign(){
		AssignAst* assign_ast = new AssignAst(tokenlist[pos].row(), tokenlist[pos].column());
		matchToken("id");
		string name = tokenlist[pos-1].value();
		matchToken("=");
		ExprAst* expr_ast = parserExpr();
		assign_ast->additem(name, expr_ast);
		return assign_ast;
	}

	ExprAst* parserLogicalExpr(){
		ExprAst* expr1_ast = parserRqualityExpr();
		while(lookForward("||")){
			string label = tokenlist[pos].label();
			LogicalExpr* add_ast = new LogicalExpr(tokenlist[pos].row(), tokenlist[pos].column());
			matchToken(label);
			ExprAst* expr2_ast = parserRqualityExpr();
			add_ast->additem(expr1_ast, expr2_ast);
			expr1_ast = add_ast;
		}
		return expr1_ast;
	}

	ExprAst* parserRqualityExpr(){
		ExprAst* expr1_ast = parserRelationalExpr();
		while(lookForward("&&")){
			string label = tokenlist[pos].label();
			RqualityExpr* add_ast = new RqualityExpr(tokenlist[pos].row(), tokenlist[pos].column());
			matchToken(label);
			ExprAst* expr2_ast = parserRelationalExpr();
			add_ast->additem(expr1_ast, expr2_ast);
			expr1_ast = add_ast;
		}
		return expr1_ast;
	}

	ExprAst* parserRelationalExpr(){
		ExprAst* expr1_ast = parserAdditiveExpr();
		while(lookForward("==") || lookForward("!=")){
			string label = tokenlist[pos].label();
			RelationalExpr* add_ast = new RelationalExpr(tokenlist[pos].row(), tokenlist[pos].column(), label);
			matchToken(label);
			ExprAst* expr2_ast = parserAdditiveExpr();
			add_ast->additem(expr1_ast, expr2_ast);
			expr1_ast = add_ast;
		}
		return expr1_ast;
	}

	ExprAst* parserAdditiveExpr(){
		ExprAst* expr1_ast = parserAddSubAst();
		while(lookForward("<") || lookForward(">") || lookForward("<=") || lookForward(">=")){
			string label = tokenlist[pos].label();
			AdditiveExpr* add_ast = new AdditiveExpr(tokenlist[pos].row(), tokenlist[pos].column(), label);
			matchToken(label);
			ExprAst* expr2_ast = parserAddSubAst();
			add_ast->additem(expr1_ast, expr2_ast);
			expr1_ast = add_ast;
		}
		return expr1_ast;
	}

	ExprAst* parserAddSubAst(){
		ExprAst* expr1_ast = parserMulDivAst();
		while(lookForward("+") || lookForward("-")){
			if (lookForward("+")){
				AddAst* add_ast = new AddAst(tokenlist[pos].row(), tokenlist[pos].column());
				matchToken("+");
				ExprAst* expr2_ast = parserMulDivAst();
				add_ast->additem(expr1_ast, expr2_ast);
				expr1_ast = add_ast;
			}else{
				SubAst* sub_ast = new SubAst(tokenlist[pos].row(), tokenlist[pos].column());
				matchToken("-");
				ExprAst* expr2_ast = parserMulDivAst();
				sub_ast->additem(expr1_ast, expr2_ast);
				expr1_ast = sub_ast;
			}
		}
		return expr1_ast;
	}

	ExprAst* parserMulDivAst(){
		ExprAst* expr1_ast = parserUnary();
		while(lookForward("*") || lookForward("/")){
			if (lookForward("*")){
				MulAst* mul_ast = new MulAst(tokenlist[pos].row(), tokenlist[pos].column());
				matchToken("*");
				ExprAst* expr2_ast = parserUnary();
				mul_ast->additem(expr1_ast, expr2_ast);
				expr1_ast = mul_ast;
			}else{
				DivAst* div_ast = new DivAst(tokenlist[pos].row(), tokenlist[pos].column());
				matchToken("/");
				ExprAst* expr2_ast = parserUnary();
				div_ast->additem(expr1_ast, expr2_ast);
				expr1_ast = div_ast;
			}
		}
		return expr1_ast;
	}


	ExprAst* parserUnary(){
		ExprAst* expr_ast;
		if (lookForward("-"))
			expr_ast = parserNegaUnary();
		else if (lookForward("+")){
			matchToken("+");
			expr_ast = parserUnary();
		}else if (lookForward("~"))
			expr_ast = parserBitComUnary();
		else if (lookForward("!"))
			expr_ast = parserLogicUnary();
		else if (lookForward("(")){
			matchToken("(");
			expr_ast = parserExpr();
			matchToken(")");
		}else if (lookForward("id"))
			expr_ast = parserLocalExpr();
		else
			expr_ast = parserConstant();
		return expr_ast;
	}

	ExprAst* parserLocalExpr(){
		LocalExpr* expr_ast = new LocalExpr(tokenlist[pos].row(), tokenlist[pos].column());
		matchToken("id");
		string name = tokenlist[pos-1].value();
		expr_ast->additem(name);
		return expr_ast;
	}

	ExprAst* parserNegaUnary(){
		NegaUnaryAst* expr_ast = new NegaUnaryAst(tokenlist[pos].row(), tokenlist[pos].column());
		matchToken("-");
		ExprAst* new_expr_ast = parserUnary();
		expr_ast->additem(new_expr_ast);
		return expr_ast;
	}

	ExprAst* parserBitComUnary(){
		BitComUnaryAst* expr_ast = new BitComUnaryAst(tokenlist[pos].row(), tokenlist[pos].column());
		matchToken("~");
		ExprAst* new_expr_ast = parserUnary();
		expr_ast->additem(new_expr_ast);
		return expr_ast;
	}

	ExprAst* parserLogicUnary(){
		LogicUnaryAst* expr_ast = new LogicUnaryAst(tokenlist[pos].row(), tokenlist[pos].column());
		matchToken("!");
		ExprAst* new_expr_ast = parserUnary();
		expr_ast->additem(new_expr_ast);
		return expr_ast;
	}

	ConstantAst* parserConstant(){
		ConstantAst* constant_ast = new ConstantAst(tokenlist[pos].row(), tokenlist[pos].column());
		matchToken("num");
		constant_ast->additem(tokenlist[pos-1].intvalue());
		return constant_ast;
	}
};

#endif