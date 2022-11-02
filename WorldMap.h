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
