#include "include/Evaluator.h"

// Penalidade para soluçãoes inviáveis
constexpr double PENALTY_VALUE = 1e12;

bool Evaluator::checkRoute( std::vector<int> route, Instance instance, double routeCost){
    
    const int BASE_ID = 0; 

    double totalFlightTime = 0.0; // Para checar a autonomia (safeAuthonomy)
    double totalTime = 0.0;       // Tempo total da rota
    routeCost = 0.0;              // Custo total da rota (valor da função objetivo)
    
    // O ponto de partida é a Base (ID 0)
    int currentPointId = BASE_ID; 

    // Inicializar verificação
    for (size_t i = 0; i < route.size(); ++i) {
        int nextPointId = route[i];

        // Tempo de voo
        double distance = instance.getDistance(currentPointId, nextPointId);
        double flightTime = distance / instance.getDroneSpeed();

        totalFlightTime += flightTime;
        if (totalFlightTime > instance.getSafeAutonomy()) {
            return false; 
        }

        totalTime += flightTime;
        
        Point nextPoint = instance.getPoint(nextPointId);
        double arrivalTime = totalTime;

        // Janelas de tempo
        double waitTime = 0.0;

        if (arrivalTime > nextPoint.timeEnd) {
            return false; 
        } 
        
        if (arrivalTime < nextPoint.timeStart) {
            waitTime = nextPoint.timeStart - arrivalTime;
        }

        totalTime += waitTime;              // O drone só sai após o tempo de espera
        routeCost += flightTime + waitTime; // Adiciona o voo e o tempo de espera ao custo
        
        // Atualiza o ponto atual para a próxima iteração
        currentPointId = nextPointId;
    }

    // Tempo de retorno a base
    double distanceToBase = instance.getDistance(currentPointId, BASE_ID);
    double flightTimeToBase = distanceToBase / instance.getDroneSpeed();
    
    totalFlightTime += flightTimeToBase;
    if (totalFlightTime > instance.getSafeAutonomy()) {
        return false;
    }
    
    // Atualiza custo totoal
    routeCost += flightTimeToBase; 

    return true; 
}

void Evaluator::evaluate(Solution& solution, Instance instance){
    double totalCost = 0;
    solution.isFeasible = true; 

    // RESTRIÇÃO 1: todos os pontos foram visitados pelo menos uma vez
    std::vector<bool> visitedPoints(instance.getNumPoints(), false); 
    visitedPoints[0] = true; 

    // RESTRIÇÃO 2: valida se o custo das rotas e suportado pelo tempo de autonomia
    for (const auto& route : solution.routes) {
        double currentRouteCost = 0.0;

        // Confere viabilidade e calcula custo (Autonomia + Janela de Tempo)
        if (!checkRoute(route, instance, currentRouteCost)) {
            solution.isFeasible = false; // Se uma rota falha, a solução inteira falha.
        }
        
        totalCost += currentRouteCost;

        // Checagem de Cobertura e Duplicação (dentro do for para falhar rápido)
        for (int pointId : route) {
            if (pointId < 1 || pointId >= (int)visitedPoints.size()) {
                solution.isFeasible = false;
            } else if (visitedPoints[pointId]) {
                solution.isFeasible = false;
            }
            visitedPoints[pointId] = true;
        }
    }

    // 3: Todos os pontos foram visitados
    for (size_t i = 1; i < visitedPoints.size(); ++i) {
        if (!visitedPoints[i]) {
            solution.isFeasible = false; // Ponto não visitado!
            break;
        }
    }

    // 4. Calculo do curso (função objetivo = tempo de voo + tempo de espera)
    if (solution.isFeasible) {
        solution.objectiveValue = totalCost;
    } else {
        solution.objectiveValue = totalCost + PENALTY_VALUE;
    }
}
