#include "Participants.h"
#include "Squad.h"
Participants::Participants(){}

void Participants::retreatParticipants(){
    retreat(atBack());
}

int Participants::getTotalHealthPoints(){
    int total = 0;
    std::vector<MilitaryUnit*>::iterator it = army.begin();
    for (; it != army.end(); ++it)
    {
        total += (*it)->getHealthpoints();
    }
    return total;
}

int Participants::getTotalDamage(){
    int total = 0;
    std::vector<MilitaryUnit*>::iterator it = army.begin();
    for (; it != army.end(); ++it)
    {
        total += (*it)->getDamage();
    }
    return total;
}

string Participants::getName(){
    return name;
}

void Participants::addUnit(MilitaryUnit* m)
{
    if (m->isLeaf())
    {
        Squad* temp = new Squad(this);
        temp->addMember(m);
        m = temp;
    }
    army.push_back(m);
}

std::vector<MilitaryUnit*> Participants::getArmy()
{
    return army;
}

WorldMap *Participants::getMap() {
    return map;
}

void Participants::setMap(WorldMap *map) {
    Participants::map = map;
}

Participant Participants::getParticipant()  {
    return participant;
}
void Participants::removeMilitaryUnit(MilitaryUnit* m)
{

}
