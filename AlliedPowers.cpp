#include "AlliedPowers.h"

AlliedPowers::AlliedPowers() {
    this->name = "Allied";
    participant = Allied;
}

void AlliedPowers::retreat(std::vector<Cell *> cells) {
    int size = cells.size();

    for (unsigned int i = 0; i < size; i++) {
        int x = cells.at(i)->getX();
        int y = cells.at(i)->getY();


        Cell ***grid = getMap()->getGrid();

        grid[x - 1][y]->setOccupyingForce(cells.at(i)->getOccupyingForce());
        std::vector<MilitaryUnit *>::iterator it;
        for (it = cells.at(i)->getOccupyingForce().begin(); it < cells.at(i)->getOccupyingForce().end(); it++) {
            ((Squad *) *it)->setOccupyingCell(grid[x - 1][y]);
        }
        cells.at(i)->removeOccupyingForce(cells.at(i)->getOccupyingForce());
    }
}

std::vector<Cell *> AlliedPowers::atBack() {
    std::vector < Cell * > notAtBack;
    for (unsigned int i = 0; i < this->ownedTerritories.size(); i++) {
        if (this->ownedTerritories.at(i)->getX() > 0) {  //Checks if the cell is not on the edge of the map
            notAtBack.push_back(this->ownedTerritories.at(i)); //pushes cell onto vector if not on edge
        }
    }
    return notAtBack;
}

void AlliedPowers::armyMove() {
    std::vector<MilitaryUnit *>::iterator it;

    for (it = army.begin(); it < army.end(); it++) {
        int SquadXCoord = ((Squad *) *it)->getOccupyingCell()->getX();
        int SquadYCoord = ((Squad *) *it)->getOccupyingCell()->getY();
        if (SquadXCoord > 0) {
            if (!map->getCell(SquadXCoord + 1, SquadYCoord)->getOccupyingForce().empty()) {
                ((Squad *) *it)->attack(SquadXCoord - 1, SquadYCoord);
            }
        }
    }

    //remove empty squads
}

