/**
    \file WorldMap.h
    \class WorldMap
    \brief Creates the Map for the simulation
    \details Creates a 2D array of Cells. Each Cell is decorated with the type of cell it is and features that it has
    \author Megan Hugo
    \todo Function Documentation
*/
#ifndef WORLDMAP_H
#define WORLDMAP_H

#include <cstdlib>

class FeatureFactory;

class Cell;
class WorldMap {
protected:
	Cell ***grid;
    int mapSize;
	FeatureFactory* factories;

public:
	WorldMap(int worldSize);
	Cell *** getGrid();
    int getSize();
    Cell * getCell(int x, int y);
};

#endif

