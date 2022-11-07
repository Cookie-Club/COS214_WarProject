#include "MilitaryUnit.h"
MilitaryUnit::MilitaryUnit(Participants* belongsTo, UnitType type): belongsTo(belongsTo), type(type), map(belongsTo->getMap())
{

}

Participants* MilitaryUnit::getOwner()
{
    return belongsTo;
}

void MilitaryUnit::setOwner(Participants* p)
{
    belongsTo = p;
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

ParticipantType MilitaryUnit::getParticipantType()
{
    return belongsTo->getParticipantType();
}

Squad* MilitaryUnit::getSquad()
{
    return squad;
}

void MilitaryUnit::setSquad(Squad* squad)
{
    this->squad = squad;
}