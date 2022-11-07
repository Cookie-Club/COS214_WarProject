#include "Participants.h"
#include "Squad.h"

<<<<<<< Updated upstream
Participants::Participants() {}
=======
Participants::Participants(ParticipantType pT) : participantType(pT) {
    std::cout << participantType << endl;
}
>>>>>>> Stashed changes

Participants::~Participants() {
    for (int x = 0; x < army.size(); ++x) {
        army[x]->setOwner(nullptr);
        delete army[x];
    }
    std::cout << "Participant deleted\n";
}

void Participants::retreatParticipants() {
    retreat(atBack());
}

int Participants::getTotalHealthPoints() {
    int total = 0;
    std::vector<MilitaryUnit *>::iterator it = army.begin();
    for (; it != army.end(); ++it) {
        total += (*it)->getHealthpoints();
    }
    return total;
}

int Participants::getTotalDamage() {
    int total = 0;
    std::vector<MilitaryUnit *>::iterator it = army.begin();
    for (; it != army.end(); ++it) {
        total += (*it)->getDamage();
    }
    return total;
}

string Participants::getName() {
    return name;
}

void Participants::addUnit(MilitaryUnit *m) {
    if (m->isLeaf()) {
        Squad *temp = new Squad(this);
        temp->addMember(m);
        m = temp;
    }
    army.push_back(m);
}

<<<<<<< Updated upstream
std::vector<MilitaryUnit *> Participants::getArmy() {
    return army;
=======
std::vector<MilitaryUnit *> *Participants::getArmy() {
    std::vector < MilitaryUnit * > *temp = &army;
    return temp;
>>>>>>> Stashed changes
}

WorldMap *Participants::getMap() {
    return map;
}

void Participants::setMap(WorldMap *map) {
    Participants::map = map;
    std::vector<MilitaryUnit *>::iterator it = army.begin();
    for (; it != army.end(); ++it) {
        (*it)->setMap(map);
    }
}

<<<<<<< Updated upstream
Participant Participants::getParticipant() {
    return participant;
=======
ParticipantType Participants::getParticipantType() {
    return participantType;
>>>>>>> Stashed changes
}

void Participants::removeMilitaryUnit(MilitaryUnit *m) {
    std::vector<MilitaryUnit *>::iterator it = army.begin();
    for (; it != army.end(); ++it) {
        if (*it == m) {
            (*it)->setOwner(nullptr);
            army.erase(it);
            return;
        }
    }
}
<<<<<<< Updated upstream
=======

std::vector<Cell *> *Participants::getOwnedTerritories() {
    std::vector < Cell * > *temp = &ownedTerritories;
    return temp;
}
>>>>>>> Stashed changes
