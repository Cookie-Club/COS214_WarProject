#include "CentralPowers.h"

CentralPowers::CentralPowers(){
    this->name = "Central";
}

void CentralPowers::retreat() {

}

std::vector<Cell> CentralPowers::atBack() {
    std::vector<Cell> notAtBack;
    for(unsigned int i = 0; i < this->ownedTerritories.size(); i++){
        if (this->ownedTerritories.at(i)->getX() < this->ownedTerritories.at(i)->getMapSize()){// how would we get the coordinates of the cell?
            std::notAtBack.push_back(this.ownedTerritories.at(i));
        }
    }
    return notAtBack;
}