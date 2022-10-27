#ifndef FACTORY_H
#define FACTORY_H
#include "Infantry.h"
#include "Tank.h"
class Factory {
public:
    virtual Infantry* createInfantry() = 0;
    virtual Tank* createTank() = 0;

};

#endif
