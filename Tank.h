/**
	\class Tank
	\brief Abstract interface for tank objects
    \details Prototype pattern: AbstractProduct
	\author Wian K
*/

#ifndef TANK_H
#define TANK_H

#include "TeamMembers.h"
#include "MilitaryUnit.h"

class Tank : public TeamMembers {
    public:
        virtual MilitaryUnit* clone() = 0;
        float getFuelConsumption();
        void setFuelConsumption(float);
    protected:
        float fuelConsumption;

};


#endif //TANK_H
