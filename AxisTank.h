/**
	\class AxisTank
	\brief Concrete Tank military unit of Axis
	\details Prototype pattern: ConcretePrototype
    Implements clone method of Prototype pattern
	\author Wian K
*/

#ifndef AXISTANK_H
#define AXISTANK_H

#include "Tank.h"

class AxisTank : public Tank 
{
	public:
		/**
			\fn AxisTank::AxisTank
			\brief Constructor
		*/
		AxisTank(int damage, int healthpoints, Participants* belongsTo, float fuelConsumption);
		/**
			\fn AxisTank::clone
			\brief Return copy of the object
		*/
		MilitaryUnit* clone();
};


#endif //AXISTANK_H
