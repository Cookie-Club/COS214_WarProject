#include "Cell.h"

Cell::Cell(){}

void Cell::removeOccupyingForce(MilitaryUnit* m) {
    std::vector<MilitaryUnit*>::iterator it;
    for(it = occupyingForce.begin(); it != occupyingForce.end(); it++){
        if(*it == m){
            occupyingForce.erase(it);
        }
    }
}

void Cell::removeOccupyingForce(std::vector<MilitaryUnit*> m) {
    occupyingForce.clear();
}

void Cell::setOccupyingForce(MilitaryUnit* m) {
    occupyingForce.push_back(m);
}

void Cell::setOccupyingForce(std::vector<MilitaryUnit*> m) {
    std::vector<MilitaryUnit*>::iterator it;
    for(it = m.begin(); it < m.end(); it++){
        occupyingForce.push_back(*it);
    }
}

std::vector<MilitaryUnit*> Cell::getOccupyingForce(){
    return occupyingForce;
}

int Cell::getX() {
    return this->x;
}

int Cell::getY() {
    return this->y;
}

void Cell::setCoordinates(int _x, int _y) {
    this->x = _x;
    this->y = _y;
}