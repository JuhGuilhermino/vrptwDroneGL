/**
 * @file Instance.h
 * @author Júlia Guilhermino (juh.guilhermino03@gmail.com)
 * @brief Definição da classe Instance.
 * @version 0.1
 * @date 2025-12-05
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef INSTANCE_H
#define INSTANCE_H

#include <vector>
#include <math.h>
#include <iostream>
#include "Point.h"

/**
 * @brief Classe que armazena pontos de uma instância.
 */
class Instance{
    private:
        std::vector<Point> points;                  //< Conjunto de pontos
        int numPoints;                              //< Nº de pontos de inspeção
        int numDrones;                              //< Nº de drones utilizados
        double safeAutonomy;                        //< Autômia máxima de bateria por voo
        double droneSpeed;                          //< Velocidade de voo
        std::vector<std::vector<double>> distance;  //< Distância entre os pontos
        Point base { 0, 50, 50, 0, 0};              //< Definição da base [50.50]
        
    public:
        /**
         * @brief Construct a new Instance object
         * 
         * @param p Nº de pontos
         * @param d Nº de drones
         * @param t Tempo de autonomia da bateria
         * @param v Velocidade de voo do drone
         */
        Instance(int p, int d, double t, double v);

        /**
         * @brief Carrega os pontos da instancia
         * 
         * @param id identificador do ponto
         * @param x coordenada vertical
         * @param y coordenada horizontal
         * @param timeStart janela de tempo inicial
         * @param timeEnd janela de tempo final
         */
        void loadPoint(int id, double x, double y, double timeStart, double timeEnd);

        /**
         * @brief Calcula e preenche a matriz de distâncias usando a distância Euclidiana.
         */
        void calculateDistances();

        int getNumPoints();

        int getNumDrones();

        double getSafeAutonomy();

        double getDroneSpeed();

        Point getPoint(int index);

        double getDistance(int startPoint, int endPoint);

        void printDistances();
};

#endif