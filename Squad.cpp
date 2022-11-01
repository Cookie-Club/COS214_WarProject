/**
    \file Squad.cpp
    \brief Implements Squad class methods
    \authors Wian Koekemoer
    \date 30/10/22
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
}

void Squad::moveSquad()
{

    /*
    
        Algorithm to select cell goes here

    */

    if(belongsTo->getState()->getType() == Agg){
        if(Ammo > 50){
            //callInBombardment();
        }
        

    }
    else if(belongsTo->getState()->getType() == Def){
        
    }

    // Calculate total resource consumption
    int rationsConsumed = 0;
    float fuelConsumed = 0;
    std::vector<MilitaryUnit*>::iterator it = members.begin();
    for (; it != members.end(); ++it) 
    {
        switch(((TeamMembers*)(*it))->getType())
        {
            case infantry: // Can change ration consuption based on cell type
                rationsConsumed += ((Infantry*)(*it))->getRationConsumption();
                break;
            case tank: // Can change fuel consuption based on cell type
                fuelConsumed += ((Tank*)(*it))->getFuelConsumption();
                break;
            default:
                break;
        }
    }

    
    // Consume resources
    fuel -= fuelConsumed;
    rations -= rationsConsumed;
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

bool Squad::receiveDamage(int damage)
{
    std::vector<MilitaryUnit*>::iterator it = members.begin();
    for (; it != members.end(); ++it) 
    {
        if ((*it)->receiveDamage(damage))
            members.erase(it);
        
    }
    if (members.size() <= 0) return true;
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