// amazing parser

#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include "ast.h"

class Parser {
public:
    Parser(Lexer& lexer);
    std::unique_ptr<ASTNode> parse();

private:
    Lexer& lexer;
    Token currentToken;

    void advanceToken();
    std::unique_ptr<ASTNode> parseModule();
    void expectToken(TokenType type);
};

#endif
