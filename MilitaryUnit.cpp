#include "MilitaryUnit.h"
MilitaryUnit::MilitaryUnit(Participants* belongsTo, UnitType type): belongsTo(belongsTo), type(type), map(belongsTo->getMap())
{

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

