/**
    \file Infantry.cpp
    \brief Implements Infantry class methods
    \authors Wian Koekemoer
    \date 30/10/22
*/
#include "Infantry.h"

Infantry::Infantry(int damage, int healthpoints, Participants* belongsTo, int rationConsumption)
:TeamMembers(damage, healthpoints, UnitType::infantry, belongsTo), rationConsumption(rationConsumption){}

int Infantry::getRationConsumption()
{
    return this->rationConsumption;
}

void Infantry::setRationConsumption(int rationConsumption)
{
    this->rationConsumption = rationConsumption;
}