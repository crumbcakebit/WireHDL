// matrix ahh simulation

#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "ast.h"

class Simulator {
public:
    void simulate(const ModuleNode& module);

private:
    void simulateModule(const ModuleNode& module);
};

#endif
