
#include "AxisInfantry.h"

AxisInfantry::AxisInfantry(int damage, int healthpoints, Participants* belongsTo, int rationConsumption) 
: Infantry(damage, healthpoints, belongsTo, rationConsumption){
    std::cout << "AxisInfantry created";
}

MilitaryUnit* AxisInfantry::clone()
{
    MilitaryUnit* temp = new AxisInfantry(this->damage, this->healthpoints, this->belongsTo, this->rationConsumption);

    return temp;
}
