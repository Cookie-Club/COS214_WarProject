/**
    \file CentralTank.cpp
    \brief Implements CentralTank class methods
    \authors Wian Koekemoer
    \date 30/10/22
*/
#include "CentralTank.h"

CentralTank::CentralTank(int damage, int healthpoints, Participants* belongsTo, float fuelConsumption) 
:Tank(damage, healthpoints, belongsTo, fuelConsumption){
    //std::cout << "CentralTank created";
}

MilitaryUnit* CentralTank::clone()
{
    MilitaryUnit* temp = new CentralTank(this->damage, this->healthpoints, this->belongsTo, this->fuelConsumption);

    return temp;
}
