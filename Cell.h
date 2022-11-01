#ifndef CELL_H
#define CELL_H
#include "Squad.h"
#include "CellState.h"
#include "MilitaryUnit.h"
#include <vector>

class Cell {

private:
	CellState* state;
	std::vector<MilitaryUnit*> occupyingForce;

public:
	virtual void setState(CellState* state){this->state = state;};
	virtual CellState* getState(){return this->state;};
	void removeOccupyingForce(MilitaryUnit* m);
	void setOccupyingForce(MilitaryUnit* m);
	std::vector<MilitaryUnit*> getOccupyingForce();
};

#endif
