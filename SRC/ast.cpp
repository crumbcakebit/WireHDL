#include "ast.h"

ModuleNode::ModuleNode(const std::string& name) : name(name) {}

void ModuleNode::addInput(std::unique_ptr<ASTNode> input) {
    inputs.push_back(std::move(input));
}
