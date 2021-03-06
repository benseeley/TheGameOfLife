//
// Created by Benjamin on 9/20/2016.
//

#include "CellSimulation.h"
#include "CellGrid.h"
#include "TorusCellGrid.h"
#include "MirroredCellGrid.h"
#include <iostream>

using namespace std;

CellSimulation::CellSimulation(CellGrid &startingGrid, int mode)
{
    switch(mode)
    {
        case 0:
            gridA = new CellGrid(startingGrid);
            gridB = new CellGrid(startingGrid);
            break;
        case 1:
            gridA = new TorusCellGrid(startingGrid);
            gridB = new TorusCellGrid(startingGrid);
            break;
        case 2:
            gridA = new MirroredCellGrid(startingGrid);
            gridB = new MirroredCellGrid(startingGrid);
            break;
        default:
            gridA = new CellGrid(startingGrid);
            gridB = new CellGrid(startingGrid);
            break;

    }

    boundaryMode = mode;
    currentGeneration = gridA;
    previousGeneration = gridB;

}

CellSimulation::~CellSimulation()
{
    delete gridA;
    delete gridB;
}

void CellSimulation::nextGeneration()
{
    previousGeneration = currentGeneration;//set previous generation to the current generation
    //switch currentGeneration pointer location
    if(currentGeneration == gridA)
    {
        currentGeneration = gridB;
    }
    else
    {
        currentGeneration = gridA;
    }

    //update current generation
    for (int i = 0; i < previousGeneration->getHeight(); ++i)
    {
        for (int j = 0; j < previousGeneration->getWidth(); ++j)
        {
            currentGeneration->setCell(i, j, updateCell(i, j));
        }
    }
    //cout << currentGeneration->toString() << endl;


}

char CellSimulation::updateCell(int row, int column)
{
    char cell = previousGeneration->getCell(row, column);
    int neighbors = previousGeneration->getMooresNeighborhood(row, column);
    if (neighbors <= 1)
    {
        return '-';
    }
    else if (neighbors == 2)
    {
        return cell;
    }
    else if (neighbors == 3)
    {
        return 'X';
    }
    else if (neighbors >= 4)
    {
        return '-';
    }

}

int CellSimulation::isComplete()
{
    return (previousGeneration->toString() == currentGeneration->toString());
}



