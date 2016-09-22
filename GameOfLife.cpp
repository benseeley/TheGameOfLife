//
// Created by Benjamin on 9/19/2016.
//

#include <iostream>
#include "GameOfLife.h"
#include "CellGrid.h"
#include <fstream>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

GameOfLife::GameOfLife()
{

}

GameOfLife::~GameOfLife()
{

}

CellGrid* GameOfLife::loadMapFile(const char* filePath)
{
    std::ifstream mapFile (filePath);
    if(mapFile.is_open())
    {
        string line;
        int height;
        int width;
        getline(mapFile, line);
        height = std::stoi(line);
        //cout << height << endl;
        getline(mapFile, line);
        width = std::stoi(line);

        CellGrid* grid = new CellGrid(height, width);


        for(int i = 0; i < height; ++i)
        {
            getline(mapFile, line);
            for(int j = 0; j < width; ++j)
            {
                grid->setCell(i, j, line[j]);
            }
        }
        return grid;

    } else{
        cout << "Error: File not found" << endl;
        exit(1);
    }

}

int GameOfLife::run()
{

   // CellGrid *mapGrid = loadMapFile("map.txt");
    CellGrid *mapGrid = new CellGrid(5,5,true,0.5);

    CellSimulation *simulation = new CellSimulation(*mapGrid, 0);

    cout<< "test1" << endl;
    cout << simulation->currentGeneration->toString() << endl;
    cout << "neighbors " << simulation->currentGeneration->getCell(0,1) << endl;
    cout << "neighbors " << simulation->currentGeneration->getMooresNeighborhood(0,1) << endl;



    do
    {
        simulation->nextGeneration();
        cout << simulation->currentGeneration->toString() << endl;
        cout << endl;

    }while (!simulation->isComplete());

    cout << "test6" << endl;

    delete simulation;
    return 0;
}

