#include "lexer.h"
#include "parser.h"
#include "simulator.h"
#include <iostream>
#include <fstream>

int main() {
    std::ifstream file("tests/testcases.hd1");
    std::string sourceCode((std::istreambuf_iterator<char>(file)),
                            std::istreambuf_iterator<char>());

    Lexer lexer(sourceCode);
    Parser parser(lexer);
    std::unique_ptr<ASTNode> ast = parser.parse();

    if (ast) {
        Simulator simulator;
        simulator.simulate(*static_cast<ModuleNode*>(ast.get()));
    }

    return 0;
}
