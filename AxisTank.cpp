/**
    \file AxisTank.cpp
    \brief Implements AxisTank class methods
    \authors Wian Koekemoer
    \date 30/10/22
*/
#include "AxisTank.h"

AxisTank::AxisTank(int damage, int healthpoints, Participants* belongsTo, float fuelConsumption) 
:Tank(damage, healthpoints, belongsTo, fuelConsumption){
    std::cout << "AxisTank created";
}

MilitaryUnit* AxisTank::clone()
{
    MilitaryUnit* temp = new AxisTank(this->damage, this->healthpoints, this->belongsTo, this->fuelConsumption);

    return temp;
}
