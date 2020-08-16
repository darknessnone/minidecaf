#ifndef __AST_H__
#define __AST_H__
#include<vector>
#include<fstream>
#include<string>
#include<map>
using std::string;
using std::vector;
using std::endl;
using std::map;
using std::ofstream;
class Ast{
protected:
	int row, column;
	static int indent;
	static int functionnum;
	static map<string, int> exprnum;
public:
	Ast(int row, int column) : row(row), column(column){ } 
	void addIndent() { indent ++; }
	void decIndent() { indent --; }
	void printstream(ofstream &fout, string st){
		for (int i = 0; i < indent; ++i)
			fout << "\t" ;
		fout << st << endl;
	}
	virtual void printto(ofstream &fout){
		std::cout << "AStprint" << std::endl;
	}
};

int Ast::indent = 0;
int Ast::functionnum = 0;
map<string, int> Ast::exprnum = {};
class ExprAst: public Ast{
protected:
	bool isVariable_;
	string variable_;
public:
	ExprAst(int row, int column, bool isVariable = false) : Ast(row, column), isVariable_(isVariable){}
	bool isVariable() { return isVariable_;}
	string variable() { return variable_; };
};

class ConstantAst: public ExprAst{
	int intvalue;
public:
	ConstantAst(int row, int column) : ExprAst(row, column){}
	void additem(int item){
		intvalue = item;
	}
	void printto(ofstream &fout){
		printstream(fout, "li a5,"+std::to_string(intvalue));
	}
};

class NegaUnaryAst: public ExprAst{
	ExprAst* expr;
public:
	NegaUnaryAst(int row, int column) : ExprAst(row, column){}
	void additem(ExprAst* expr){
		this->expr = expr;
	}
	void printto(ofstream &fout){
		expr->printto(fout);
		if (expr->isVariable()){
			printstream(fout, "lw a5,"+expr->variable());
		}
		printstream(fout, "neg a5,a5");
	}
};

class BitComUnaryAst: public ExprAst{
	ExprAst* expr;
public:
	BitComUnaryAst(int row, int column) : ExprAst(row, column){}
	void additem(ExprAst* expr){
		this->expr = expr;
	}
	void printto(ofstream &fout){
		expr->printto(fout);
		if (expr->isVariable()){
			printstream(fout, "lw a5,"+expr->variable());
		}
		printstream(fout, "not a5,a5");
	}
};

class LogicUnaryAst: public ExprAst{
	ExprAst* expr;
public:
	LogicUnaryAst(int row, int column) : ExprAst(row, column){}
	void additem(ExprAst* expr){
		this->expr = expr;
	}
	void printto(ofstream &fout){
		expr->printto(fout);
		if (expr->isVariable()){
			printstream(fout, "lw a5,"+expr->variable());
		}
		printstream(fout, "seqz a5,a5");
	}
};

class MulAst : public ExprAst{
	ExprAst* expr1;
	ExprAst* expr2;
public:
	MulAst(int row, int column) : ExprAst(row, column){}
	void additem(ExprAst* e1, ExprAst* e2){
		expr1 = e1;
		expr2 = e2;
	}
	void printto(ofstream &fout){
		expr1->printto(fout);
		if (expr1->isVariable()){
			printstream(fout, "lw a5,"+expr1->variable());
		}
		printstream(fout, "sd a5, -8(sp)");
		printstream(fout, "addi sp, sp, -8");
		expr2->printto(fout);
		if (expr2->isVariable()){
			printstream(fout, "lw a5,"+expr2->variable());
		}
		printstream(fout, "ld a4, 0(sp)");
		printstream(fout, "addi sp, sp, 8");
		printstream(fout, "mul a5, a4, a5");
	}
};

class DivAst : public ExprAst{
	ExprAst* expr1;
	ExprAst* expr2;
public:
	DivAst(int row, int column) : ExprAst(row, column){}
	void additem(ExprAst* e1, ExprAst* e2){
		expr1 = e1;
		expr2 = e2;
	}
	void printto(ofstream &fout){
		expr1->printto(fout);
		if (expr1->isVariable()){
			printstream(fout, "lw a5,"+expr1->variable());
		}
		printstream(fout, "sd a5, -8(sp)");
		printstream(fout, "addi sp, sp, -8");
		expr2->printto(fout);
		if (expr2->isVariable()){
			printstream(fout, "lw a5,"+expr2->variable());
		}
		printstream(fout, "ld a4, 0(sp)");
		printstream(fout, "addi sp, sp, 8");
		printstream(fout, "div a5, a4, a5");
	}
};

