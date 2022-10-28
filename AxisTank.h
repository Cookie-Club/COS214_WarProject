/**
	\class AxisTank
	\brief Concrete military unit class
	\details Prototype pattern: ConcretePrototype
    Implements clone method of Prototype pattern
	\author Wian K
*/

#ifndef AXISTANK_H
#define AXISTANK_H

#include "Tank.h"

class AxisTank : public Tank {
public:
    AxisTank();
    MilitaryUnit* clone();
};


#endif //AXISTANK_H
