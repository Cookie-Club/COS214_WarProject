#include "CentralTank.h"

CentralTank::CentralTank(int damage, int healthpoints, Participants *belongsTo, float fuelConsumption) 
: Tank(damage,healthpoints,belongsTo,fuelConsumption) {
}

MilitaryUnit *CentralTank::clone() {
    MilitaryUnit *temp = new CentralTank(this->damage, this->healthpoints, this->belongsTo, this->fuelConsumption);

    return temp;
}
