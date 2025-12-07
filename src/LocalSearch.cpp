#include "include/LocalSearch.h"

std::pair<int, int> LocalSearch::getRandomPoint(Solution solution){
    // Escolhe uma rota aleatória
    int numRoutes = solution.routes.size();
    int routeIndex = std::rand() % numRoutes;

    // Escolhe um ponto aleatório da rota escolhida
    int numPoints = solution.routes[routeIndex].size();
    int pointIndex = std::rand() % numPoints;

    return {routeIndex, pointIndex};
}

int LocalSearch::getRandomRouteIndex(Solution solution){
    int numRoutes = solution.routes.size();
    int routeIndex = std::rand() % numRoutes;

    return routeIndex;
}

Solution LocalSearch::initialSolution(Instance instance){
    // Carregar dados da instância
    int numRoutes = instance.getNumDrones();
    int numPoints = instance.getNumPoints();

    // Gerar solução
    Solution solution(numRoutes);

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
        solution.routes[droneIndex].push_back(points[i]);
    }
    
    return solution;
}

void LocalSearch::swap(Solution& solution, Instance instance){
    // Se não houver 2 pontos na solução atual não muda nada
    if (solution.routes.empty() || (solution.routes[0].empty() && solution.routes.size() == 1)) return;

    // Seleciona dois pontos aleatórios
    std::pair<int, int> pointA = getRandomPoint(solution);
    std::pair<int, int> pointB = getRandomPoint(solution);

    // Verifica se são pontos diferentes
    while (pointA.first == pointB.first && pointA.second == pointB.second) {
        pointB = getRandomPoint(solution);
    }

    // Realizar troca
    std::vector<int>& routeA = solution.routes[pointA.first];
    std::vector<int>& routeB = solution.routes[pointB.first];
    std::swap(routeA[pointA.second], routeB[pointB.second]);
}

void LocalSearch::relocate(Solution& solution, Instance instance){
    // Se não houver 2 pontos na solução atual não muda nada
    if (solution.routes.empty() || (solution.routes[0].empty() && solution.routes.size() == 1)) return;

    // Seleciona ponto de origem
    std::pair<int, int> pointA = getRandomPoint(solution);
    int routeIndexA = pointA.first; 
    int pointIndexA = pointA.second; 
    std::vector<int>& routeA = solution.routes[routeIndexA];

    // Guarda ponto que será movido
    int pointToMove = routeA[pointIndexA];

    // Encontra rota de destino
    int routeIndexB = getRandomRouteIndex(solution);
    std::vector<int>& routeB = solution.routes[routeIndexB];
    int pointIndexB = std::rand() % (routeB.size() + 1);

    // Executa troca
    routeA.erase(routeA.begin() + pointIndexA);
    if (routeIndexA == routeIndexB && pointIndexB > pointIndexA) {
        pointIndexB--;
    }
    routeB.insert(routeB.begin() + pointIndexB, pointToMove);
}

void LocalSearch::apply2Opt(Solution& solution, Instance instance){
    // Seleciona uma rota
    std::vector<int>* routePtr = nullptr;
    int maxAttempts = 10;
    
    // Verifica se a rota possui pelo menos 3 pontos
    for (int attempt = 0; attempt < maxAttempts; ++attempt) {
        int routeIndex = getRandomRouteIndex(solution);
        if (solution.routes[routeIndex].size() >= 3) {
            routePtr = &solution.routes[routeIndex];
            break;
        }
    }
    if (routePtr == nullptr) {
        return; 
    }
    
    // Aplicação do 2-Opt
    std::vector<int>& route = *routePtr;
    int routeSize = route.size();

    int i = std::rand() % (routeSize - 1); 
    int j = std::rand() % (routeSize);
    
    // Garante que i < j
    if (i >= j) {
        std::swap(i, j);
    }
    
    // Garante que o segmento tenha pelo menos 2 pontos
    if (j == i) return;

    // Aplica a inversão
    std::reverse(route.begin() + i, route.begin() + j + 1);
}

void LocalSearch::random(Solution& solution, Instance instance){
    int moveType = std::rand() % 2; // 0 para Swap, 1 para Relocate

    switch (moveType) {
        case 0:
            swap(solution, instance);
            break;
        case 1:
            relocate(solution, instance);
            break;
        case 2:
            apply2Opt(solution, instance);
            break;
    }    
}
