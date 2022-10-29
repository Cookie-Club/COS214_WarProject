#include "TeamMembers.h"

TeamMembers::TeamMembers(int damage, int healthpoints, UnitType type, Participants* belongsTo)
: MilitaryUnit(belongsTo, type)
{
    this->damage = damage;
    this->healthpoints = healthpoints;
}
bool TeamMembers::receiveDamage(int damage)
{
    int newHealth = healthpoints - damage;

    if(newHealth < 0) 
        return false;

    setHealthpoints(newHealth);

    return true;
}

void TeamMembers::setHealthpoints(int hp)
{
    this->healthpoints = hp;
}

bool TeamMembers::isLeaf()
{
    return true;
}

void TeamMembers::setDamage(int damage)
{
    this->damage = damage;
}

std::vector<MilitaryUnit*> getMembers()
{
    return std::vector<MilitaryUnit*>();
}

void TeamMembers::setSquad(Squad* squad)
{
    this->squad = squad;
};