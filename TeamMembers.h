#ifndef TEAMMEMBERS_H
#define TEAMMEMBERS_H

#include "MilitaryUnit.h"
enum UnitType { infantry, tank };
class TeamMembers : public MilitaryUnit {

    public:
        virtual MilitaryUnit* clone() = 0;
        void setHealthpoints(int hp);
        virtual bool isLeaf();
        UnitType getType();
    protected:
        int damage;
        int healthpoints;
        UnitType type;
};



#endif //TEAMMEMBERS_H
