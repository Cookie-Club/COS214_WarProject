#include "Participants.h"

void Participants::armyMove() {
	/// @todo - implement Participants::armyMove
	// throw "Not yet implemented";
    std::cout << "Army has moved\n";
}


void Participants::templateMethod(){
    // //If not at the back of the board then retreat
    // // how to know if it is at the back -> function for each side?
    // std::vector<Cell *> vector = atBack();
    // for (int i; i < vector.size(); i++){
    //     retreat(vector.at(i));
    // }
}




int Participants::getTotalHealthPoints(){
    return totalHealthPoints;
}

void Participants::setTotalHealthPoints() {
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

void Participants::sendMap() {
    army.at(0)->setMap(map);
}

Participant Participants::getParticipant()  {
    return participant;
}
void Participants::removeMilitaryUnit(MilitaryUnit* m)
{

}
