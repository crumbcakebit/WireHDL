#include "parser.h"

Parser::Parser(Lexer& lex) : lexer(lex), currentToken(lexer.getNextToken()) {}

std::unique_ptr<ASTNode> Parser::parse() {
    if (currentToken.getType() == TokenType::Module) {
        return parseModule();
    }
    // xtra parse logic
    return nullptr;
}

void Parser::advanceToken() {
    currentToken = lexer.getNextToken();
}

std::unique_ptr<ASTNode> Parser::parseModule() {
    advanceToken(); // skip module
    std::string moduleName = currentToken.getValue();
    advanceToken(); // skip module name

    auto moduleNode = std::make_unique<ModuleNode>(moduleName);
    expectToken(TokenType::OpenBrace);

    // Parse input/output
    while (currentToken.getType() != TokenType::CloseBrace) {
        if (currentToken.getType() == TokenType::Input) {
            auto inputNode = parseInput();
            moduleNode->addInput(std::move(inputNode));
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
