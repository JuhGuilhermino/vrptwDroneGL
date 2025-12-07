/**
 * @file SimulatedAnnealing.h
 * @author Júlia Guilhermino (juh.guilhermino03@gmail.com)
 * @brief Implementaçãa da meta-heurística Simulated Annealing
 * @version 0.1
 * @date 2025-12-06
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef SIMULATED_ANNEALING_H
#define SIMULARED_ANNEALING_H

#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "Instance.h"
#include "Solution.h"
#include "Evaluator.h"
#include "LocalSearch.h"

class SimulatedAnnealing{
    private:
        LocalSearch localSearch; //< Operadores de vizinhança
        Evaluator evaluator;
        double tempInitial;      // T0 = temperatura incial
        double tempMin;          // T_min = temperatura mínima
        double alpha;            // Fator de resfriamento
        int interationsPerTemp;  // Nº de interações por nível de temperatura

        /**
         * @brief Probabilidade de aceitar pior solução
         * 
         * @param deltaE Difenreça de energia, no caso diferença da função objetivo da solução atual e visinha
         * @param currentTemp 
         * @return double 
         */
        double acceptanceProbability(double deltaE, double currentTemp);

    public:
        /**
         * @brief Construct a new Simulated Annealing object
         * 
         * @param t0 temperatura inicial
         * @param tMin temperatura minima
         * @param alpha fator de resfriamento
         * @param iterPerTemp nº de interações por nível
         */
        SimulatedAnnealing( double t0, double tMin, double a, int iterPerTemp);

        /**
         * @brief executa SA
         * @param instance Instância do problema
         * @return melhor solução encontrada
         */
        Solution run(Instance instance);
        
};

#endif
