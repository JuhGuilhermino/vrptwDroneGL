/**
 * @file Evaluator.h
 * @author juh.guilhermino03@gmail.com (juh.guilhermino03@gmail.com)
 * @brief Impleneta as restrições para o problema do VRPTW-Drones.
 * @version 0.1
 * @date 2025-12-07
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef EVALUATOR_H
#define EVALUATOR_H

#include <iostream>
#include <numeric>
#include <algorithm>
#include "Solution.h"
#include "Instance.h"
#include "Point.h"

class Evaluator{
    private:
        /**
         * @brief Calcula o custo da rota e autonomia dos drones
         * 
         * @param route Vetor de IDs de pontos que prespesentam a rota
         * @param instance Instancia do problema
         * @param routeCost Valor obtido pela função objetivo
         * @return true Se tempo de autoonomia da rota for válido
         * @return false Caso contrário
         */
        bool checkRoute(std::vector<int> route, Instance instance, double routeCost);

    public:
        /**
         * @brief Construct a new Evaluator object
         * 
         */
        Evaluator() = default;
        
        /**
         * @brief Avalia viabilidade completa da solução
         * 
         * @param solution Solução a ser avalaida
         * @param instance Instancia do problema
         */
        void evaluate(Solution& solution, Instance instance);
};

#endif
