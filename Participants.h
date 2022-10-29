#ifndef PARTICIPANTS_H
#define PARTICIPANTS_H

#include "MilitaryUnit.h"
#include "Cell.h"
#include "Action.h"
#include "attackStrategy.h"

class Participants {

protected:
	std::vector<MilitaryUnit*> army;
	std::vector<Cell> ownedTerritories;
	Action* state;
	double resources;
	std::vector<attackStrategy*> moveStrategies;

public:
	void armyMove();
	virtual void retreat() = 0;
    void setState(Action* state);
	void templateMethod();
	std::vector<MilitaryUnit*> getArmy();
};

#endif
