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

    MiniDecafParser::ToplvContext* treeNode = parser.toplv();

    VarAllocVisitor varAllocVisitor;
    std::tuple<symTab<int>, symTab<int>, symTab<vector<int> > > symbol_ = varAllocVisitor.visitToplv(treeNode);

    CodeGenVisitor codeGenVisitor;
    string asmCode = codeGenVisitor.visitToplv(treeNode, symbol_);
    cout << asmCode << endl;
    return 0;
}