/**
 * @file LocalSearch.h
 * @author Júlia Guilhermino (juh.guilhermino03@gmail.com)
 * @brief Imblementação da heurística da busca local e já faz a avaliação da solução
 * @version 0.1
 * @date 2025-12-07
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef LOCAL_SEARCH_H
#define LOCAL_SEARCH_H

#include <vector>
#include <random>
#include <algorithm>
#include "Solution.h"
#include "Instance.h"

class LocalSearch{
    private:
        std::pair<int, int> getRandomPoint(Solution solution);

        int getRandomRouteIndex(Solution solution);

    public:
        LocalSearch() = default;

        /**
         * @brief Gera uma solução incial a partir de uma instancia
         * 
         * @param instance Dados do problema
         * @return Solution Solução encontrada
         */
        Solution initialSolution(Instance instance);

        void swap(Solution& solution, Instance instance);

        void relocate(Solution& solution, Instance instance);

        void apply2Opt(Solution& solution, Instance instance);

        void random(Solution& solution, Instance instance);

};

#endif
