#include <iostream>
#include <fstream>
#include <sstream>
#include "lexer.h"
#include "parser.h"

int main() {
    std::ifstream file("hd1/prim.hd1");
    if (!file) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string source = buffer.str();

    Lexer lexer(source);
    Parser parser(lexer);
    
    auto ast = parser.parse();

    return 0;
}
