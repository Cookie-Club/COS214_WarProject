#ifndef TANK_H
#define TANK_H

#include "TeamMembers.h"
#include "MilitaryUnit.h"

class Tank : public TeamMembers {
    public:
        MilitaryUnit* clone();
        Tank();

};


#endif //TANK_H
