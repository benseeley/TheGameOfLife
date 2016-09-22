//
// Created by Benjamin on 9/19/2016.
//

#include "MapFileReader.h"

MapFileReader::MapFileReader()
{

}

MapFileReader::MapFileReader(std::string filePath)
{
    mapFile.open(filePath);
}

void MapFileReader::openMapFile(std::string filePath)
{
    mapFile.open(filePath);

}

MapFileReader::~MapFileReader()
{

}
