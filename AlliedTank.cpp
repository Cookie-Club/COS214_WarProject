#include "AlliedTank.h"

/**
    \fn AlliedTank::AlliedTank
    \brief Default Constructor
*/
AlliedTank::AlliedTank() {
    std::cout << "AlliedTank created";
}

/**
    \fn AlliedTank::clone
    \brief Return copy of the object
*/
MilitaryUnit* AlliedTank::clone()
{
    MilitaryUnit* temp = new AlliedTank();
    ((AlliedTank*)temp)->setHealthpoints(this->healthpoints);
    ((AlliedTank*)temp)->setDamage(this->damage);
    ((AlliedTank*)temp)->setFuelConsumption(this->fuelConsumption);

    return temp;
}