class AddAst : public ExprAst{
	ExprAst* expr1;
	ExprAst* expr2;
public:
	AddAst(int row, int column) : ExprAst(row, column){}
	void additem(ExprAst* e1, ExprAst* e2){
		expr1 = e1;
		expr2 = e2;
	}
	void printto(ofstream &fout){
		expr1->printto(fout);
		if (expr1->isVariable()){
			printstream(fout, "lw a5,"+expr1->variable());
		}
		printstream(fout, "sd a5, -8(sp)");
		printstream(fout, "addi sp, sp, -8");
		expr2->printto(fout);
		if (expr2->isVariable()){
			printstream(fout, "lw a5,"+expr2->variable());
		}
		printstream(fout, "ld a4, 0(sp)");
		printstream(fout, "addi sp, sp, 8");
		printstream(fout, "add a5, a4, a5");
	}
};

class SubAst : public ExprAst{
	ExprAst* expr1;
	ExprAst* expr2;
public:
	SubAst(int row, int column) : ExprAst(row, column){}
	void additem(ExprAst* e1, ExprAst* e2){
		expr1 = e1;
		expr2 = e2;
	}
	void printto(ofstream &fout){
		expr1->printto(fout);
		if (expr1->isVariable()){
			printstream(fout, "lw a5,"+expr1->variable());
		}
		printstream(fout, "sd a5, -8(sp)");
		printstream(fout, "addi sp, sp, -8");
		expr2->printto(fout);
		if (expr2->isVariable()){
			printstream(fout, "lw a5,"+expr2->variable());
		}
		printstream(fout, "ld a4, 0(sp)");
		printstream(fout, "addi sp, sp, 8");
		printstream(fout, "sub a5, a4, a5");
	}
};

class AdditiveExpr : public ExprAst{
	ExprAst* expr1;
	ExprAst* expr2;
	string label;
public:
	AdditiveExpr(int row, int column, string label) : ExprAst(row, column), label(label){}
	void additem(ExprAst* e1, ExprAst* e2){
		expr1 = e1;
		expr2 = e2;
	}
	void printto(ofstream &fout){
		expr1->printto(fout);
		if (expr1->isVariable()){
			printstream(fout, "lw a5,"+expr1->variable());
		}
		printstream(fout, "sd a5, -8(sp)");
		printstream(fout, "addi sp, sp, -8");
		expr2->printto(fout);
		if (expr2->isVariable()){
			printstream(fout, "lw a5,"+expr2->variable());
		}
		printstream(fout, "ld a4, 0(sp)");
		printstream(fout, "addi sp, sp, 8");
		if (label == "<")
			printstream(fout, "slt a5, a4, a5");
		else if (label == ">")
			printstream(fout, "sgt a5, a4, a5");
		else if (label == "<="){
			printstream(fout, "sgt a5, a4, a5");
			printstream(fout, "xor a5, a5, 1");
		}else {
			printstream(fout, "slt a5, a4, a5");
			printstream(fout, "xor a5, a5, 1");
		}
	}
};

class RelationalExpr : public ExprAst{
	ExprAst* expr1;
	ExprAst* expr2;
	string label;
public:
	RelationalExpr(int row, int column, string label) : ExprAst(row, column), label(label){}
	void additem(ExprAst* e1, ExprAst* e2){
		expr1 = e1;
		expr2 = e2;
	}
	void printto(ofstream &fout){
		expr1->printto(fout);
		if (expr1->isVariable()){
			printstream(fout, "lw a5,"+expr1->variable());
		}
		printstream(fout, "sd a5, -8(sp)");
		printstream(fout, "addi sp, sp, -8");
		expr2->printto(fout);
		if (expr2->isVariable()){
			printstream(fout, "lw a5,"+expr2->variable());
		}
		printstream(fout, "ld a4, 0(sp)");
		printstream(fout, "addi sp, sp, 8");
		if (label == "!="){
			printstream(fout, "xor a5, a4, a5");
			printstream(fout, "snez a5, a5");
		}else{
			printstream(fout, "xor a5, a4, a5");
			printstream(fout, "seqz a5, a5");
		}
	}
};

class RqualityExpr : public ExprAst{
	ExprAst* expr1;
	ExprAst* expr2;
public:
	RqualityExpr(int row, int column) : ExprAst(row, column){}
	void additem(ExprAst* e1, ExprAst* e2){
		expr1 = e1;
		expr2 = e2;
	}
	void printto(ofstream &fout){
		expr1->printto(fout);
		if (expr1->isVariable()){
			printstream(fout, "lw a5,"+expr1->variable());
		}
		printstream(fout, "sd a5, -8(sp)");
		printstream(fout, "addi sp, sp, -8");
		expr2->printto(fout);
		if (expr2->isVariable()){
			printstream(fout, "lw a5,"+expr2->variable());
		}
		printstream(fout, "ld a4, 0(sp)");
		printstream(fout, "addi sp, sp, 8");
		printstream(fout, "snez a4, a4");
		printstream(fout, "snez a5, a5");
		printstream(fout, "and a5, a5, a4");
	}
};

