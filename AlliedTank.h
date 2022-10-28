/**
	\class AlliedTank
	\brief Concrete military unit class
	\details Prototype pattern: ConcretePrototype
    Implements clone method of Prototype pattern
	\author Wian K
*/

#ifndef ALLIEDTANK_H
#define ALLIEDTANK_H

#include "Tank.h"

class AlliedTank : public Tank {
public:
    AlliedTank();
    MilitaryUnit* clone();
};


#endif //ALLIEDTANK_H
