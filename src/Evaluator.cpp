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

void Evaluator::evaluate(Solution solution, Instance instance){}
