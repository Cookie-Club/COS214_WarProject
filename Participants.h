/**
    \file Participants.h
    \class Participants
    \brief Defines Participants class and ActionType enum
    \defgroup Participants
    \authors Wian Koekemoer, Robert Officer, Megan Hugo,Kaitlyn Sookdhew
    \date 30/10/22
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
    std::string name;
    WorldMap* map;
    ParticipantType participantType;

public:
    Participants(ParticipantType pT);
    virtual ~Participants();

    /**
     * \fn Participants::armyMove
     * \brief pure virtual method to move army to new cells
     */
    virtual void armyMove() = 0;

    /**
     * \fn Participants::retreat
     * \param cells     Vector for cells that need to be retreated
     * \brief virtual method that will move squads currently on cells one cell back
     */
    virtual void retreat(std::vector<Cell*> cells)=0;
    std::vector<Cell*> * getOwnedTerritories();
    virtual std::vector<Cell*> atBack() = 0;


    void retreatParticipants();

    /**
        \fn Participants::addUnit
        \brief Adds a military unit to the Participants army vector
        \details Receives a MilitaryUnit pointer, checks if it is a Composite participants of the Composite pattern. 
        \details If the passed parameter is a Leaf participant, a new composite (squad) is created which contains 
        \details the passed parameter, and the squad is added to the army instead. 
        \details Otherwise, if the passed parameter is already a composite, it is added to the army directly
        \param m A MilitaryUnit pointer that points to either a Leaf or a Composite participant
    */
    void addUnit(MilitaryUnit* m);
    std::vector<MilitaryUnit*> * getArmy();
    int getTotalHealthPoints();

    /**
    * \fn Participants::getTotalDamage
    * \return int value
    * \brief method to calculate and return total damage the Participant can inflict
    */
    int getTotalDamage();

    /**
     * \fn Participants::getName
     * \return string value
     * \brief getter method for the name attribute
     */
    std::string getName();
    ParticipantType getParticipantType() ;
    WorldMap *getMap();

    /**
     * \fn Participants::setMap
     * \param map   WorldMap pointer
     * \brief setter for the map variable
     */
    void setMap(WorldMap *map);

    /**
     * \fn Participants::removeMilitaryUnit
     * \param m     MilitaryUnit pointer
     * \brief removes given MilitaryUnit from army vector
     */
    void removeMilitaryUnit(MilitaryUnit* m);

protected:
    vector<MilitaryUnit*> army;
    vector<Cell*> ownedTerritories;
    //Action* state;
    double resources;
    //vector<attackStrategy*> moveStrategies;
    std::string name;
    WorldMap* map;
    Participant participant;

};

#endif
