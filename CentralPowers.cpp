#include "CentralPowers.h"

CentralPowers::CentralPowers(){
    this->name = "Central";
    participant = Central;
}

void CentralPowers::retreat(std::vector<Cell*> cells) {
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

std::vector<Cell*> CentralPowers::atBack() {
    std::vector<Cell*> notAtBack;
    for(unsigned int i = 0; i < this->ownedTerritories.size(); i++){

        if (this->ownedTerritories.at(i)->getX() < (getMap()->getSize()-1)){
            notAtBack.push_back(this->ownedTerritories.at(i));
        }
    }
    return notAtBack;
}

void CentralPowers::armyMove() {
	std::vector<MilitaryUnit*>::iterator it = army.begin();
    for(; it != army.end(); it++){
        int SquadXCoord = ((Squad*)*it)->getOccupyingCell()->getX();
        int SquadYCoord = ((Squad*)*it)->getOccupyingCell()->getY();

        if(SquadYCoord > 0){
            if(!map->getCell(SquadXCoord, SquadYCoord - 1)->getOccupyingForce().empty()){
                if(map->getCell(SquadXCoord, SquadYCoord - 1)->getOccupyingForce().at(0)->getOwner() == ((Squad*)*it)->getOwner()){
                    ((Squad*)*it)->getOccupyingCell()->removeOccupyingForce(*it);
                    map->getCell(SquadXCoord, SquadYCoord - 1)->setOccupyingForce(*it);
                }
                else{
                    ((Squad*)*it)->attack(SquadXCoord, SquadYCoord - 1);
                }
            }
            else{
                ((Squad*)*it)->getOccupyingCell()->removeOccupyingForce(*it);
                map->getCell(SquadXCoord, SquadYCoord - 1)->setOccupyingForce(*it);
            }
        }
    //remove empty squads
    }
}
