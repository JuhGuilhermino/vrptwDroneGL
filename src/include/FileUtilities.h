/**
 * @file FileUtilities.h
 * @author Júlia Guilhermino (juh.guilhermino03@gmail.com.com)
 * @brief Leitura das instâncias e escrita dos resultados
 * @version 0.1
 * @date 2025-12-06
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef FILE_UTILITIES_H
#define FILE_UTILITIES_H

#include <fstream>
#include <string>
#include <vector>
#include "Instance.h"
#include <iostream>

class FileUtilities{
    private:
        std::vector<Instance> instances;

    public:
        FileUtilities();

        bool readData(const std::string file);

        int getNumInstances();
        
        Instance getInstance(int index);

};


#endif
