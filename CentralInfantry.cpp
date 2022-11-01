/**
    \file CentralInfantry.cpp
    \brief Implements CentralInfantry class methods
    \authors Wian Koekemoer
    \date 30/10/22
*/
#include "CentralInfantry.h"

CentralInfantry::CentralInfantry(int damage, int healthpoints, Participants* belongsTo, int rationConsumption) 
: Infantry(damage, healthpoints, belongsTo, rationConsumption){
    std::cout << "CentralInfantry created";
}

MilitaryUnit* CentralInfantry::clone()
{
    MilitaryUnit* temp = new CentralInfantry(this->damage, this->healthpoints, this->belongsTo, this->rationConsumption);

    return temp;
}
