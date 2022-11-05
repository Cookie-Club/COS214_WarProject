#include "WorldMap.h"

#include "AmmoDepoFactory.h"
#include "FuelDepoFactory.h"
#include "Bog.h"
#include "Flatlands.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

WorldMap::WorldMap(int worldSize) {
    this->mapSize = worldSize;
    this->grid = new Cell**[worldSize];
    int totalSize = worldSize * worldSize;
    int bogCounter = 0;

    srand(time(NULL));
    for (int i = 0; i < worldSize; i++)
    {
        this->grid[i] = new Cell*[worldSize];
        for (int j = 0; j < worldSize; j++)
        {
            std::cout<< "Cell [" << i << "][" << j << "]: ";
            int rand = std::rand() % (totalSize + 1);

            if(rand >= totalSize*0.7 && rand < totalSize * 0.9){
                factories = new AmmoDepoFactory();
                grid[i][j] = factories->createFeature();
                cout << "AmmoDepo, ";
            }
            else if(rand >= totalSize*0.9 && rand < totalSize * 1.0){
                factories = new FuelDepoFactory();
                grid[i][j] = factories->createFeature();
                cout << "FuelDepo, ";
            }
            else{
                grid[i][j] = new Cell();
                cout << "Nothing, ";
            }

            grid[i][j]->setCoordinates(i, j);

            //Replaced cout commands in the if statements below with
            // the creation messages in the cell constructors that are called
            rand = std::rand() % (totalSize + 1);
            if(rand <= (totalSize * 0.25)){
                this->grid[i][j]->add(new Bog());
            }
            else if(rand > (totalSize * 0.25) && rand <= (totalSize * 0.5)){
                this->grid[i][j]->add(new Flatlands());
            }
            else{
                this->grid[i][j]->add(new Cell());
            }
        }
    }
}

Cell *** WorldMap::getGrid()
{
    return grid;
}

int WorldMap::getSize() {
    return this->mapSize;
}

Cell * WorldMap::getCell(int x, int y){
    return grid[x][y];
}