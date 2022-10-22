
#include "TeamMembers.h"

void TeamMembers::setHealthpoints(int hp)
{
    this->healthpoints = hp;
}

bool TeamMembers::isLeaf()
{
    return true;
}

UnitType TeamMembers::getType()
{
    return this->type;
}
