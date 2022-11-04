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
    //state->setType(Agg);
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
    occupyingCell->setOccupyingForce(this);
}

Squad* Squad::clone()
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
    int i = std::rand() % members.size();
    MilitaryUnit* unluckyWinner = members[i];
    //if unit dies
    
    if(!unluckyWinner->receiveDamage(damage))
    {
        std::vector<MilitaryUnit*>::iterator it = members.begin();
        for (; it != members.end(); ++it)
        {
            if (*it == unluckyWinner)
                members.erase(it);
        }
        delete unluckyWinner;
        return false;
    }
    return true;
}

void Squad::removeSquadMember(MilitaryUnit* member){
    std::vector<MilitaryUnit*>::iterator it = members.begin();
    for (; it != members.end(); ++it)
    {
        if (member == *it){
            delete *it;
            members.erase(it);
            return;
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

void Squad::attack(int x, int y) {
    if(belongsTo->getTotalHealthPoints() > 40 && rations > 50 && fuel > 50){
        delete state;
        state = new Aggressive();
    }
    else{
        delete state;
        state = new Defensive();
    }
    state->handle(this);
    
    if(Ammo > 50){
        callInBombardment(belongsTo->getMap()->getCell(x, y));
    }

    strategy->execute(this);
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
//returns true if it wins battle
bool Squad::battle(std::vector<MilitaryUnit*> enemyMembers){
    ///\todo Rework Squad::battle()
    bool ret;
    std::vector<MilitaryUnit *>::iterator it;
    Participants *en= (enemyMembers.at(0)->getOwner());
    int enHp= en->getTotalHealthPoints();
    int enDam=en->getTotalDamage();
    for (it = enemyMembers.begin(); it < enemyMembers.end(); ++it) {
        while (isAlive() && !enemyMembers.empty()) {
            receiveDamage(enDam);
            int sDam=this->getOwner()->getTotalDamage();
            en->setTotalHealthPoints((enHp-sDam));
            ret=true;
        }
    }
    if(!isAlive()){
        ret=false;
    }
    return ret;
}

Participant Squad::getParticipant() {
    return getOwner()->getParticipant();
}

int Squad::getSquadHealth(){
    int totalHealth;
    std::vector<MilitaryUnit *>::iterator it;
    for(it = members.begin(); it < members.end(); it++){
        totalHealth += ((TeamMembers*)*it)->getHealthpoints();
    }

    return totalHealth;
}

int Squad::getSquadDamage()
{
    int ret = 0;
    std::vector<MilitaryUnit*>::iterator it = members.begin();
    return 0;
}

