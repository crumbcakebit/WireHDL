// parser.h
#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"  // Assuming you have a lexer class that provides tokens
#include "ast.h"    // Include AST node definitions
#include <memory>
#include <string>

class Parser {
public:
    explicit Parser(Lexer& lex);
    std::unique_ptr<ASTNode> parse();

private:
    void advanceToken();
    void expectToken(TokenType type);
    std::unique_ptr<ASTNode> parseModule();
    std::unique_ptr<ASTNode> parseInput();

    Lexer& lexer;
    Token currentToken;
};

#endif // PARSER_H
