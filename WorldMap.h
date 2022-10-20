#ifndef WORLDMAP_H
#define WORLDMAP_H

#include "Cell.h"
#include "FeatureFactory.h"

class WorldMap {

private:
	Cell grid[][];
	FeatureFactory* factories;

public:
	WorldMap(int worldSize);
};

#endif
