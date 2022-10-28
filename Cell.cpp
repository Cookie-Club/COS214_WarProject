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