/**
    \file CentralInfantry.h
    \brief Defines CentralInfantry class
    \authors Wian Koekemoer
    \date 30/10/22
*/
/**
	\class CentralInfantry
	\brief Concrete Infantry military unit of Central
	\details Prototype pattern: ConcretePrototype
    Implements clone method of Prototype pattern
	\author Wian K
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
