#ifndef CELL_H
#define CELL_H
#include <vector>
class MilitaryUnit;
class Cell {

protected:
    int x;
    int y;
	std::vector<MilitaryUnit*> occupyingForce;

public:
	void removeOccupyingForce(MilitaryUnit* m);
	virtual void setOccupyingForce(MilitaryUnit* m);
	std::vector<MilitaryUnit*> getOccupyingForce();
    void setCoordinates(int _x, int _y);
    int getX();
    int getY();
    virtual void add(Cell * addition) = 0;
    virtual void execute(MilitaryUnit * m){};
};

#endif

#include "Squad.h"