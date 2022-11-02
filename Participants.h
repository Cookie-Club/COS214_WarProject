/**
    \file Participants.h
    \brief Defines Participants class and ActionType enum
    \authors Wian Koekemoer, Robert Officer, Megan Hugo
    \date 30/10/22
*/
#ifndef PARTICIPANTS_H
#define PARTICIPANTS_H

#include "MilitaryUnit.h"
#include "Cell.h"
#include "Action.h"
#include "attackStrategy.h"

enum ParticipantType {allied, central};

class Participants {

protected:
	std::vector<MilitaryUnit*> army;
	std::vector<Cell*> ownedTerritories;
	Action* state;
	double resources;
	std::vector<attackStrategy*> moveStrategies;
    int totalHealthPoints;
    int totalDamage;

public:
	void armyMove();
	virtual void retreat() = 0;
    virtual std::vector<Cell> atBack() = 0;
    void setState(Action* state);
	void templateMethod();
	std::vector<MilitaryUnit*> getArmy();
	Action * getState();
    int getTotalHealthPoints();
    void setTotalHealthPoints();
    int getTotalDamage();
    void setTotalDamage();
};

#endif
