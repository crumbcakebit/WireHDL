#ifndef LEXER_H
#define LEXER_H

#include <string>

enum class TokenType {
    Module, Input, Output, Stage, Always, Pipeline, Identifier, Number,
    OpenBrace, CloseBrace, Semicolon, Equal, If, Else, LBracket, RBracket, 
    LParen, RParen, Comma, EndOfFile, Unknown
};

class Token {
public:
    Token(TokenType type, const std::string& value = "")
        : type(type), value(value) {}

    TokenType getType() const { return type; }
    std::string getValue() const { return value; }

private:
    TokenType type;
    std::string value;
};

class Lexer {
public:
    Lexer(const std::string& source);
    Token getNextToken();

private:
    std::string source;
    size_t currentPos;

    std::string readIdentifier();
    std::string readNumber();
    char currentChar() const;
    void advance();
};

#endif
