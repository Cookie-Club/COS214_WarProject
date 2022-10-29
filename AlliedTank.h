/**
	\class AlliedTank
	\brief Concrete Tank military unit of Allies
	\details Prototype pattern: ConcretePrototype 
    Implements clone method of Prototype pattern
	\author Wian K
*/

#ifndef ALLIEDTANK_H
#define ALLIEDTANK_H

#include "Tank.h"

class AlliedTank : public Tank 
{
	public:
		/**
			\fn AlliedTank::AlliedTank
			\brief Constructor
		*/
		AlliedTank(int damage, int healthpoints, Participants* belongsTo, float fuelConsumption);
		/**
			\fn AlliedTank::clone
			\brief Return copy of the object
		*/
		MilitaryUnit* clone();
};


#endif //ALLIEDTANK_H
