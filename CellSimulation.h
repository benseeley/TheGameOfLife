//
// Created by Benjamin on 9/20/2016.
//

#ifndef BENJAMINSEELEY_ASSIGNMENT2_CELLSIMULATION_H
#define BENJAMINSEELEY_ASSIGNMENT2_CELLSIMULATION_H

#include "CellGrid.h"

class CellSimulation
{
public:

    CellSimulation(CellGrid &startingGrid, int mode);
    ~CellSimulation();
    void nextGeneration();
    char updateCell(int row, int column);


    CellGrid *currentGeneration;
    CellGrid *previousGeneration;

    int isComplete();

private:
    CellGrid *gridA;
    CellGrid *gridB;
    int boundaryMode;


};


#endif //BENJAMINSEELEY_ASSIGNMENT2_CELLSIMULATION_H
