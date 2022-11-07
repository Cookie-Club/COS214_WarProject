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
    belongsTo->getArmy()->push_back(this);
    state = new Aggressive();
    std::cout << belongsTo->getParticipantType();
    fuel = 100;
    rations = 100;
    Ammo = 100;
} 

Squad::~Squad() {
    MilitaryUnit *temp = nullptr;
    std::vector<MilitaryUnit *>::iterator it;
    for (it = this->members.begin(); it != this->members.end();) {
        temp = *it;
        this->members.erase(it);
        delete temp;
    }
    if (belongsTo != nullptr) belongsTo->removeMilitaryUnit(this);
    if (occupyingCell != nullptr) occupyingCell->removeOccupyingForce(this);
    std::cout << "Squad Deleted\n";
}


void Squad::setOccupyingCell(Cell* c)
{
    std::cout << "Setting occupying cell to " << c->getX() << " " << c->getY() << endl;
    if (occupyingCell != nullptr) occupyingCell->removeOccupyingForce(this);
    this->occupyingCell = c;
    if (c != nullptr) occupyingCell->setOccupyingForce(this);
}

Squad* Squad::clone()
{
    Squad* newSquad = new Squad(this->getOwner());
    std::vector<MilitaryUnit*>::iterator it = members.begin();
    for (; it != members.end(); ++it) newSquad->addMember((*it)->clone());
    return newSquad;
}

bool Squad::isLeaf() {
    return false;
}

bool Squad::isAlive() {
    return (members.size() > 0);
}

void Squad::addMember(MilitaryUnit *m) {
    std::vector<MilitaryUnit *>::iterator it = members.begin();
    //Ensure unit not already in squad
    while (it != members.end()) {
        if ((*it) == m)
            return;

        ++it;
    }
    members.push_back(m);
    ((TeamMembers *) m)->setSquad(this);
}

std::vector<MilitaryUnit *> Squad::getMembers() {
    return members;
}

bool Squad::receiveDamage(int damage) {
    int dividedDamage = damage / members.size();
    for (int x = 0; x < members.size(); ++x) {
        if (!members[x]->receiveDamage(dividedDamage)) {
            this->removeSquadMember(members[x]);
            --x;//Would skip next unit object otherwise
        }
    }
    return this->isAlive();
}

void Squad::removeSquadMember(MilitaryUnit *member) {
    std::cout << "in removeSquadMember\n";
    MilitaryUnit* temp;
    std::vector<MilitaryUnit*>::iterator it = members.begin();
    for (; it != members.end(); ++it)
    {
        if (member == *it){
            std::cout << "Member found, being removed" << endl;
            temp = *it;
            members.erase(it);
            delete temp;
            std::cout << "Member has been removed" << endl;
            return;
        }
    }
}

void Squad::callInBombardment(Cell *targetedCell) {
    Order *bomb = new Bombardment(targetedCell);
    bomb->execute();
    delete bomb;
}

Action *Squad::getState() {
    return state;
}

void Squad::setState(Action *state) {
    this->state = state;
}

attackStrategy *Squad::getStrategy() {
    return strategy;
}

void Squad::setStrategy(attackStrategy *aStrat) {
    this->strategy = aStrat;
}

void Squad::attack(int x, int y) {
    std::cout << "Attack commencing" << endl;
    if(belongsTo->getTotalHealthPoints() > 40 && rations > 50 && fuel > 50){
        if (state != nullptr) delete state;
        state = new Aggressive();
    } else {
        if (state != nullptr) delete state;
        state = new Defensive();
    }
    state->handle(this);
    
    if(Ammo > 50){
        std::cout << "Bombardment called in! Soften em' up lads" << endl;
        callInBombardment(belongsTo->getMap()->getCell(x, y));
    }

    strategy->execute(this);
}

int Squad::getAmmo() {
    return Ammo;
}

void Squad::setAmmo(int ammo) {
    this->Ammo = ammo;
}

int Squad::getFuel() {
    return fuel;
}

void Squad::setFuel(int fuel) {
    this->fuel = fuel;
}

int Squad::getRations() {
    return rations;
}

void Squad::setRations(int rations) {
    this->rations = rations;
}

//returns true if it wins battle
bool Squad::battle(std::vector<MilitaryUnit *> enemyMembers) {
    ///\todo Rework Squad::battle()

    //To iterate through enemy vector
    std::vector<MilitaryUnit *>::iterator it;

    //Damage of enemy unit
    int enHp;
    //Health of enemy unit
    int enDam;
    //Damage of current Squad
    int sDam;
    //for-loop iterates through enemy units while Squad lives
    for (it = enemyMembers.begin(); it < enemyMembers.end() && this->isAlive(); ++it) {
        enDam = (*it)->getDamage();//Get damage of enemy unit
        while (this->isAlive() && (*it)->isAlive()) {
            //deals enemy damage to this squad
            this->receiveDamage(enDam);
            //Get total damage of Squad's members
            sDam = this->getDamage();
            //Deals this squads damage to enemy unit
            (*it)->receiveDamage(sDam);
        }
    }

    return this->isAlive();
}

int Squad::getSquadHealth() {
    int totalHealth;
    std::vector<MilitaryUnit *>::iterator it;
    for (it = members.begin(); it < members.end(); it++) {
        totalHealth += ((TeamMembers *) *it)->getHealthpoints();
    }

    return totalHealth;
}

int Squad::getSquadDamage() {
    int ret = 0;
    std::vector<MilitaryUnit *>::iterator it = members.begin();
    return 0;
}

int Squad::getDamage() {
    int total = 0;
    std::vector<MilitaryUnit *>::iterator it = members.begin();
    for (; it != members.end(); ++it) {
        total += (*it)->getDamage();
    }
    return total;
}

int Squad::getHealthpoints() {
    int total = 0;
    std::vector<MilitaryUnit *>::iterator it = members.begin();
    for (; it != members.end(); ++it) {
        total += (*it)->getHealthpoints();
    }
    return total;
}

void Squad::setMap(WorldMap *map) {
    std::vector<MilitaryUnit *>::iterator it = members.begin();
    for (; it != members.end(); ++it) (*it)->setMap(map);
}
