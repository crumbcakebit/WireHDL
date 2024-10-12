#include "lexer.h"
#include <cctype>
#include <stdexcept>

Lexer::Lexer(const std::string& source) : source(source), currentPos(0) {}

Token Lexer::getNextToken() {
    while (currentPos < source.size()) {
        char currentChar = source[currentPos];

        // Skip whitespace
        if (std::isspace(currentChar)) {
            currentPos++;
            continue;
        }

        // Handle identifiers
        if (std::isalpha(currentChar)) {
            std::string identifier = readIdentifier();
            if (identifier == "module") return Token(TokenType::Module);
            if (identifier == "input") return Token(TokenType::Input);
            if (identifier == "output") return Token(TokenType::Output);
            if (identifier == "stage") return Token(TokenType::Stage);
            if (identifier == "always") return Token(TokenType::Always);
            if (identifier == "pipeline") return Token(TokenType::Pipeline);
            return Token(TokenType::Identifier, identifier);
        }

        // Handle numbers
        if (std::isdigit(currentChar)) {
            return Token(TokenType::Number, readNumber());
        }

        // Handle punctuation
        switch (currentChar) {
            case '{':
                currentPos++;
                return Token(TokenType::OpenBrace);
            case '}':
                currentPos++;
                return Token(TokenType::CloseBrace);
            case ';':
                currentPos++;
                return Token(TokenType::Semicolon);
            case '=':
                currentPos++;
                return Token(TokenType::Equal);
            case '(':
                currentPos++;
                return Token(TokenType::LParen);
            case ')':
                currentPos++;
                return Token(TokenType::RParen);
            case ',':
                currentPos++;
                return Token(TokenType::Comma);
            default:
                currentPos++;
                return Token(TokenType::Unknown, std::string(1, currentChar));
        }
    }

    return Token(TokenType::EndOfFile);
}

std::string Lexer::readIdentifier() {
    std::string result;
    while (currentPos < source.size() && (std::isalnum(source[currentPos]) || source[currentPos] == '_')) {
        result += source[currentPos++];
    }
    return result;
}

std::string Lexer::readNumber() {
    std::string result;
    while (currentPos < source.size() && std::isdigit(source[currentPos])) {
        result += source[currentPos++];
    }
    return result;
}
