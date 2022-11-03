#include "AlliedPowers.h"

AlliedPowers::AlliedPowers(){
    this->name = "Allied";
}

void AlliedPowers::retreat(std::vector<Cell*> cells) {
    int size = cells.size();

    for (unsigned int i = 0; i < size; i++) {
        int x = cells.at(i)->getX();
        int y = cells.at(i)->getY();

        Cell***grid = getMap()->getGrid();
        Cell* c=grid[x-1][y];
        c->setOccupyingForce(cells.at(i)->getOccupyingForce());
     //   cells.at(i)->getOccupyingForce()->setOccupyingCell(c);
        cells.at(i)->removeOccupyingForce();
    }
}

vector<Cell *> AlliedPowers::atBack() {
    std::vector <Cell*> notAtBack;

    for(unsigned int i = 0; i < this->ownedTerritories.size(); i++){
        if (this->ownedTerritories.at(i)->getX() > 0){
            notAtBack.push_back(this->ownedTerritories.at(i));
        }
    }
    return notAtBack;
}

