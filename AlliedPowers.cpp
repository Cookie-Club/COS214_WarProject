#include "AlliedPowers.h"

AlliedPowers::AlliedPowers(){
    this->name = "Allied";
    participant = Allied;
}

void AlliedPowers::retreat(std::vector<Cell*> cells) {
    int size = cells.size();

    for (unsigned int i = 0; i < size; i++) {
        int x = cells.at(i)->getX();
        int y = cells.at(i)->getY();


        Cell *** grid = getMap()->getGrid();

        grid[x-1][y]->setOccupyingForce(cells.at(i)->getOccupyingForce());
        std::vector<MilitaryUnit*>::iterator it;
        for(it = cells.at(i)->getOccupyingForce().begin(); it < cells.at(i)->getOccupyingForce().end(); it++){
            ((Squad*)*it)->setOccupyingCell(grid[x-1][y]);
        }
        cells.at(i)->removeOccupyingForce(cells.at(i)->getOccupyingForce());
    }
}

std::vector<Cell*> AlliedPowers::atBack() {
    std::vector<Cell*> notAtBack;
    for(unsigned int i = 0; i < this->ownedTerritories.size(); i++){
        if (this->ownedTerritories.at(i)->getX() > 0){
            notAtBack.push_back(this->ownedTerritories.at(i));
        }
    }
    return notAtBack;
}

