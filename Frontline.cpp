#include "Frontline.h"

void Frontline::execute(Squad* s)
{
    std::cout << "Frontline attack commencing" << endl;
    int newY;
    if(s->getParticipantType()==Allied){
        //If Allied go right
        std::cout << "Allied troop attacking right" << endl;
        newY=s->getOccupyingCell()->getY()+1;
    }else{
        //If Central go left
        std::cout << "Central troop attacking left" << endl;
        newY=s->getOccupyingCell()->getY()-1;
    }

    std::cout << "Commencing attack" << endl;
    //x-coordinate does not change
    int x=s->getOccupyingCell()->getX();
    //get WorldMap to find newCell
    WorldMap *m = s->getMap();
    //If new coordinates are within bounds
    if(newY < m->getSize() && x < m->getSize()) {
        std::cout << "Selected cell is valid" << endl;
        //Get new cell
        Cell*** grid = m->getGrid();
        Cell* newCell = grid[x][newY];
        std::cout << 1 << endl;
        //Get current cell
        Cell *currentCell = s->getOccupyingCell();

        //If newCell is occupied
        if (!newCell->getOccupyingForce()->empty() && s->getParticipantType() != (newCell->getOccupyingForce())->at(newCell->getOccupyingForce()->size() - 1)->getParticipantType())
        {
            std::cout << 2 << endl;
            //Get vector of enemy units
            vector<MilitaryUnit *> enemyVec = *(newCell->getOccupyingForce());

            std::cout << 3 << endl;
            //Fight! Fight! Fight!
            s->battle(enemyVec);
            std::cout << "Battle is finished" << endl;
            if(s->isAlive()) std::cout << s->getName() << " was victorious" << endl;
            else std::cout << "Squad " << s->getName() << " met Death" << endl;
        }

        //If squad still alive (Automatically true if newCell was empty)
        if (s->isAlive()) { 
            //clones squad
            /**
             * \todo Add cloning
            */
            // Squad *m = s->clone();
            // m->setOccupyingCell(currentCell);
            //Set newCell as occupyingCell of squad
            s->setOccupyingCell(newCell);
            //Setting belongsTo to nullptr avoids potential segfaults in the event
            // that the cell deletes the unit after its owner was deleted
            //m->setOwner(nullptr);
            //leaves clone behind to defend, but its owner does not have visibility 
            // to it and it can thus not be moved via aParticipants::moveArmy()
        }
    }
}
