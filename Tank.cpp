/**
    \file Tank.cpp
    \brief Implements Tank class methods
    \authors Wian Koekemoer
    \date 30/10/22
*/
#include "Tank.h"

Tank::Tank(int damage, int healthpoints, Participants *belongsTo, float fuelConsumption) : TeamMembers(damage,
                                                                                                       healthpoints,
                                                                                                       UnitType::tank,
                                                                                                       belongsTo),
                                                                                           fuelConsumption(
                                                                                                   fuelConsumption) {}

float Tank::getFuelConsumption() {
    return this->fuelConsumption;
}

void Tank::setFuelConsumption(float fuelConsumption) {
    this->fuelConsumption = fuelConsumption;
}