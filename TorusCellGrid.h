//
// Created by Ben on 9/22/2016.
//

#ifndef BENJAMINSEELEY_ASSIGNMENT2_TORUSCELLGRID_H
#define BENJAMINSEELEY_ASSIGNMENT2_TORUSCELLGRID_H

#include "CellGrid.h"


class TorusCellGrid : public CellGrid
{
public:
    TorusCellGrid():CellGrid(){}
    TorusCellGrid(int height, int width, bool randomize = true, double density = 0.5):CellGrid(height, width, randomize, density) {}
    TorusCellGrid(CellGrid &grid):CellGrid(grid) {}//copy constructor
    ~TorusCellGrid() {}

    char getCell(int row, int column);
};


#endif //BENJAMINSEELEY_ASSIGNMENT2_TORUSCELLGRID_H
