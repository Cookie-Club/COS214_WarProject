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
            \param[in] damage 			The total damage the AxisTank object should deal to other units
            \param[in] healthpoints		The number of healthpoints the AxisTank object should have
            \param[in] belongsTo		Pointer to Participants object that owns the AxisTank object
            \param[in] fuelConsumption	A float value denoting the total fuel consumed when traveling
		*/
		AxisTank(int damage, int healthpoints, Participants* belongsTo, float fuelConsumption);
        virtual ~AxisTank();
		/**
			\fn AxisTank::clone
			\brief Return copy of the object
		*/
		MilitaryUnit* clone();
};


#endif //AXISTANK_H
