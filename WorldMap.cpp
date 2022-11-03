#include "WorldMap.h"
#include <typeinfo>

WorldMap::WorldMap(int worldSize) {
    this->mapSize = worldSize;
    this->grid = new Cell**[worldSize];
    int totalSize = worldSize * worldSize;
    int bogCounter = 0;

    for (int i = 0; i < worldSize; i++)
    {
        this->grid[i] = new Cell*[worldSize];
        for (int j = 0; j < worldSize; j++)
        {
            int rand = std::rand() % (totalSize + 1);
            if(rand >= totalSize*0.7 && rand < totalSize * 0.9){
                factories = new AmmoDepoFactory();
                grid[i][j] = factories->createFeature();
                cout << "AmmoDepo created" << endl;
            }
            else if(rand >= totalSize*0.9 && rand < totalSize * 1.0){
                factories = new FuelDepoFactory();
                grid[i][j] = factories->createFeature();
                cout << "FuelDepo created" << endl;
            }
            else{
                grid[i][j] = new Cell();
                cout << "Plain cell created" << endl;
            }

            grid[i][j]->setCoordinates(i, j);

            
            rand = std::rand() % (totalSize + 1);
            if(rand <= (totalSize * 0.5)){
                this->grid[i][j]->add(new Bog());
                cout << "Bog discovered on Cell[" << i << "][" << j << "]" << endl;
            }
            else{
                this->grid[i][j]->add(new Flatlands());
                cout << "Flatland discovered on Cell[" << i << "][" << j << "]" << endl;
            }
        }
    }
}

Cell *** WorldMap::getGrid()
{
    return grid;
}