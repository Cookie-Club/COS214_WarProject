/**
    \file AxisInfantry.cpp
    \brief Implements AxisInfantry class methods
    \authors Wian Koekemoer
    \date 30/10/22
*/
#include "AxisInfantry.h"

AxisInfantry::AxisInfantry(int damage, int healthpoints, Participants* belongsTo, int rationConsumption) 
: Infantry(damage, healthpoints, belongsTo, rationConsumption){
    std::cout << "AxisInfantry created";
}

MilitaryUnit* AxisInfantry::clone()
{
    MilitaryUnit* temp = new AxisInfantry(this->damage, this->healthpoints, this->belongsTo, this->rationConsumption);

    return temp;
}
