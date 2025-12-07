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