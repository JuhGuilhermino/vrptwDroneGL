#include "include/Solution.h"

Solution::Solution(int numDrones) 
    : objectiveValue(std::numeric_limits<double>::max()), isFeasible(false) {
    routes.resize(numDrones);
}

Solution Solution::deepCopy() const {
    Solution newSolution; 
    newSolution.objectiveValue = this->objectiveValue;
    newSolution.isFeasible = this->isFeasible;

    // Cópia da matriz de rotas
    newSolution.routes = this->routes; 
    return newSolution;
}

void Solution::printSolution(){
    std::cout << "SOLUTION 1: " << isFeasible << " " << objectiveValue;
    for (size_t i = 0; i < routes.size(); ++i){
        std::cout << "  [";
        for (size_t j = 0; j < routes[i].size(); ++j){
            std::cout << routes[i][j];
            if (j < routes[i].size() - 1) {
                std::cout << " | ";
            }
        }
        std::cout << "]  ";
    }
    std::cout << "\n";
}
