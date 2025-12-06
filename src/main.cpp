/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-12-06
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <iostream>
#include "include/Experiment.h"

void print_usage() {
    std::cerr << "Usage: ./main [algorithm] <output_file_name> <input_image_file>\n";
    std::cerr << "Where [algorithm] can be:\n";
    std::cerr << '\t' << "g       Genetic Algorithm\n";
    std::cerr << '\t' << "s       Simulated Annealing\n";
}

int main(int argc, char* argv[]) {
    // Verifica a quantidade de argumentos
    if (argc != 4) {
        print_usage();
        return 0; // Saída antecipada
    }

    // Inicializa o experimento
    Experiment experiment(argv[2]);

    // Verifica se o algortimo informado é válido
    if (!experiment.validAlgorithm(argv[1])) {
        std::cerr << "ERRO: Algoritmo inválido!\n";
        print_usage();
        return 0; // Saída antecipada
    }

    // Realiza leitura das instâncias
    if (!experiment.readInstances(argv[3])) {
        std::cerr << "ERRO: Não foi possivel ler o arquivo '" << argv[3] << "'\n";
        print_usage();
        return 0; // Saída antecipada
    }

    // Se verificações forem válidas, executa experimento
    while (experiment.endLoop()) {
        experiment.render();
        experiment.runExperiemnt();
    }

    return 0;
}
