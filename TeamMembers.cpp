#include "TeamMembers.h"

/**
    \fn Squad::receiveDamage
    \brief Reduces unit healthpoints
    \details Receives damage as a parameter and subtracts it from the unit's healthpoints.
    Returns true if the unit died, and false if otherwise
*/
bool TeamMembers::receiveDamage(int damage){
    int newHealth = healthpoints - damage;
    setHealthpoints(newHealth);

    if(healthpoints > 0){
        return false;
    }

    return true;
}

/**
    \fn TeamMembers:setHealthpoints
    \brief Setter for healthpoints variable
*/
void TeamMembers::setHealthpoints(int hp)
{
    this->healthpoints = hp;
}

/**
    \fn TeamMembers::isLeaf
    \brief Returns true to communicate object is leaf in Composite structure
*/
bool TeamMembers::isLeaf()
{
    return true;
}

/**
    \fn TeamMembers::setDamage
    \brief Setter for damage
*/
void TeamMembers::setDamage(int damage)
{
    this->damage = damage;
}