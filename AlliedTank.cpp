#include "AlliedTank.h"

AlliedTank::AlliedTank(int damage, int healthpoints, Participants *belongsTo, float fuelConsumption) 
: Tank(damage,healthpoints,belongsTo,fuelConsumption) {
}

MilitaryUnit *AlliedTank::clone() {
    MilitaryUnit *temp = new AlliedTank(this->damage, this->healthpoints, this->belongsTo, this->fuelConsumption);

    return temp;
}
