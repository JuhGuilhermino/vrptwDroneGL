/**
 * @file Point.h
 * @author Júlia Guilhermino (juh;guilhermino03@gmail.com)
 * @brief Definição do struct Point
 * @version 0.1
 * @date 2025-12-07
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef POINT_H
#define POINT_H

struct Point {
    int id;               //< Identificador do ponto
    double x;             //< Coordenada X
    double y;             //< Coordenada Y
    double timeStart;     //< Inicio da janela de tempo
    double timeEnd;       //< Fim da janela de tempo
};

#endif
