#include "include/LocalSearch.h"

LocalSearch::LocalSearch(Evaluator e)
    : evaluator(e){}

Solution LocalSearch::initialSolution(Instance instance){
    // Carregar dados da instância
    int numRoutes = instance.getNumDrones();
    int numPoints = instance.getNumPoints();

    // Gerar solução
    Solution s(numRoutes);

    // Gerar vetor auxiliar
    std::vector<int> points;
    for (int i = 0; i < numPoints; i++){
        points.push_back(i+1);  
    }

    // Congigurar vetor de aleatóriedade
    std::random_device rd;
    std::mt19937 gerador(rd());

    // Embaralhar vetor auxiliar
    std::shuffle(points.begin(), points.end(), gerador);

    // Distribuir pontos nas rotas
    for (size_t i = 0; i < points.size(); ++i) {
        int droneIndex = i % numRoutes;
        s.routes[droneIndex].push_back(points[i]);
    }

    /* PRINT ROTAS
    for (int i = 0; i < numRoutes; i++){
        std::cout << "ROTA 1: [";
        for (size_t j = 0; j < s.routes[i].size(); ++j){
            std::cout << s.routes[i][j];
            if (j < s.routes[i].size() - 1) {
                std::cout << ", ";
            }
        } 
        std::cout << "]" << std::endl;
    }
    */
    
    return s;
}

void LocalSearch::swap(Solution solution, Instance instance){}

void LocalSearch::relocate(Solution solution, Instance instance){}

void LocalSearch::apply2Opt(Solution solution, Instance instance){}

void LocalSearch::random(Solution solution, Instance instance){}
