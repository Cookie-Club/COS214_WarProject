#ifndef AXISFACTORY_H
#define AXISFACTORY_H

#include "Factory.h"
#include "CentralInfantry.h"
#include "CentralTank.h"

class CentralFactory : public Factory {
public:
    Infantry* createInfantry();
    Tank* createTank();
};



#endif //AXISFACTORY_H
