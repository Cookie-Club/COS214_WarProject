#include "WorldMap.h"

WorldMap::WorldMap(int worldSize) {

    this->mapSize = worldSize;
    this->grid = new Cell **[worldSize];

    for (int i = 0; i < worldSize; i++)
    {
        this->grid[i] = new Cell *[worldSize];
        for (int j = 0; j < worldSize; j++)
        {
            this->grid[i][j] = new Cell();
        }
    }

    // need to add cell features
}

Cell *** WorldMap::getGrid()
{
    return grid;
}