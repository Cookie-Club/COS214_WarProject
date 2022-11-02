#include "WorldMap.h"

WorldMap::WorldMap(int worldSize) {

    this->mapSize = worldSize;
    this->grid = new Cell **[worldSize];
    int totalSize = worldSize * worldSize;

    for (int i = 0; i < worldSize; i++)
    {
        this->grid[i] = new Cell *[worldSize];
        for (int j = 0; j < worldSize; j++)
        {
            int rand = std::rand() % (totalSize + 1);

            if(rand >= totalSize*0.7 && rand < totalSize * 0.9){
                factories = new AmmoDepoFactory();
                this->grid[i][j] = factories->createFeature();
            }
            else if(rand >= totalSize*0.9 && rand < totalSize * 1.0){
                factories = new FuelDepoFactory();
                this->grid[i][j] = factories->createFeature();
            }
            
            rand = std::rand() % (totalSize + 1);

            if(rand <= totalSize * 0.5){
                this->grid[i][j]->add(new Bog());
            }
            else{
                this->grid[i][j]->:add(new Flatlands());
            }
            grid[i][j]->setCoordinates(i,j);
        }
    }
}

Cell *** WorldMap::getGrid()
{
    return grid;
}