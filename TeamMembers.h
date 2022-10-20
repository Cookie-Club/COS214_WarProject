#ifndef TEAMMEMBERS_H
#define TEAMMEMBERS_H

#include "MilitaryUnit.h"

class TeamMembers : public MilitaryUnit {

    public:
        virtual MilitaryUnit* clone() = 0;
        void setHealthpoints(int hp);
        virtual bool isLeaf(){return true;};
    protected:
        int damage;
        int healthpoints;

};



#endif //TEAMMEMBERS_H
