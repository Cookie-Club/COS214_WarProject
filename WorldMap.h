#ifndef WORLDMAP_H
#define WORLDMAP_H

#include "Cell.h"
#include "FeatureFactory.h"

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
