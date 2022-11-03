#include "Cell.h"
Cell::Cell(){
    occupyingForce=NULL;
}
void Cell::removeOccupyingForce() {
    occupyingForce=NULL;
}

void Cell::setOccupyingForce(Squad* m) {
    occupyingForce=m;
}

Squad* Cell::getOccupyingForce(){
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