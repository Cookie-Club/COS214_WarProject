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
    //main for loop that runs through the Participants army, calling each squads move function on their iteration
    for(;it < army.end(); it++){
        //check to see if iteration is at the end of the army and if the iterator still exists
        while(!*it && it != army.end()){
            MilitaryUnit * temp = *it;
            it = army.erase(it);
            delete temp;
        }


        std::cout << "Unit ";
        std::cout << ((Squad*)*it)->getName() << " has been selected to move" << endl;

        //current coordinates saved to be used later
        int SquadXCoord = ((Squad*)*it)->getOccupyingCell()->getX();
        int SquadYCoord = ((Squad*)*it)->getOccupyingCell()->getY();
        //Make sure moving is still possible
        if(SquadYCoord < (map->getSize() - 1)){
            //check if the cell is not empty
            if(!map->getCell(SquadXCoord, SquadYCoord + 1)->getOccupyingForce()->empty()){
                //check if friendlies are in the cell next to you
                if(map->getCell(SquadXCoord, SquadYCoord + 1)->getOccupyingForce()->at(0)->getOwner() == ((Squad*)*it)->getOwner()){
                    //join friendly on the cell
                    ((Squad*)*it)->setOccupyingCell(map->getCell(SquadXCoord, SquadYCoord + 1));
                }
                //if enemy detected, current unit will attack
                else{
                    std::cout << "ENEMY ENCOUNERED AT X: " << SquadXCoord << " Y: " << SquadYCoord + 1 << endl; 
                    ((Squad*)*it)->attack(SquadXCoord, SquadYCoord + 1);
                }
            }
            else{
                //else just take over cell
                ((Squad*)*it)->setOccupyingCell(map->getCell(SquadXCoord, SquadYCoord + 1));
            }
        }
        //check to see if squad still has members and if not delete and remove the squad from the army
        if(!((Squad*)*it)->isAlive()){
            MilitaryUnit * temp = *it;
            it = army.erase(it);
            delete temp;
        }
        std::cout << "---------" << endl;
    }
    std::cout << "Allied has finished its turn" << endl;
    //remove empty squads
}

