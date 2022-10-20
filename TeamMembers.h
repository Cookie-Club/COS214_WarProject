#ifndef TEAMMEMBERS_H
#define TEAMMEMBERS_H

#include <iostream>

#include "MilitaryUnit.h"

using namespace std;

class TeamMembers : public MilitaryUnit {

    public:
        virtual MilitaryUnit* clone() = 0;
        void setHealthpoints(int hp);
        virtual bool isLeaf(){return true;};
        void receiveDamage(int damage);
        string getType();
    protected:
        int damage;
        int healthpoints;
};



#endif