class LogicalExpr : public ExprAst{
	ExprAst* expr1;
	ExprAst* expr2;
public:
	LogicalExpr(int row, int column) : ExprAst(row, column){}
	void additem(ExprAst* e1, ExprAst* e2){
		expr1 = e1;
		expr2 = e2;
	}
	void printto(ofstream &fout){
		expr1->printto(fout);
		if (expr1->isVariable()){
			printstream(fout, "lw a5,"+expr1->variable());
		}
		printstream(fout, "sd a5, -8(sp)");
		printstream(fout, "addi sp, sp, -8");
		expr2->printto(fout);
		if (expr2->isVariable()){
			printstream(fout, "lw a5,"+expr2->variable());
		}
		printstream(fout, "ld a4, 0(sp)");
		printstream(fout, "addi sp, sp, 8");
		printstream(fout, "or a5, a5, a4");
		printstream(fout, "snez a5, a5");
	}
};

class AssignAst : public ExprAst{
	ExprAst* expr;
	string name;
public:
	AssignAst(int row, int column) : ExprAst(row, column){}
	void additem(string name_, ExprAst* e){
		expr = e;
		name = name_;
	}
	void printto(ofstream &fout){
		expr->printto(fout);
		if (expr->isVariable()){
			printstream(fout, "lw a5,"+expr->variable());
		}
		printstream(fout, "sw a5, -"+std::to_string(exprnum[name])+"(s0)");
	}
};


class LocalExpr: public ExprAst{
	string name;
public:
	LocalExpr(int row, int column) : ExprAst(row, column, true){}
	void additem(string name){
		this->name = name;
	    this->variable_ = "-"+std::to_string(exprnum[name])+"(s0)";
	}
	void printto(ofstream &fout){
	}
};

class StmtAst: public Ast{
public:
	StmtAst(int row, int column) : Ast(row, column){}
};

class ReturnStmtAst: public StmtAst{
	ExprAst* expr;
public:
	ReturnStmtAst(int row, int column) : StmtAst(row, column){}
	void additem(ExprAst* item){
		expr = item;
	}
	void printto(ofstream &fout){
		expr->printto(fout);
		printstream(fout, "mv a0,a5");
	}
};

class LocalVariablesAst: public StmtAst{
	string name;
	ExprAst* expr;
	int position;
public:
	LocalVariablesAst(int row, int column) : StmtAst(row, column){}
	void additem(string name, int num, ExprAst* item){
		this->name = name;
		expr = item;
		this->position = num*8+8;
		exprnum[name] = position;
	}
	void printto(ofstream &fout){
		if (expr!=NULL){
			expr->printto(fout);
			printstream(fout, "sw a5, -"+ std::to_string(position)+"(s0)");
		}
	}
};

class ExprStmt: public StmtAst{
	ExprAst* expr;
public:
	ExprStmt(int row, int column) : StmtAst(row, column){}
	void additem(ExprAst* item){
		expr = item;
	}
	void printto(ofstream &fout){
		expr->printto(fout);
	}
};

class FunctionAst: public Ast{
	string name;
	vector<StmtAst*> stmtlist;
	int num_;
public:
	FunctionAst(int row, int column) : Ast(row, column){}
	void additem(string name, int id_num, vector<StmtAst*> list){
		this->name = name;
		stmtlist = list;
		num_ = 16 + id_num * 8;
	}
	void printto(ofstream &fout){
		printstream(fout, ".globl "+name);
		printstream(fout, ".type "+name+", @function");
		decIndent();
		printstream(fout, name+":");
		printstream(fout, ".LFB"+std::to_string(functionnum)+":");
		addIndent();
		printstream(fout, "addi	sp,sp,-"+std::to_string(num_));
		printstream(fout, "sw	s0,"+std::to_string(num_-8)+"(sp)");
		printstream(fout, "addi	s0,sp,"+std::to_string(num_));
		for (int i = 0; i < stmtlist.size(); ++i)
				stmtlist[i]->printto(fout);
		printstream(fout, "lw	s0,"+std::to_string(num_-8)+"(sp)");
		printstream(fout, "addi	sp,sp,"+std::to_string(num_));
		printstream(fout, "jr	ra");
		decIndent();
		printstream(fout, ".LFE"+std::to_string(functionnum)+":");
		addIndent();
		printstream(fout, ".size "+name+", .-"+name);
		printstream(fout, ".ident	\"GCC: (xPack GNU RISC-V Embedded GCC, 64-bit) 8.3.0\"");


		functionnum++;
	}
};

class ProgramAst: public Ast{
	FunctionAst* function;
public:
	ProgramAst(int row, int column) : Ast(row, column){}
	void additem(FunctionAst* func){
		function = func;
	}
	void printto(ofstream &fout, string filename){
		addIndent();
		printstream(fout, ".file	\""+filename+"\"");
		printstream(fout, ".option nopic");
		printstream(fout, ".text");
		printstream(fout, ".align	1");
		function->printto(fout);
		decIndent();
	}
};

#endif