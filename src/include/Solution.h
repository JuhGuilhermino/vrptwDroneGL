/**
 * @file Solution.h
 * @author Júlia Guilhermino (juh.guilhermino03@gmail.com)
 * @brief Armazena a solução (rotas) e se elas são viáveis
 * @version 0.1
 * @date 2025-12-06
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <numeric>
#include <limits>
#include <iostream>

class Solution{
    public:
        std::vector<std::vector<int>> routes; //< Rotas dos k drones
        double objectiveValue;                //< Tempo de voo + espera da solução
        bool isFeasible;                      //< Se todas as restrições são cumpridas;

        /**
         * @brief Constroi um objeto solução e o declara como inválido e com o VFO com maior valor possível 
         * 
         */
        Solution() : objectiveValue(std::numeric_limits<double>::max()), isFeasible(false) {}
    
        /**
         * @brief Construtor que inicializa rotas para k drones
         * 
         * @param numDrones Nº de drones 
         */
        Solution(int numDrones);

        /**
         * @brief Cópia profunda da solução atual sem percas.
         * 
         * @return Solution 
         */
        Solution deepCopy() const;

        void printSolution();
};

#endif