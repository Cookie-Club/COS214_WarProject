#include "CentralInfantry.h"

CentralInfantry::CentralInfantry(int damage, int healthpoints, Participants *belongsTo, int rationConsumption)
        : Infantry(damage, healthpoints, belongsTo, rationConsumption) {
    //std::cout << "CentralInfantry created";
}

MilitaryUnit *CentralInfantry::clone() {
    MilitaryUnit *temp = new CentralInfantry(this->damage, this->healthpoints, this->belongsTo,
                                             this->rationConsumption);

    return temp;
}
