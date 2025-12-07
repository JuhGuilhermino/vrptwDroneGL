/**
 * @file Experiment.h
 * @author juh.guilhermino03@gmailcom
 * @brief Implementa a arquitetura GameLoop para gerenciar o experimento.
 * @version 0.1
 * @date 2025-12-06
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef EXPERIMENT_H
#define EXPERIMENT_H

#include <vector>
#include <string>
#include <iostream>
#include <chrono>
#include "FileUtilities.h"
#include "Instance.h"
#include "Solution.h"
#include "LocalSearch.h"
#include "Evaluator.h"
#include "SimulatedAnnealing.h"
//#include "GeneticAlgorithm.h"

class Experiment {
    private:
        enum Algorithms {
            SA,
            GA
        };

        enum States {
            STARTING,
            UPDATE_INSTANCE,
            FIND_SOLUTION,
            CALCULATE_METRICS,
            SAVE_SOLUTION
        };

        const int NUM_RUNS = 30;

        int algortithm;
        int currentState;
        int numInstances;
        int loopControl = 0;
        int currentInstance = 0;
        int currentRun = 0;
        std::string fileResults;
        std::vector<Instance> instances;
        std::vector<Solution> solutions;
        std::vector<std::vector<Solution>> soluctionsPerInstance;  //< Conjunto de soluções para cada execução
        FileUtilities fileUtilities;

    public:
        Experiment(const std::string pathResults);
        
        ~Experiment();

        bool endLoop();

        bool validAlgorithm(const std::string a);

        bool readInstances(const std::string file);

        void runExperiemnt();

        void render();
    };

#endif
