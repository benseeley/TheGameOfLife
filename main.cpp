#include <iostream>
#include "GameOfLife.h"
#include "CellGrid.h"


using namespace std;
int main(int argc, char** argv) {

    GameOfLife game;
    cout<< "test" << endl;
    game.run();



    /*cout << "test" << endl;

    GameOfLife gameOfLife;
    string filePath = "map.txt";
    CellGrid *grid = gameOfLife.loadMapFile(filePath.c_str());



    cout << grid->toString() << endl;*/



    cout << "complete" << endl;
    return 0;
}