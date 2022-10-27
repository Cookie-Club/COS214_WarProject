#include "TeamMembers.h"

bool TeamMembers::receiveDamage(int damage){
    int newHealth = healthpoints - damage;
    setHealthpoints(newHealth);

    if(healthpoints <= 0){
        return false;
    }

    return true;
}

UnitType TeamMembers::getType(){
    return type;
}

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

std::vector<MilitaryUnit*> TeamMembers::getMembers()
{
    return std::vector<MilitaryUnit *>();
}

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
