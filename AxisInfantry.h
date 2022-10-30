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
            \param[in] damage               The total damage the AxisInfantry object should deal to other units
            \param[in] healthpoints         The number of healthpoints the AxisInfantry object should have
            \param[in] belongsTo            Pointer to Participants object that owns the AxisInfantry object
            \param[in] rationConsumption    An integer value denoting the total rations consumed when traveling
		*/
		AxisInfantry(int damage, int healthpoints, Participants* belongsTo, int rationConsumption);
		/**
			\fn AxisInfantry::clone
			\brief Return copy of the object
		*/
		MilitaryUnit* clone();
};


#endif //AXISINFANTRY_H
