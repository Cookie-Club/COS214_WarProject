#include "AlliedPowers.h"

AlliedPowers::AlliedPowers(ParticipantType pT):Participants(pT){
    this->name = "Allied";
}

void AlliedPowers::retreat(std::vector<Cell *> cells) {
    int size = cells.size();

    for (unsigned int i = 0; i < size; i++) {
        int x = cells.at(i)->getX();
        int y = cells.at(i)->getY();


        Cell ***grid = getMap()->getGrid();

        grid[x - 1][y]->setOccupyingForce(*(cells.at(i)->getOccupyingForce()));
        std::vector<MilitaryUnit *>::iterator it;
        for (it = cells.at(i)->getOccupyingForce()->begin(); it < cells.at(i)->getOccupyingForce()->end(); it++) {
            ((Squad *) *it)->setOccupyingCell(grid[x - 1][y]);
        }
        cells.at(i)->removeOccupyingForce(*(cells.at(i)->getOccupyingForce()));
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
    std::cout << "Allied is moving troops" << endl;
	std::vector<MilitaryUnit*>::iterator it = army.begin();
    for(;it < army.end(); it++){
        std::cout << army.size();
        std::cout << "Inside Allied for loop" << endl;
        while(!*it && it != army.end()){
            MilitaryUnit * temp = *it;
            it = army.erase(it);
            std::cout << "Calling delete from AlliedPowers:46\n";
            delete temp;
        }

        if(it == army.end()){
            std::cout << "Ain't no army Allied" << endl;
            return;
        }

        std::cout << "Unit ";
        std::cout << ((Squad*)*it)->getName() << " has been selected to move" << endl;

        
        int SquadXCoord = ((Squad*)*it)->getOccupyingCell()->getX();
        int SquadYCoord = ((Squad*)*it)->getOccupyingCell()->getY();
        if(SquadYCoord < (map->getSize() - 1)){
            if(!map->getCell(SquadXCoord, SquadYCoord + 1)->getOccupyingForce()->empty()){
                if(map->getCell(SquadXCoord, SquadYCoord + 1)->getOccupyingForce()->at(0)->getOwner() == ((Squad*)*it)->getOwner()){
                    ((Squad*)*it)->setOccupyingCell(map->getCell(SquadXCoord, SquadYCoord + 1));
                }
                else{
                    std::cout << "ENEMY ENCOUNERED AT X: " << SquadXCoord << " Y: " << SquadYCoord + 1 << endl; 
                    ((Squad*)*it)->attack(SquadXCoord, SquadYCoord + 1);
                }
            }
            else{
                ((Squad*)*it)->setOccupyingCell(map->getCell(SquadXCoord, SquadYCoord + 1));
            }
        }
        if(!((Squad*)*it)->isAlive()){
            std::cout << "Deleting squad " << ((Squad*)*it)->getName() << " in Allied Powers" << endl;
            MilitaryUnit * temp = *it;
            it = army.erase(it);
            std::cout << "Calling delete from AlliedPowers:78\n";
            delete temp;

            std::vector<MilitaryUnit*>::iterator it2;
            for(it2 = army.begin(); it2 != army.end(); it2++){
                if(*it == *it2){
                    std::cout << "Squad" << ((Squad*)*it2)->getName() << " was not deleted";
                    break;
                }
            }
        }
        std::cout << "---------" << endl;
    }
    std::cout << "Allied has finished its turn" << endl;
    //remove empty squads
}

