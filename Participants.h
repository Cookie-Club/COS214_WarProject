/**
    \file Participants.h
    \brief Defines Participants class and ActionType enum
    \authors Wian Koekemoer, Robert Officer
    \date 30/10/22
*/
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
	Action * getState();
};

#endif
