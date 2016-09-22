//
// Created by Benjamin on 9/19/2016.
//

#ifndef BENJAMINSEELEY_ASSIGNMENT2_MAPFILEREADER_H
#define BENJAMINSEELEY_ASSIGNMENT2_MAPFILEREADER_H

#include <string>
#include "CellGrid.h"
#include <fstream>


class MapFileReader
{
public:
    MapFileReader();
    MapFileReader(std::string filePath);
    void openMapFile(std::string filePath);
private:
    std::ifstream mapFile;
};


#endif //BENJAMINSEELEY_ASSIGNMENT2_MAPFILEREADER_H
