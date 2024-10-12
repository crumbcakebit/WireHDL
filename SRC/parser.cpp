// parser.cpp
#include "parser.h"
#include <stdexcept>

Parser::Parser(Lexer& lex) : lexer(lex), currentToken(lexer.getNextToken()) {}

std::unique_ptr<ASTNode> Parser::parse() {
    if (currentToken.getType() == TokenType::Module) {
        return parseModule();
    }
    // Extra parse logic can be added here
    return nullptr;
}

void Parser::advanceToken() {
    currentToken = lexer.getNextToken();
}

std::unique_ptr<ASTNode> Parser::parseModule() {
    advanceToken(); // skip module token
    std::string moduleName = currentToken.getValue();
    advanceToken(); // skip module name

    auto moduleNode = std::make_unique<ModuleNode>(moduleName);
    expectToken(TokenType::OpenBrace);

    // Parse input/output
    while (currentToken.getType() != TokenType::CloseBrace) {
        if (currentToken.getType() == TokenType::Input) {
            auto inputNode = parseInput(); // This returns std::unique_ptr<ASTNode>
            moduleNode->addInput(std::move(inputNode)); // Correct type now
        }
        advanceToken();
    }

    expectToken(TokenType::CloseBrace);
    return moduleNode;
}

void Parser::expectToken(TokenType type) {
    if (currentToken.getType() != type) {
        throw std::runtime_error("Unexpected token");
    }
    advanceToken();
}

std::unique_ptr<ASTNode> Parser::parseInput() {
    advanceToken(); // Skip "input" token
    std::string inputName = currentToken.getValue();
    advanceToken(); // Skip input name

    expectToken(TokenType::Semicolon); // Expect a semicolon after input declaration
    return std::make_unique<InputNode>(inputName); // This returns std::unique_ptr<InputNode>
}
