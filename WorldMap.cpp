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
            grid[i][j]->setCoordinates(i,j);
        }
    }
/*
    // need to add cell features
    // need to add cell features
    totalCells = worldSize*worldSize;

    numAmmoDeposit = 0.3*totalCells; //30% of all cells will be AmmoDeposits
    numFuelDeposit = 0.1*totalCells; //10% of all cells will be FuelDeposits

//    for (int i = 0; i < numAmmoDeposit; i++) {
//
//    } Need to add Decorator first
*/
}

Cell *** WorldMap::getGrid()
{
    return grid;
}