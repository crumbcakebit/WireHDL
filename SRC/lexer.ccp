#include "lexer.h"
#include <cctype>

Lexer::Lexer(const std::string& src) : source(src), currentPos(0) {}

Token Lexer::getNextToken() {
    while (currentPos < source.length()) {
        char currentChar = source[currentPos];

        if (isspace(currentChar)) {
            ++currentPos;
            continue;
        }

        if (isalpha(currentChar)) {
            std::string identifier = readIdentifier();
            if (identifier == "module") return Token(TokenType::Module);
            if (identifier == "input") return Token(TokenType::Input);
            // Other keywords
            return Token(TokenType::Identifier, identifier);
        }

        if (isdigit(currentChar)) {
            return Token(TokenType::Number, readNumber());
        }

        switch (currentChar) {
            case '{': ++currentPos; return Token(TokenType::OpenBrace);
            case '}': ++currentPos; return Token(TokenType::CloseBrace);
            case ';': ++currentPos; return Token(TokenType::Semicolon);
            // other symbols
            default: ++currentPos; return Token(TokenType::Unknown);
        }
    }
    return Token(TokenType::EndOfFile);
}

std::string Lexer::readIdentifier() {
    size_t start = currentPos;
    while (isalnum(source[currentPos])) ++currentPos;
    return source.substr(start, currentPos - start);
}

std::string Lexer::readNumber() {
    size_t start = currentPos;
    while (isdigit(source[currentPos])) ++currentPos;
    return source.substr(start, currentPos - start);
}
