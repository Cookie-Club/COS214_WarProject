
#include "AlliedInfantry.h"

AlliedInfantry::AlliedInfantry(int damage, int healthpoints, Participants* belongsTo, int rationConsumption) 
: Infantry(damage, healthpoints, belongsTo, rationConsumption){
    //std::cout << "Allied Infantry created";
}

MilitaryUnit* AlliedInfantry::clone()
{
    MilitaryUnit* temp = new AlliedInfantry(this->damage, this->healthpoints, this->belongsTo, this->rationConsumption);

    return temp;
}
