/**
    \file AlliedInfantry.h
    \class AlliedInfantry
    \brief Concrete Product in the Abstract factory pattern. Concrete Infantry military unit of Allies
    \details implements the abstract operations that produce product objects that are created
    by the corresponding ConcreteFactories
    Prototype pattern: ConcretePrototype
    Implements clone method of Prototype pattern
    \ingroup MilitaryUnit
    \author Kaitlyn Sookdhew, Wian Koekemoer
*/

#ifndef AXISINFANTRY_H
#define AXISINFANTRY_H

#include "Infantry.h"

class CentralInfantry : public Infantry 
{
	public:
		/**
			\fn CentralInfantry::CentralInfantry
			\brief Constructor
            \param[in] damage               The total damage the CentralInfantry object should deal to other units
            \param[in] healthpoints         The number of healthpoints the CentralInfantry object should have
            \param[in] belongsTo            Pointer to Participants object that owns the CentralInfantry object
            \param[in] rationConsumption    An integer value denoting the total rations consumed when traveling
		*/
		CentralInfantry(int damage, int healthpoints, Participants* belongsTo, int rationConsumption);
        virtual ~CentralInfantry(){};
		/**
			\fn CentralInfantry::clone
			\brief Return copy of the object
		*/
		MilitaryUnit* clone();
};


#endif //AXISINFANTRY_H
