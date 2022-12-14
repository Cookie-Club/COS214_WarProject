/**
    \file TeamMembers.cpp
    \brief Implements TeamMembers class methods
    \authors Wian Koekemoer
    \date 30/10/22
*/
#include "TeamMembers.h"

TeamMembers::TeamMembers(int damage, int healthpoints, UnitType type, Participants *belongsTo) 
: MilitaryUnit(belongsTo,type) {
    this->damage = damage;
    this->healthpoints = healthpoints;
}

bool TeamMembers::receiveDamage(int damage)
{
    std::cout << "Damage recieved by team member: " << damage << endl;
    healthpoints-= damage;
    return (healthpoints > 0);
}

void TeamMembers::setHealthpoints(int healthpoints) {
    this->healthpoints = healthpoints;
}

bool TeamMembers::isLeaf() {
    return true;
}

bool TeamMembers::isAlive() {
    return (healthpoints > 0);
}

int TeamMembers::getHealthpoints() {
    return healthpoints;
}

int TeamMembers::getDamage() {
    return damage;
}

void TeamMembers::setDamage(int damage) {
    this->damage = damage;
}

std::vector<MilitaryUnit *> getMembers() {
    return std::vector<MilitaryUnit *>();
}