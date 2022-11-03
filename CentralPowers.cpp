#include "CentralPowers.h"

CentralPowers::CentralPowers(){
    this->name = "Central";
}

void CentralPowers::retreat(std::vector<Cell*>) {
    int size = cells.size();

    for (unsigned int i = 0; i < size; i++) {
        int x = cells.at(i).getX();
        int y = cells.at(i).getY();

        WorldMap *map = getMap();

        map[x - 1][y].setOccupyingForce(cells.at(i).getOccupyingForce());
        cells.at(i).getOccupyingForce().setOccupyingCell(map[x - 1][y]);
        cells.at(i).removeOccupyingForce();
}

std::vector<Cell*> CentralPowers::atBack() {
    std::vector <Cell> notAtBack;
    for(unsigned int i = 0; i < this->ownedTerritories.size(); i++){
        if (this->ownedTerritories.at(i).getX() < (getMap().getSize()-1){
            std::notAtBack.push_back(this.ownedTerritories.at(i));
        }
    }
    return notAtBack;
}