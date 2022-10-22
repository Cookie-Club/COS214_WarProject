    //
// Created by megan on 2022/10/18.
//

#include "Squad.h"
#include "Infantry.h"
#include "Tank.h"
void Squad::moveSquad()
{

    /*
    
        Algorithm to select cell goes here

    */

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
        };
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
    Squad* newSquad = new Squad();
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
}