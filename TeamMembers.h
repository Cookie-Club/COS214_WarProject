#ifndef TEAMMEMBERS_H
#define TEAMMEMBERS_H

#include <iostream>

#include "MilitaryUnit.h"
class TeamMembers : public MilitaryUnit {

    public:
        virtual MilitaryUnit* clone() = 0;
        void setHealthpoints(int hp);
        virtual bool isLeaf();
        bool receiveDamage(int damage);
        UnitType getType();

        virtual std::vector<MilitaryUnit*> getMembers();

    protected:
        int damage;
        int healthpoints;
};



#endif
