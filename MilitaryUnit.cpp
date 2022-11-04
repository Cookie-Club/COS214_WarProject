#include "MilitaryUnit.h"
MilitaryUnit::MilitaryUnit(Participants* belongsTo, UnitType type): squad(nullptr)
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

Participant MilitaryUnit::getParticipant() {
    return getOwner()->getParticipant();
}

void MilitaryUnit::setSquad(Squad* squad)
{
    this->squad = squad;
}

Squad* MilitaryUnit::getSquad()
{
    return squad;
}

void MilitaryUnit::removeSquad()
{
    squad = nullptr;
}

