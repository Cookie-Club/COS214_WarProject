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
        /**
            \fn Tank::Tank
            \brief Constructor
        */
        Tank(int damage, int healthpoints, Participants* belongsTo, float fuelConsumption);
        /**
            \fn Tank::clone
            \brief Pure virtual function inherited from MilitaryUnit
        */
        virtual MilitaryUnit* clone() = 0;
        /**
            \fn Tank::getFuelConsumption
            \brief Getter for fuelConsumption
        */
        float getFuelConsumption();
        /**
            \fn Tank::setFuelConsumption
            \brief Setter for fuelConsumption
        */
        void setFuelConsumption(float);
    protected:
        float fuelConsumption;

};


#endif //TANK_H
