//
// Created by Benjamin on 9/19/2016.
//
#define neighbors

#include "CellGrid.h"
#include <cctype>
#include <iostream>
#include <sstream>
using namespace std;

CellGrid::CellGrid()
{
    height = 10;
    width = 10;
    gridMatrix = new char[height * width];
    for (int i = 0;i < (height * width); ++i)
    {
        gridMatrix[i] = '-';
    }
}

CellGrid::CellGrid(int height, int width, bool randomize, double density)
{
    CellGrid::height = height;
    CellGrid::width = width;
    gridMatrix = new char[height * width];
    if(randomize)
    {
        CellGrid::randomize(density);
    }
    else
    {
        setMatrix('-');
    }


}

CellGrid::CellGrid(CellGrid &grid)
{
    height = grid.getHeight();
    width = grid.getWidth();
    gridMatrix = new char[height * width];
    setMatrix(grid);

}


CellGrid::~CellGrid()
{
    delete gridMatrix;
}

char CellGrid::getCell(int row, int column)
{
    if(row >= height || column >= width || row < 0 || column < 0)
    {
        return '-';
    }
    else
    {
        return gridMatrix[row * width + column];
    }
}

int CellGrid::getMooresNeighborhood(int row, int column)
{
    int temp = 0;
    for(int i = -1; i <= 1; ++i)
    {
        for(int j = -1; j <= 1; ++j)
        {
            if(!(i == 0 && j == 0))
            {
                //cout << getCell(row + i, column + j);
                if(toupper(getCell(row + i, column + j)) == 'X')
                {
                    ++temp;
                }
            }
            else
            {
                //cout << " ";
            }
        }
        //cout << endl;
    }

    return temp;
}

char CellGrid::setCell(int row, int column, char value)
{
    gridMatrix[row * width + column] = value;
}

int CellGrid::getHeight() const
{
    return height;
}

int CellGrid::getWidth() const
{
    return width;
}

string CellGrid::toString()
{
    ostringstream oString;
    for(int i = 0; i < getHeight(); ++i)
    {
        for(int j = 0; j < getWidth(); ++j)
        {
            oString << getCell(i, j);
        }
        oString << endl;
    }
    return oString.str();
}

void CellGrid::setMatrix(CellGrid &grid)
{
    if(getHeight() == grid.getHeight() && getWidth() == grid.getWidth())
    {
        for(int i = 0;i < getHeight();++i)
        {
            for (int j = 0; j < getWidth(); ++j)
            {
                setCell(i, j, grid.getCell(i, j));
            }
        }
    }
    else
    {
        cout << "Error: Grids are not the same size" << endl;
        exit(1);
    }
}

void CellGrid::randomize(double density)
{
    for(int i = 0;i < getHeight();++i)
    {
        for (int j = 0; j < getWidth(); ++j)
        {
            if((double)rand()/RAND_MAX < density)
            {
                setCell(i, j, 'X');
            }
            else
            {
                setCell(i,j, '-');
            }
        }
    }
}

void CellGrid::setMatrix(char c)
{
    for(int i = 0;i < getHeight();++i)
    {
        for (int j = 0; j < getWidth(); ++j)
        {
            setCell(i, j, c);
        }
    }
}
