#ifndef AXISFACTORY_H
#define AXISFACTORY_H

#include "Factory.h"
#include "AxisInfantry.h"
#include "AxisTank.h"
class AxisFactory : public Factory {
    public:
        MilitaryUnit* createInfantry();
        MilitaryUnit* createTank();
};



#endif //AXISFACTORY_H
