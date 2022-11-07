#include "CentralInfantry.h"

CentralInfantry::CentralInfantry(int damage, int healthpoints, Participants *belongsTo, int rationConsumption)
        : Infantry(damage, healthpoints, belongsTo, rationConsumption) {
<<<<<<< Updated upstream
    //std::cout << "CentralInfantry created";
=======

>>>>>>> Stashed changes
}

MilitaryUnit *CentralInfantry::clone() {
    MilitaryUnit *temp = new CentralInfantry(this->damage, this->healthpoints, this->belongsTo,
                                             this->rationConsumption);

    return temp;
}
