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
        currentState = States::UPDATE_INSTANCE;
        
        return true;

    } else {
        return false;
    }
}

void Experiment::runExperiemnt(){
    if (currentState == States::UPDATE_INSTANCE){
        // Avança para próxima instância
        if (currentRun <= NUM_RUNS){ 
            currentRun++;
        } else {
            currentRun = 1;
            currentInstance++;
        }
        
        // Atualiza estado
        //currentState = States::FIND_SOLUTION; 


        // TESTES DOS ALGORTIMOS - LOCAL SEARCH
        Evaluator e;
        LocalSearch l(e);

        l.initialSolution(instances[currentInstance]);

        std::cout << "deu bom\n";

        currentInstance++;

    } else if (currentState == States::FIND_SOLUTION){
        
    } else if (currentState == States::CALCULATE_METRICS){

    } else if (currentState == States::SAVE_SOLUTION){
        
    }
}

void Experiment::render(){
    if (currentState == States::UPDATE_INSTANCE){
        
    } else if (currentState == States::FIND_SOLUTION){
        
    } else if (currentState == States::CALCULATE_METRICS){

    } else if (currentState == States::SAVE_SOLUTION){
        
    }
}
