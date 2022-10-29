
#include "AlliedInfantry.h"

/**
    \fn AlliedInfantry::AlliedInfantry
    \brief Defaulkt Constructor
*/
AlliedInfantry::AlliedInfantry() {
    std::cout << "AlliedInfantry created";
}

/**
    \fn AlliedInfantry::clone
    \brief Return copy of the object
*/
MilitaryUnit* AlliedInfantry::clone()
{
    MilitaryUnit* temp = new AlliedInfantry();
    ((AlliedInfantry*)temp)->setHealthpoints(this->healthpoints);
    ((AlliedInfantry*)temp)->setDamage(this->damage);
    ((AlliedInfantry*)temp)->setRationConsumption(this->rationConsumption);

    return temp;
}
