
/**
    \file AlliedTank.h
    \class AlliedTank
    \brief Concrete Product in the Abstract factory pattern. Concrete Tank military unit of Allies
    \details implements the abstract operations that produce product objects that are created
    by the corresponding ConcreteFactories
    Prototype pattern: ConcretePrototype
    Implements clone method of Prototype pattern
    \ingroup MilitaryUnit
    \author Kaitlyn Sookdhew, Wian Koekemoer
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
			\brief clone() method of Prototype pattern
			\return A copy of the current AlliedTank
		*/
		MilitaryUnit* clone();
};


#endif //ALLIEDTANK_H
