#include "Cell.h"

Cell::Cell(){}

void Cell::removeOccupyingForce() {
    std::vector<MilitaryUnit*>::iterator it;
    for(it = occupyingForce.begin(); it != occupyingForce.end(); it++){
            occupyingForce.erase(it);
    }
}

void Cell::setOccupyingForce(std::vector<MilitaryUnit*> m) {
    occupyingForce=m;
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