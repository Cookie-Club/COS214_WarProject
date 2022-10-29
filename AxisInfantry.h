/**
	\class AxisInfantry
	\brief Concrete Infantry military unit of Axis
	\details Prototype pattern: ConcretePrototype
    Implements clone method of Prototype pattern
	\author Wian K
*/

#ifndef AXISINFANTRY_H
#define AXISINFANTRY_H

#include "Infantry.h"

class AxisInfantry : public Infantry 
{
	public:
		/**
			\fn AxisInfantry::AxisInfantry
			\brief Constructor
		*/
		AxisInfantry(int damage, int healthpoints, Participants* belongsTo, int rationConsumption);
		/**
			\fn AxisInfantry::clone
			\brief Return copy of the object
		*/
		MilitaryUnit* clone();
};


#endif //AXISINFANTRY_H
