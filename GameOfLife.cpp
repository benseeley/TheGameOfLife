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

CellGrid GameOfLife::loadMapFile(const char* filePath)
{
    std::ifstream mapFile (filePath);
    if(mapFile.is_open())
    {
        string line;
        int height;
        int width;
        getline(mapFile, line);
        height = std::stoi(line);
        getline(mapFile, line);
        width = std::stoi(line);

        CellGrid grid(height, width);


        for(int i = 0; i < height; ++i)
        {
            getline(mapFile, line);
            for(int j = 0; j < width; ++j)
            {
                grid.setCell(i, j, line[j]);
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

    //CellGrid mapGrid = loadMapFile("map.txt");
    CellGrid *mapGrid = new CellGrid(5,5,true,0.5);

    CellSimulation simulation(*mapGrid, 0);



    do
    {
        cout << simulation.currentGeneration->toString() << endl;

        simulation.nextGeneration();
        sleep(1);

    }while (!simulation.isComplete());

    return 0;
}



