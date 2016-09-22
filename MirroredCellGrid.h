//
// Created by Ben on 9/22/2016.
//

#ifndef BENJAMINSEELEY_ASSIGNMENT2_MIRROREDCELLGRID_H
#define BENJAMINSEELEY_ASSIGNMENT2_MIRROREDCELLGRID_H

#include "CellGrid.h"

class MirroredCellGrid : public CellGrid
{
public:
    MirroredCellGrid():CellGrid() {}
    MirroredCellGrid(int height, int width, bool randomize = true, double density = 0.5):CellGrid(height, width, randomize, density) {}//overloaded constructor
    MirroredCellGrid(CellGrid &grid):CellGrid(grid) {}//copy constructor
    ~MirroredCellGrid() {}

    char getCell(int row, int column);
};

#endif //BENJAMINSEELEY_ASSIGNMENT2_MIRROREDCELLGRID_H
