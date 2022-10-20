#ifndef ALLIEDFACTORY_H
#define ALLIEDFACTORY_H

#include "Factory.h"
#include "AlliedInfantry.h"
#include "AlliedTank.h"

class AlliedFactory : public Factory {
    public:
        MilitaryUnit* createInfantry();
        MilitaryUnit* createTank();
};


#endif //ALLIEDFACTORY_H
