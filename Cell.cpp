#include "Cell.h"

void Cell::removeOccupyingForce(MilitaryUnit* m) {
 for (auto i = occupyingForce.begin(); i != occupyingForce.end(); ++i) {
        if (*i == m) {
            occupyingForce.erase(i);
            i--;
        }
    }
	// throw "Not yet implemented";
}

void Cell::setOccupyingForce(MilitaryUnit* m) {
	occupyingForce.push_back(m);
	// throw "Not yet implemented";
}

std::vector<MilitaryUnit*> Cell::getOccupyingForce(){
	return occupyingForce;
}

int Cell::getX() {
    return this.x;
}

int Cell::getY() {
    return this.y;
}

void Cell::setCoordinates(int _x, int _y) {
    this.x = _x;
    this.y = _y;
}
