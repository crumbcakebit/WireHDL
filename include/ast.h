//astdeeznuts

#ifndef AST_H
#define AST_H

#include <string>
#include <vector>
#include <memory>

class ASTNode {
public:
    virtual ~ASTNode() = default;
};

class ModuleNode : public ASTNode {
public:
    ModuleNode(const std::string& name);
    void addInput(std::unique_ptr<ASTNode> input);

private:
    std::string name;
    std::vector<std::unique_ptr<ASTNode>> inputs;
};

#endif
