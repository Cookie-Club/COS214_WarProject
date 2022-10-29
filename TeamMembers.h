/**
	\class TeamMembers
	\brief Abstract interface for basic military units
	\details Defines damage and healthpoitns variables and their getters/setters
    Composite pattern: Leaf
	\author Wian K
*/

#ifndef TEAMMEMBERS_H
#define TEAMMEMBERS_H

#include <iostream>

#include "MilitaryUnit.h"
//Forward declaration for squad type
class Squad;
class TeamMembers : public MilitaryUnit {

    public:
        /**
            \fn TeamMembers:TeamMembers
            \brief Constructor
            \details Sets damage and healthpoints
        */
        TeamMembers(int damage, int healthpoints, UnitType type, Participants* belongsTo);
        /**
            \fn TeamMembers:clone
            \brief Inherited from MilitaryUnit, not implemented
        */
        virtual MilitaryUnit* clone() = 0;
        /**
            \fn TeamMembers:setHealthpoints
            \brief Setter for healthpoints variable
        */
        void setHealthpoints(int hp);
        /**
            \fn TeamMembers::setDamage
            \brief Setter for damage
        */
        void setDamage(int damage);
        /**
            \fn TeamMembers::isLeaf
            \brief Returns true to communicate object is leaf in Composite structure
        */
        virtual bool isLeaf();
        /**
            \fn Squad::receiveDamage
            \brief Reduces unit healthpoints
            \details Receives damage as a parameter and subtracts it from the unit's healthpoints.
            Returns false if the unit died, and true if otherwise
        */
        bool receiveDamage(int damage);
        /**
            \fn TeamMembers::getSquad
            \brief Getter for squad
        */
        Squad* getSquad(){return squad;};
        /**
            \fn TeamMembers::getSquad
            \brief Getter for squad
        */
        void setSquad(Squad* squad);

    protected:
        Squad* squad;
        int damage;
        int healthpoints;
};



#endif
