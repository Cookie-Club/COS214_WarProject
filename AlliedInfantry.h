/**
	\class AlliedInfantry
	\brief Concrete Infantry military unit of Allies
	\details Prototype pattern: ConcretePrototype 
    Implements clone method of Prototype pattern
	\author Wian K
*/

#ifndef ALLIEDINFANTRY_H
#define ALLIEDINFANTRY_H

#include "Infantry.h"

class AlliedInfantry : public Infantry 
{
	public:
		/**
			\fn AlliedInfantry::AlliedInfantry
			\brief Constructor
		*/
		AlliedInfantry(int damage, int healthpoints, Participants* belongsTo, int rationConsumption);
		/**
			\fn AlliedInfantry::clone
			\brief Return copy of the object
		*/
		MilitaryUnit* clone();
};


#endif //ALLIEDINFANTRY_H
