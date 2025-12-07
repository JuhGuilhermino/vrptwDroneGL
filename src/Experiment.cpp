#include "include/Experiment.h"

Experiment::Experiment(const std::string pathResults)
    : fileResults(pathResults){}

Experiment::~Experiment(){}

bool Experiment::endLoop(){
    if (currentInstance>=numInstances){
        return false;
    } else {
        return true;
    }
}

bool Experiment::validAlgorithm(const std::string a){
    if (a == "G" or a == "g"){
        algortithm = Algorithms::GA;
        return true;
    } else if (a == "S" or a == "s"){
        algortithm = Algorithms::SA;
        return true;
    } else {
        return false;
    }
}

bool Experiment::readInstances(const std::string file){
    if (fileUtilities.readData(file)){
        // Salvar nº de instâncias
        numInstances = fileUtilities.getNumInstances();

        // Salvar instancias
        for (int i = 0; i < numInstances; i++){
            instances.push_back(fileUtilities.getInstance(i));
        }

        // Atualiza estado para iniciar o loop
        numInstances = instances.size();
        currentState = States::STARTING;
        
        return true;

    } else {
        return false;
    }
}

void Experiment::runExperiemnt(){
    if (currentState == States::STARTING){
        currentInstance = 30;

    } else if (currentState == States::UPDATE_INSTANCE){
        
    } else if (currentState == States::FIND_SOLUTION){
        
    } else if (currentState == States::CALCULATE_METRICS){

    } else if (currentState == States::SAVE_SOLUTION){
        
    }
}

void Experiment::render(){
    if (currentState == States::STARTING){
        if (currentInstance == 0){
            std::cout << "|---------------------------------------------------------------------------------------------|\n";
            std::cout << "|                                    INICIAR EXPERIMENTO                                      |\n";
            std::cout << "|---------------------------------------------------------------------------------------------|\n";
            std::cout << " Nº de Instâncias: " << numInstances << "\n";
            std::cout << " Nº Repetições por Instância: " << NUM_RUNS << "\n\n";

        }
        std::cout << "|---------------------------------------------------------------------------------------------|\n";
        std::cout << "|                                         INSTANCIA " << currentInstance+1 << "                                         |\n";
        std::cout << "|---------------------------------------------------------------------------------------------|\n";
        std::cout << " DADOS\n";
        std::cout << "       > Drones (rotas): " << instances[currentInstance].getNumDrones() << "\n";
        std::cout << "       > Pontos de Inspeção: " << instances[currentInstance].getNumPoints() << "\n";
        std::cout << "       > Velocidade: " << instances[currentInstance].getDroneSpeed() << "m/s\n";
        std::cout << "       > Duração da Bateria: " << instances[currentInstance].getSafeAutonomy() << "m\n";
        std::cout << "       > Matriz de Distancias:\n";
        instances[currentInstance].printDistances();
        std::cout << "\n\n SOLUÇÕES\n";
        
    } else if (currentState == States::UPDATE_INSTANCE){
        
    } else if (currentState == States::FIND_SOLUTION){
        
    } else if (currentState == States::CALCULATE_METRICS){

    } else if (currentState == States::SAVE_SOLUTION){
        
    }
}
