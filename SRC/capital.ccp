#include "lexer.h"
#include "parser.h"
#include "simulator.h"
#include <fstream>
#include <iostream>

int main() {
    std::ifstream file("tests/prim.hd1");  
    if (!file.is_open()) {
        std::cerr << "well that didn't work!??" << std::endl;
        return 1;
    }

    //Lexical analysis moment
    Lexer lexer(file);
    std::vector<Token> tokens = lexer.tokenize();

    //Parsing moment
    Parser parser(tokens);
    AST* ast = parser.parse();

    //Simulation moment
    Simulator simulator;
    simulator.run(ast);

    return 0;
}
