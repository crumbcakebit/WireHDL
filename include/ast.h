// ast.h
#ifndef AST_H
#define AST_H

#include <string>
#include <vector>
#include <memory>

class ASTNode {
public:
    virtual ~ASTNode() = default;
};

class InputNode : public ASTNode {
public:
    explicit InputNode(const std::string& name) : inputName(name) {}
    // Other member functions...

private:
    std::string inputName;
};

class ModuleNode : public ASTNode {
public:
    explicit ModuleNode(const std::string& name) : moduleName(name) {}

    void addInput(std::unique_ptr<ASTNode> input) { // Accepts ASTNode
        inputs.push_back(std::move(input));
    }

    // Other member functions...

private:
    std::string moduleName;
    std::vector<std::unique_ptr<ASTNode>> inputs; // Store inputs as unique_ptr to ASTNode
};

#endif // AST_H
