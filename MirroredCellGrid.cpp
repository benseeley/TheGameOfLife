//
// Created by Ben on 9/22/2016.
//

#include "MirroredCellGrid.h"
#include "CellGrid.h"



char MirroredCellGrid::getCell(int row, int column)
{
    int tempRow;
    int tempColumn;
    if(row == -1)
    {
        tempRow = 0;
    }
    else if(row == height)
    {
        tempRow = height-1;
    }
    else
    {
        tempRow = row;
    }

    if(column == -1)
    {
        tempColumn = 0;
    }
    else if(column == width)
    {
        tempColumn = width-1;
    }
    else
    {
        tempColumn = column;
    }
    return gridMatrix[tempRow * width + tempColumn];
}
