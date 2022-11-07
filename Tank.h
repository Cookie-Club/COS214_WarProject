/**
    \file Tank.h
    \class Tank
	\brief Abstract interface for tank objects
    \details Prototype pattern: AbstractProduct
    \authors Wian Koekemoer
    \date 30/10/22
*/

#ifndef TANK_H
#define TANK_H

#include "TeamMembers.h"

class Tank : public TeamMembers {
public:
    /**
        \fn Tank::Tank
        \brief Constructor
        \param[in] damage           The total damage the Infantry object should deal to other units
        \param[in] healthpoints     The number of healthpoints the Infantry object should have
        \param[in] belongsTo        Pointer to Participants object that owns the Infantry object
        \param[in] fuelConsumption  A float value denoting the total fuel consumed when traveling
    */
    Tank(int damage, int healthpoints, Participants *belongsTo, float fuelConsumption);

    virtual ~Tank() {};

    /**
        \fn Tank::clone
        \brief Pure virtual function inherited from MilitaryUnit
    */
    virtual MilitaryUnit *clone() = 0;

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
