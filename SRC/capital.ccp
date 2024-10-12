#include <fstream>
#include <sstream>
#include "lexer.h"
#include "parser.h"
// other here

int main() {
    std::ifstream file("test/prim1.hd1"); 
    if (!file) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    std::stringstream buffer;
    buffer << file.rdbuf(); 
    std::string source = buffer.str();

    Lexer lexer(source); 
   
    return 0;
}

