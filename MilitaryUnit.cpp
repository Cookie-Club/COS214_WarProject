#include "MilitaryUnit.h"
Participants* MilitaryUnit::getOwner()
{
    return belongsTo;
}

UnitType MilitaryUnit::getType()
{
    return this->type;
}