#ifndef __AST_H__
#define __AST_H__
#include<vector>
#include<fstream>
#include<string>
using std::string;
using std::vector;
using std::endl;
using std::ofstream;
class Ast{
protected:
	int row, column;
	static int indent;
	static int functionnum;
public:
	Ast(int row, int column) : row(row), column(column){ indent = 0;}
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

class ExprAst: public Ast{
// protected:
// 	string value_;
public:
	ExprAst(int row, int column) : Ast(row, column){}
	// string value() { return value_;}
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
		printstream(fout, "not a5,a5");
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

class FunctionAst: public Ast{
	string name;
	StmtAst* stmt;
public:
	FunctionAst(int row, int column) : Ast(row, column){}
	void additem(string name, StmtAst* item){
		this->name = name;
		stmt = item;
	}
	void printto(ofstream &fout){
		printstream(fout, ".globl "+name);
		printstream(fout, ".type "+name+", @function");
		decIndent();
		printstream(fout, name+":");
		printstream(fout, ".LFB"+std::to_string(functionnum)+":");
		addIndent();
		int num_ = 16;
		printstream(fout, "addi	sp,sp,-"+std::to_string(num_));
		printstream(fout, "sw	s0,"+std::to_string(num_-4)+"(sp)");
		printstream(fout, "addi	s0,sp,"+std::to_string(num_));
		stmt->printto(fout);
		printstream(fout, "lw	s0,"+std::to_string(num_-4)+"(sp)");
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