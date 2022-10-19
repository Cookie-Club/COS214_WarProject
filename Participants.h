#ifndef PARTICIPANTS_H
#define PARTICIPANTS_H

#include "MilitaryUnit.h"
#include "Cell.h"
#include "Action.h"


class Participants {

private:
	MilitaryUnit attribute;
	vector<MilitaryUnit*> army;
	vector<Cell> ownedTerritories;
	Action* state;
	double resources;
	vector<attackStrategy*> moveStrategies;

public:
	void armyMove();
	virtual void retreat() = 0;
};

#endif
