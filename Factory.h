#ifndef FACTORY_H
#define FACTORY_H
#include "MilitaryUnit.h"
class Factory {
public:
	virtual MilitaryUnit* createInfantry() = 0;
	virtual MilitaryUnit* createTank() = 0;

};

#endif
