#include "MilitaryUnit.h"
MilitaryUnit::MilitaryUnit(Participants* belongsTo, UnitType type)
{
    this->belongsTo = belongsTo;
    this->type = type;
}

Participants* MilitaryUnit::getOwner()
{
    return belongsTo;
}

UnitType MilitaryUnit::getType()
{
    return this->type;
}

WorldMap* MilitaryUnit::getMap()
{
    return map;
}

void MilitaryUnit::setMap(WorldMap *map) {
    this->map = map;
}