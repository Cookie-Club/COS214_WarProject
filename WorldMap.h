/**
    \file WorldMap.h
    \brief Creates the Map for the simulation
    \details Creates a 2D array of Cells. Each Cell is decorated with the type of cell it is and features that it has
    \author Megan Hugo
*/

#ifndef WORLDMAP_H
#define WORLDMAP_H

#include "Cell.h"
#include "FeatureFactory.h"
#include "AmmoDepoFactory.h"

class WorldMap {

private:
	Cell ***grid;
    int mapSize;
	FeatureFactory* factories; //why is there a factories pointer?

public:
	WorldMap(int worldSize);
};

#endif
