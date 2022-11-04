#include "Cell.h"
Cell::Cell(){
    // std::cout << "Cell created\n";
    type = "cell";
}


void Cell::removeOccupyingForce(std::vector<MilitaryUnit*> m) {
    std::vector<MilitaryUnit*>::iterator it = m.begin();
    for (; it != m.begin(); ++it)
    {
        std::vector<MilitaryUnit*>::iterator it2 = occupyingForce.begin();
        for (; it2 != occupyingForce.end(); ++it2)
            if (*it2 == *it)
            {
                occupyingForce.erase(it2);
                return;
            }
    }
}

void Cell::removeOccupyingForce(MilitaryUnit* m) {
    std::vector<MilitaryUnit*>::iterator it = occupyingForce.begin();
    for (; it != occupyingForce.end(); ++it)
        if (*it == m)
        {
            occupyingForce.erase(it);
            return;
        }
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

void Cell::printSymbol(std::string s)
{
    int code = 39;
    if (owner) code = (int)owner->getParticipant();
    std::cout << "\033[" << code << "m|\033[0mCel" << s << occupyingForce.size() << "\033[" << code << "m|\033[0m";
}