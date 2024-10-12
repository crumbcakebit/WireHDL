#include "simulator.h"
#include <iostream>

void Simulator::simulate(const ModuleNode& module) {
    simulateModule(module);
}

void Simulator::simulateModule(const ModuleNode& module) {
    std::cout << "Simulating module: " << module.getName() << std::endl;
    // Simulate all blah blah fml
}
