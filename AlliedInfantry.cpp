/**
    \file AlliedInfantry.cpp
    \brief Implements AlliedInfantry class methods
    \authors Wian Koekemoer
    \date 30/10/22
*/
#include "AlliedInfantry.h"

AlliedInfantry::AlliedInfantry(int damage, int healthpoints, Participants* belongsTo, int rationConsumption) 
: Infantry(damage, healthpoints, belongsTo, rationConsumption){
    std::cout << "AlliedInfantry created";
}

MilitaryUnit* AlliedInfantry::clone()
{
    MilitaryUnit* temp = new AlliedInfantry(this->damage, this->healthpoints, this->belongsTo, this->rationConsumption);

    return temp;
}
