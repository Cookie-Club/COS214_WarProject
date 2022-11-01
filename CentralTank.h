/**
	\class CentralTank
	\brief Concrete Tank military unit of Central
	\details Prototype pattern: ConcretePrototype
    Implements clone method of Prototype pattern
	\author Wian K
*/

#ifndef AXISTANK_H
#define AXISTANK_H

#include "Tank.h"

class CentralTank : public Tank 
{
	public:
		/**
			\fn CentralTank::CentralTank
			\brief Constructor
            \param[in] damage 			The total damage the CentralTank object should deal to other units
            \param[in] healthpoints		The number of healthpoints the CentralTank object should have
            \param[in] belongsTo		Pointer to Participants object that owns the CentralTank object
            \param[in] fuelConsumption	A float value denoting the total fuel consumed when traveling
		*/
		CentralTank(int damage, int healthpoints, Participants* belongsTo, float fuelConsumption);
        virtual ~CentralTank(){};
		/**
			\fn CentralTank::clone
			\brief Return copy of the object
		*/
		MilitaryUnit* clone();
};


#endif //AXISTANK_H
