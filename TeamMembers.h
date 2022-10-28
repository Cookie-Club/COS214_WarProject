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
class TeamMembers : public MilitaryUnit {

    public:
        virtual MilitaryUnit* clone() = 0;
        void setHealthpoints(int hp);
        void setDamage(int damage);
        virtual bool isLeaf();
        bool receiveDamage(int damage);

        virtual std::vector<MilitaryUnit*> getMembers();

    protected:
        int damage;
        int healthpoints;
};



#endif
