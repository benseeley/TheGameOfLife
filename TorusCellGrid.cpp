//
// Created by Ben on 9/22/2016.
//

#include "TorusCellGrid.h"
#include "CellGrid.h"

char TorusCellGrid::getCell(int row, int column)
{
    int tempRow;
    int tempColumn;
    if(row == -1)
    {
        tempRow = height - 1;
    }
    else if(row == height)
    {
        tempRow = 0;
    }
    else
    {
        tempRow = row;
    }
    if(column == -1)
    {
        tempColumn = width - 1;
    }
    else if(column == width)
    {
        tempColumn = 0;
    }
    else
    {
        tempColumn = column;
    }
    return gridMatrix[tempRow * width + tempColumn];
}