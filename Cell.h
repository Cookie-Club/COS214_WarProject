/**
 * \todo Figure out how to make setState and getState pure virtual
*/

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
	virtual void setState(CellState* state);
	virtual CellState* getState();
	void removeOccupyingForce(MilitaryUnit* m);
	void setOccupyingForce(MilitaryUnit* m);
	std::vector<MilitaryUnit*> getOccupyingForce();
};

#endif
