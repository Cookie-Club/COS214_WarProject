/**
    \file WorldMap.h
    \brief Creates the Map for the simulation
    \details Creates a 2D array of Cells. Each Cell is decorated with the type of cell it is and features that it has
    \author Megan Hugo
*/
#ifndef WORLDMAP_H
#define WORLDMAP_H

#include "AmmoDepoFactory.h"
#include "FuelDepoFactory.h"
#include "Bog.h"
#include "Flatlands.h"

class WorldMap {

protected:
	Cell ***grid;
    int mapSize;
	FeatureFactory* factories;

public:
	WorldMap(int worldSize);
	Cell *** getGrid();
};

#endif
