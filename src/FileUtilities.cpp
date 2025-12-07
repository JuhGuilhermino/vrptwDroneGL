#include "include/FileUtilities.h"

FileUtilities::FileUtilities(){}

bool FileUtilities::readData(const std::string file){
    std::ifstream input(file); 

    if (!input) {
        return false;

    } else {
        // Variáveis auxiliares
        int numInstances, numPoints, numDrones;
        double seedAutonomy, droneSpeed, x, y, timeStart, timeEnd;
        
        // Leitura da instancia
        input >> numInstances >> numPoints >> numDrones >> seedAutonomy >> droneSpeed;

        for (int i = 0; i < numInstances; i++){
            // Criar instancia
            Instance instance(numPoints, numDrones, seedAutonomy, droneSpeed);

            // Salvar pontos
            for (int j = 0; j < numPoints; j++) {
                input >> x >> y >> timeStart >> timeEnd;
                instance.loadPoint(j+1, x, y, timeStart, timeEnd);
            }
            // Armazenar instancia na matriz
            instances.push_back(instance);
        }


        for (int i = 0; i < numInstances; i++){
            instances[i].calculateDistances();
        }
        
        return true;
    }

    input.close();
}

int FileUtilities::getNumInstances(){
    return instances.size();
}

Instance FileUtilities::getInstance(int index){
    return instances[index];
}

