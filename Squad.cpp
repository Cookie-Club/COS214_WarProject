#include "Squad.h"

Squad::Squad(){
    type = "squad";
}

void Squad::moveSquad()
{

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