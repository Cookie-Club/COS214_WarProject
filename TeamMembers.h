#ifndef TEAMMEMBERS_H
#define TEAMMEMBERS_H

#include "MilitaryUnit.h"

class TeamMembers : public MilitaryUnit {

private:
    int damage;
    int healthpoints;

public:
    virtual MilitaryUnit* clone() = 0;
    void setHealthpoints();

};


#endif //TEAMMEMBERS_H
