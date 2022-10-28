/**
	\class AlliedInfantry
	\brief Concrete military unit class
	\details Prototype pattern: ConcretePrototype
    Implements clone method of Prototype pattern
	\author Wian K
*/

#ifndef ALLIEDINFANTRY_H
#define ALLIEDINFANTRY_H

#include "Infantry.h"

class AlliedInfantry : public Infantry {
public:
    AlliedInfantry();
    MilitaryUnit* clone();
};


#endif //ALLIEDINFANTRY_H
