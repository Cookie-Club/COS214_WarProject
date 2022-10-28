#include "Tank.h"

/**
    \fn Tank::Tank
    \brief Default constructor
    \details Sets type to Tank
*/
Tank::Tank(){
    type = tank;
}

/**
    \fn Tank::getFuelConsumption
    \brief Getter for fuelConsumption
*/
float Tank::getFuelConsumption()
{
    return this->fuelConsumption;
}

/**
    \fn Tank::setFuelConsumption
    \brief Setter for fuelConsumption
*/
void Tank::setFuelConsumption(float fuelConsumption)
{
    this->fuelConsumption = fuelConsumption;
}