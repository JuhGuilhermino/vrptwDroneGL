#include "include/Instance.h"

Instance::Instance(int p, int d, double t, double v)
    : numPoints(p), numDrones(d), safeAutonomy(t), droneSpeed (v){
        points.push_back(base);
    };

void Instance::loadPoint(int id, double x, double y, double timeStart, double timeEnd){
    Point p {id, x, y, timeStart, timeEnd};
    points.push_back(p);
}

void Instance::calculateDistances(){
    // Percorre todos os pares de pontos (i, j)
    for (int i = 0; i <= numPoints; ++i) {
        // Vetor auxiliar
        std::vector<double> line;

        for (int j = 0; j <= numPoints; ++j) {
            if (i==j) {
                line.push_back(0);
            } else {
                // Diferença de coordenadas
                double dx = points[i].x - points[j].x;
                double dy = points[i].y - points[j].y;

                // Distancia Euclidiana
                double d = std::sqrt(std::pow(dx, 2) + std::pow(dy, 2));

                // Armazenar distancia no vetor auxiliar
                line.push_back(d);
            }
        }

        distance.push_back(line);
        line.clear();
    }

   
    for (int i = 0; i <= numPoints; i++){
            for (int j = 0; j <= numPoints; j++){
            std::cout << distance[i][j] << "/";
        }
        std::cout << "\n";
    }
    
}