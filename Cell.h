#ifndef CELL_H
#define CELL_H
#include <vector>
class MilitaryUnit;
class Cell {

private:
    int x;
    int y;
    int mapSize;
	std::vector<MilitaryUnit*> occupyingForce;

public:
	void removeOccupyingForce(MilitaryUnit* m);
	void setOccupyingForce(MilitaryUnit* m);
	std::vector<MilitaryUnit*> getOccupyingForce();
    void setCoordinates(int _x, int _y);
    int getX();
    int getY();
    void setMapSize(int _size);
    int getMapSize();
};

#endif

#include "Squad.h"