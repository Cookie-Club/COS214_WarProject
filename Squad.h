/**
	\class Squad
	\brief Composite satructure of military units
	\details Stores TeamMember objects, stores occupying cell, implements movement
    Composite pattern: Composite participant
	\author Wian Koekemoer
*/

#ifndef SQUAD_H
#define SQUAD_H
#include "TeamMembers.h"
#include "MilitaryUnit.h"
#include "Cell.h"
#include <vector>

class Squad : public MilitaryUnit {

    public:
        /** 
            \fn Squad::Squad
            \brief Default constructor
            \details Sets type to Squad
        */
        Squad();
        /**
            \fn Squad::Squad
            \brief Constructor
        */
        Squad(Participants* belongsTo);
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
        */
        void addMember(MilitaryUnit* m);
        /**
            \fn Squad::removeSquadMember
            \brief Removes a military unit from the list of members
        */
        void removeSquadMember(MilitaryUnit* member);
        /**
            \fn Squad::getMembers
            \brief Returns members vector
        */
        virtual std::vector<MilitaryUnit*> getMembers();
        /**
            \fn Squad::receiveDamage
            \brief Receives damage
            \details Receives damage input, and distributes it among members, 
            \details returning bool value that represents whether squad died
        */
        virtual bool receiveDamage(int damage);

    protected:
        Cell* occupyingCell;
        std::vector<MilitaryUnit*> members;
        int Ammo;
        int rations;
        float fuel;
};


#endif //SQUAD_H
