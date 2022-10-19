#ifndef CELL_H
#define CELL_H
#include "Squad.h"
#include "CellState.h"
class Cell {

private:
	CellState* state;
	Squad* occupyingForce;

public:
	virtual void setState(cellState* state) = 0;
	virtual void getState() = 0;
	void removeOccupyingForce();
	void setOccupyingForce();
};

#endif
