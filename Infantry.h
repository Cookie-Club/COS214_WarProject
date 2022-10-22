#ifndef INFANTRY_H
#define PROJECT_INFANTRY_H

#include "TeamMembers.h"
#include "MilitaryUnit.h"

class Infantry : public TeamMembers {
    public:
        MilitaryUnit* clone();
        int getRationConsumption();

    protected:
        int rationConsumption;

};


#endif //INFANTRY_H
