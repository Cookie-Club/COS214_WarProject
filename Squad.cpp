/**
    \file Squad.cpp
    \brief Implements Squad class methods
    \authors Wian Koekemoer
    \date 30/10/22
    \todo figure out which cell to call bombardment on in attack() method
*/
#include "Squad.h"
#include "Infantry.h"
#include "Tank.h"
#include "Enumerations.h"

Squad::Squad(Participants* belongsTo):MilitaryUnit(belongsTo, UnitType::squad)
{
    belongsTo->getArmy().push_back(this);
}

Squad::~Squad()
{
    MilitaryUnit* temp = nullptr;
    std::vector<MilitaryUnit*>:: iterator it;
    for (it = this->members.begin(); it != this->members.end(); ++it)
    {
        temp = *it;
        this->members.erase(it);
        delete temp;
    }
    if (belongsTo) belongsTo->removeMilitaryUnit(this);
    if (occupyingCell) occupyingCell->removeOccupyingForce(this);
}
void Squad::setOccupyingCell(Cell* c)
{
    this->occupyingCell->removeOccupyingForce(this);
    this->occupyingCell = c;
    c->setOccupyingForce(this);
}

MilitaryUnit* Squad::clone()
{
    Squad* newSquad = new Squad(this->getOwner());
    std::vector<MilitaryUnit*>::iterator it = members.begin();
    for (; it != members.end(); ++it) newSquad->addMember((*it)->clone());
    return newSquad;
}

bool Squad::isLeaf()
{
    return false;
}

void Squad::addMember(MilitaryUnit* m)
{
    members.push_back(m);
    ((TeamMembers*)m)->setSquad(this);
}

std::vector<MilitaryUnit*> Squad::getMembers(){
    return members;
}

bool Squad::receiveDamage(int damage) // @kaitlyn fix this
{
    std::vector<MilitaryUnit*>::iterator it = members.begin();
    for (; it != members.end(); ++it)
    {
        if ((*it)->receiveDamage(damage))
            members.erase(it);

    }
    if (members.size() <= 0) {
        return true;
    }
    return false;
}

void Squad::removeSquadMember(MilitaryUnit* member){
    std::vector<MilitaryUnit*>::iterator it = members.begin();
    for (; it != members.end(); ++it)
    {
        if (member == *it){
            members.erase(it);
            return;
        }
    }

    if(members.size() == 0){
        std::vector<MilitaryUnit*>::iterator it = members.begin();
        for (; it != this->getOwner()->getArmy().end(); ++it)
        {
            if (this == *it){
                belongsTo->getArmy().erase(it);
                return;
            }
        }
    }
}

void Squad::callInBombardment(Cell * targetedCell)
{
    Order * bomb = new Bombardment(targetedCell);
    bomb->execute();
    delete bomb;
}

Action *Squad::getState() {
    return state;
}

void Squad::setState(Action* state) {
    this->state = state;
}

attackStrategy* Squad::getStrategy()  
{
    return strategy;
}

void Squad::setStrategy(attackStrategy * aStrat){
    this->strategy = aStrat;
}

void Squad::attack() {
    state->handle(this);
    strategy->execute(this);
    if(Ammo > 50){
        //callInBombardment();
    }
}

bool Squad::isAlive()  
{
    return (members.size() > 0);
}

int Squad::getAmmo()
{
    return Ammo;
}

void Squad::setAmmo(int ammo)
{
    this->Ammo = ammo;
}

int Squad::getFuel()
{
    return fuel;
}

void Squad::setFuel(int fuel)
{
    this->fuel = fuel;
}

int Squad::getRations()
{
    return rations;
}

void Squad::setRations(int rations)
{
    this->rations = rations;
}

Cell* Squad::getOccupyingCell()  
{
    return occupyingCell;
}
