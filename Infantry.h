#ifndef INFANTRY_H
#define PROJECT_INFANTRY_H

#include "TeamMembers.h"
#include "MilitaryUnit.h"

class Infantry : public TeamMembers {
    public:
        MilitaryUnit* clone();
        Infantry();

};


#endif //INFANTRY_H
