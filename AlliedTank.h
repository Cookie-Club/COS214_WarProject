/**
    \file AlliedTank.h
    \brief Defines AlliedTank class
    \authors Wian Koekemoer
    \date 30/10/22
*/
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
            \param[in] damage 			The total damage the AlliedTank object should deal to other units
            \param[in] healthpoints		The number of healthpoints the AlliedTank object should have
            \param[in] belongsTo		Pointer to Participants object that owns the AlliedTank object
            \param[in] fuelConsumption	A float value denoting the total fuel consumed when traveling
		*/
		AlliedTank(int damage, int healthpoints, Participants* belongsTo, float fuelConsumption);
        virtual ~AlliedTank(){};
		/**
			\fn AlliedTank::clone
			\brief Return copy of the object
		*/
		MilitaryUnit* clone();
};


#endif //ALLIEDTANK_H
