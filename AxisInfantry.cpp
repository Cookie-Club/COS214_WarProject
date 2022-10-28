
#include "AxisInfantry.h"
AxisInfantry::AxisInfantry() {
    std::cout << "AxisInfantry created";
}

/**
    \fn AxisInfantry::clone
    \brief Return copy of the object
*/
MilitaryUnit* AxisInfantry::clone()
{
    MilitaryUnit* temp = new AxisInfantry();
    ((AxisInfantry*)temp)->setHealthpoints(this->healthpoints);
    ((AxisInfantry*)temp)->setDamage(this->damage);
    ((AxisInfantry*)temp)->setRationConsumption(this->rationConsumption

    return temp;
}
