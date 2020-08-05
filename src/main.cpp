#include <iostream>

#include "MiniDecafLexer.h"
#include "MiniDecafParser.h"
#include "CodeGenVisitor.h"
#include "VarAllocVisitor.h"

using namespace antlr4;
using namespace std;

int main(int argc, const char* argv[]) {
    if (argc != 2) {
        std::cerr << "[error] Input sourcefile required: ./MiniDecaf <sourcefile>\n";
        return 1;
    }
    ifstream sourceFile;
    sourceFile.open(argv[1]);

    ANTLRInputStream input(sourceFile);
    MiniDecafLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    MiniDecafParser parser(&tokens);

    MiniDecafParser::ProgContext* treeNode = parser.prog();

    VarAllocVisitor varAllocVisitor;
    unordered_map<string, int> symbol_ = varAllocVisitor.visitProg(treeNode);
    
    CodeGenVisitor codeGenVisitor;
    string asmCode = codeGenVisitor.visitProg(treeNode, symbol_);
    cout << asmCode << endl;
    return 0;
}