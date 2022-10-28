/**
	\class AxisInfantry
	\brief Concrete military unit class
	\details Prototype pattern: ConcretePrototype
    Implements clone method of Prototype pattern
	\author Wian K
*/

#ifndef AXISINFANTRY_H
#define AXISINFANTRY_H

#include "Infantry.h"

class AxisInfantry : public Infantry {
public:
    AxisInfantry();
    MilitaryUnit* clone();
};


#endif //AXISINFANTRY_H
