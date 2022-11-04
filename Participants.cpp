#include "Participants.h"

Participants::Participants(){}

void Participants::retreatParticipants(){
    retreat(atBack());
}

int Participants::getTotalHealthPoints(){
    return totalHealthPoints;
}

void Participants::setTotalHealthPoints(int hp) {
}

int Participants::getTotalDamage(){
    return totalDamage;
}

void Participants::setTotalDamage() {}

string Participants::getName(){
    return name;
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
