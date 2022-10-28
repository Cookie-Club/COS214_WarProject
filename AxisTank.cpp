
#include "AxisTank.h"
AxisTank::AxisTank() {
    std::cout << "AxisTank created";
}

/**
    \fn AxisTank::clone
    \brief Return copy of the object
*/
MilitaryUnit* AxisTank::clone()
{
    MilitaryUnit* temp = new AxisTank();
    ((AxisTank*)temp)->setHealthpoints(this->healthpoints);
    ((AxisTank*)temp)->setDamage(this->damage);
    ((AxisTank*)temp)->setFuelConsumption(this->fuelConsumption);

    return temp;
}
