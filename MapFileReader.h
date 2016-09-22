//
// Created by Benjamin on 9/19/2016.
//

#ifndef BENJAMINSEELEY_ASSIGNMENT2_MAPFILEREADER_H
#define BENJAMINSEELEY_ASSIGNMENT2_MAPFILEREADER_H

#include <string>
#include "CellGrid.h"
#include <fstream>
using namespace std;

class MapFileReader
{
public:
    MapFileReader();
    MapFileReader(string filePath);
    ~MapFileReader();
    void openMapFile(string filePath);
private:
    ifstream mapFile;


};


#endif //BENJAMINSEELEY_ASSIGNMENT2_MAPFILEREADER_H
