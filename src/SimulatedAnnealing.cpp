#include "include/SimulatedAnnealing.h"

SimulatedAnnealing::SimulatedAnnealing(double t0, double tMin, double a, int iterPerTemp)
    : tempInitial(t0), tempMin(tMin), alpha(a), interationsPerTemp(iterPerTemp){
        std::srand(std::time(0));
    }   

double SimulatedAnnealing::acceptanceProbability(double deltaE, double currentTemp){
    if (deltaE <= 0) {
        return 1.0; 
    }
    // Senão calcula: P = exp(-DeltaE / T)
    return std::exp(-deltaE / currentTemp);
}

Solution SimulatedAnnealing::run(Instance instance) {
    // Gera uma solução inicial
    Solution currentSolution = localSearch.initialSolution(instance); 
    
    // A melhor solução vista até agora é a inicial
    Solution bestSolution = currentSolution.deepCopy(); 
    double currentTemp = tempInitial;
    bestSolution.objectiveValue = currentSolution.objectiveValue;

    evaluator.evaluate(bestSolution, instance);

    // Enquanto temperatura mínima não for atingida
    /*while (currentTemp > tempMin) {
        for (int i = 0; i < interationsPerTemp; ++i) {
            Solution neighbor = currentSolution.deepCopy(); 
            localSearch.apply2Opt(neighbor, instance);
            double deltaE = neighbor.objectiveValue - currentSolution.objectiveValue;
            double R = (double)std::rand() / RAND_MAX; 
            
            // Se a vizinha for melhor OU for aceita pela probabilidade
            if (acceptanceProbability(deltaE, currentTemp) > R) {
                currentSolution = neighbor;
                if (currentSolution.objectiveValue < bestSolution.objectiveValue) {
                    bestSolution = currentSolution.deepCopy();
                }
            }
        }
        currentTemp *= alpha; 
    }*/

    return bestSolution;
}
