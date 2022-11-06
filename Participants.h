/**
    \file Participants.h
    \class Participants
    \brief Defines Participants class and ActionType enum
    \authors Wian Koekemoer, Robert Officer, Megan Hugo,Kaitlyn Sookdhew
    \date 30/10/22
    \todo Function Documentation
*/
#ifndef PARTICIPANTS_H
#define PARTICIPANTS_H

#include "Cell.h"
#include "Action.h"
#include "attackStrategy.h"
#include <string>
#include "MilitaryUnit.h"
class MilitaryUnit;
class Participants {

protected:
    std::vector<MilitaryUnit*> army;
    std::vector<Cell*> ownedTerritories;
    //Action* state;
    double resources;
    //vector<attackStrategy*> moveStrategies;
    int totalHealthPoints;
    int totalDamage;
    std::string name;
    WorldMap* map;
    Participant participant;

public:
    Participants();
    virtual ~Participants(){};
    virtual void armyMove() = 0;
    virtual void retreat(std::vector<Cell*> cells)=0;
    std::vector<Cell*> * getOwnedTerritories();
    virtual std::vector<Cell*> atBack() = 0;
    void retreatParticipants();
    std::vector<MilitaryUnit*>* getArmy();
    int getTotalHealthPoints();
    void setTotalHealthPoints(int hp);
    int getTotalDamage();
    void setTotalDamage();
    std::string getName();
    Participant getParticipant() ;
    WorldMap *getMap();
    void setMap(WorldMap *map);
    void removeMilitaryUnit(MilitaryUnit* m);

};

#endif
