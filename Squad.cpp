#include "Squad.h"
#include "Infantry.h"
#include "Tank.h"

/**
    \fn Squad::Squad
    \brief Default constructor
    \details Sets type to Squad
*/
Squad::Squad(){
    this->type = squad;
}
/**
    \fn Squad::moveSquad
    \brief Select cell to move to
*/
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
/**
    \fn Squad::setOccupyingCell
    \brief Stores the cell on which the squad is located
    \details Receives a cell reference
    Requests old cell to remove the squad from its occupying forces variable
    Saves cell reference that was passed as parameter
    Requests that new cell add the squad to its occupying forces variable
*/
void Squad::setOccupyingCell(Cell* c)
{
    this->occupyingCell->removeOccupyingForce(this);
    this->occupyingCell = c;
    c->setOccupyingForce(this);
}

/**
    \fn Squad::clone
    \brief Clone operation of Prototype pattern
    \details Creates and returns a copy of the Squad composite structure and its TeamMembers
*/
MilitaryUnit* Squad::clone()
{
    Squad* newSquad = new Squad();
    std::vector<MilitaryUnit*>::iterator it = members.begin();
    for (; it != members.end(); ++it) newSquad->addMember((*it)->clone());
    return newSquad;
}

/**
    \fn Squad::isLeaf
    \brief Returns false to communicate object is not a leaf in Composite structure
*/
bool Squad::isLeaf()
{
    return false;
}

/**
    \fn Squad::addMember
    \brief Expands members variable
    \details Adds parameter to members vector
*/
void Squad::addMember(MilitaryUnit* m)
{
    members.push_back(m);
}

/**
    \fn Squad::getMembers
    \brief Returns members vector
*/
std::vector<MilitaryUnit*> Squad::getMembers(){
    return members;
}

/**
    \fn Squad::receiveDamage
    \brief Receives damage
    \details Receives damage input, and distributes it among members, returning bool value that represents whether squad died
*/
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