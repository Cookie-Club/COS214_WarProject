#include "Infantry.h"

Infantry::Infantry(int damage, int healthpoints, Participants* belongsTo, int rationConsumption)
:TeamMembers(damage, healthpoints, belongsTo, UnitType::infantry), rationConsumption(rationConsumption){}

Infantry::Infantry(){
    type = infantry;
}

int Infantry::getRationConsumption()
{
    return this->rationConsumption;
}

void Infantry::setRationConsumption(int rationConsumption)
{
    this->rationConsumption = rationConsumption;
}