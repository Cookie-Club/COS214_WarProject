<<<<<<< Updated upstream
=======
/**
    \file Participants.h
    \brief Defines Participants class and ActionType enum
    \authors Wian Koekemoer, Robert Officer, Megan Hugo
    \date 30/10/22
*/
>>>>>>> Stashed changes
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
    virtual bool atBack() = 0;
    void setState(Action* state);
};

#endif
