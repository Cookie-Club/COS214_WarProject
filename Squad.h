/**
    \file Squad.h
    \brief Defines Squad class
    \authors Wian Koekemoer
    \date 30/10/22
*/
/**
	\class Squad
	\brief Composite satructure of military units
	\details Stores TeamMember objects, stores occupying cell, implements movement
    Composite pattern: Composite participant
	\authors Wian Koekemoer, Robert Officer
*/

#ifndef SQUAD_H
#define SQUAD_H
#include "TeamMembers.h"
#include "MilitaryUnit.h"
#include "Cell.h"
#include "Order.h"
#include "attackStrategy.h"
#include "Action.h"
#include <vector>

//Forward declaration for callInBombardment usage of the constructor and execute methods
class Bombardment : public Order{
    public:
        Bombardment(Cell * targetedCell);
        void execute(){};
};

class Squad : public MilitaryUnit {

    public:
        
        /**
            \fn Squad::Squad
            \brief Constructor
            \param[in] belongsTo    Pointer to Participants object that owns the Squad object
        */
        Squad(Participants* belongsTo);
        /**
            \fn Squad::~Squad
            \brief Destructor
            \details Deletes members
        */
        ~Squad();
        /**
            \fn Squad::moveSquad
            \brief Select cell to move to
        */
        void moveSquad();
        /**
            \fn Squad::setOccupyingCell
            \brief Stores the cell on which the squad is located
            \details Receives a cell reference
            Requests old cell to remove the squad from its occupying forces variable
            Saves cell reference that was passed as parameter
            Requests that new cell add the squad to its occupying forces variable
            \param[in] c    Pointer to Cell object on which the Squad object is located
        */
        void setOccupyingCell(Cell* c);
        /**
            \fn Squad::clone
            \brief Clone operation of Prototype pattern
            \details Creates and returns a copy of the Squad composite structure and its TeamMembers
        */
        MilitaryUnit* clone();
        /**
            \fn Squad::isLeaf
            \brief Returns false to communicate object is not a leaf in Composite structure
        */
        bool isLeaf();
        /**
            \fn Squad::addMember
            \brief Expands members variable
            \details Adds parameter to members vector
            \param[in] m    Pointer to MilitaryUnit object which should be added to members vector
        */
        void addMember(MilitaryUnit* m);
        /**
            \fn Squad::removeSquadMember
            \brief Removes a military unit from the list of members
            \param[in] member   Pointer to member which should be removed from members vector
        */
        void removeSquadMember(MilitaryUnit* member);
        /**
            \fn Squad::getMembers
            \brief Getter for members vector
        */
        virtual std::vector<MilitaryUnit*> getMembers();
        /**
            \fn Squad::receiveDamage
            \brief Receives damage
            \details Receives damage input, and distributes it among members, 
            \details returning bool value that represents whether squad died
            \param[in] damage   Total damage which should be dealt to the Squad object
        */
        virtual bool receiveDamage(int damage);

        /**
            \fn Squad::callInBombardment
            \brief Executes the Command and Chain of Responsibility
            \details Creates a new bombardment order and executes the new order on the passed in cell.
        */
        void callInBombardment(Cell * targetedCell);

    Action *getState() const;

    void setState(Action *state);

    const attackStrategy* getStrategy() const;

    void setStrategy(const attackStrategy* strategy);

    void attack();

    protected:
        Cell* occupyingCell;
        std::vector<MilitaryUnit*> members;
        int Ammo;
        int rations;
        float fuel;
        Action* state;
        attackStrategy* strategy;
};


#endif //SQUAD_H
