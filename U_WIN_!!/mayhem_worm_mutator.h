// MAYHEM_WORM_MUTATOR.H

#ifndef MAYHEM_WORM_MUTATOR_H
#define MAYHEM_WORM_MUTATOR_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <random>
#include <chrono>
#include <ctime>
#include <filesystem>

struct ASTNode {
    std::string type;
    std::vector<ASTNode*> children;
    ASTNode(std::string t, std::vector<ASTNode*> c) : type(t), children(c) {}

    std::string getAttribute(std::string attributeName);
};

class MayhemWorm {
public:
    void deleteAST(ASTNode* root);
    void applyCodeTemplates(ASTNode* root);
    void mutateCode();
    std::string generateMutatedCode();
    void initiateMayhem();  // Declaration for the initiateMayhem function
};

#endif // MAYHEM_WORM_MUTATOR_H