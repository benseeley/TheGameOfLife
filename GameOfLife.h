//
// Created by Benjamin on 9/19/2016.
//

#ifndef BENJAMINSEELEY_ASSIGNMENT2_GAMEOFLIFE_H
#define BENJAMINSEELEY_ASSIGNMENT2_GAMEOFLIFE_H


#include <string>
#include "CellGrid.h"
#include "CellSimulation.h"

class GameOfLife
{
public:
    GameOfLife();
    ~GameOfLife();
    CellGrid* loadMapFile(const char* filePath);
    int run();

    CellSimulation *simulation;



};


#endif //BENJAMINSEELEY_ASSIGNMENT2_GAMEOFLIFE_H
