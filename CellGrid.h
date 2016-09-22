//
// Created by Benjamin on 9/19/2016.
//

#ifndef BENJAMINSEELEY_ASSIGNMENT2_CELLGRID_H
#define BENJAMINSEELEY_ASSIGNMENT2_CELLGRID_H


#include <string>

class CellGrid
{
public:
    CellGrid();
    CellGrid(int height, int width, bool randomize = true, double density = 0.5);
    CellGrid(CellGrid &grid);//copy constructor
    ~CellGrid();


    //getters
    char getCell(int row, int column);
    int getHeight() const;
    int getWidth() const;

    //setters
    char setCell(int row, int column, char value);
    void setMatrix(CellGrid &grid);
    void setMatrix(char c);


    //helper methods
    int getMooresNeighborhood(int row, int column);
    std::string toString();
    void randomize(double density);



private:
    int height;
    int width;
    char*  gridMatrix;//simulated 2d array
};


#endif //BENJAMINSEELEY_ASSIGNMENT2_CELLGRID_H
