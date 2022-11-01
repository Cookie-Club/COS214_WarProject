#ifndef CELL_H
#define CELL_H
#include <vector>
class MilitaryUnit;
class Cell {

private:
	std::vector<MilitaryUnit*> occupyingForce;

public:
	void removeOccupyingForce(MilitaryUnit* m);
	void setOccupyingForce(MilitaryUnit* m);
	std::vector<MilitaryUnit*> getOccupyingForce();
};

#endif

#include "Squad.h"