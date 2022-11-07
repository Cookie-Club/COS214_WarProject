/**
    \todo Finish the last else statement
*/
#include "Mining.h"

void Mining::execute(Squad* s)
{
    int newX;
    if(s->getParticipant()==Allied){
        //If allied, move 3 right
        newX=s->getOccupyingCell()->getX()+3;
    }else{
        //If central, move 3 left
        newX=s->getOccupyingCell()->getX()-3;
    }
    //Y-coordinate does not change
    int y=s->getOccupyingCell()->getY();
    //get WorldMap to find newCell
    WorldMap* m=s->getMap();
    //If new coordinates are within bounds
    if(newX < m->getSize() && newX >= 0 && y < m->getSize() && y >=0) {
        //Get new cell
        Cell*** grid = m->getGrid();
        Cell* newCell = grid[newX][y];
        //Get current cell
        Cell* currentCell=s->getOccupyingCell();

        //If newCell is occupied
        if (!newCell->getOccupyingForce().empty())
        {
            //Get vector of enemy units
            vector<MilitaryUnit *> enemyVec = newCell->getOccupyingForce();
            //Fight! Fight! Fight!
            s->battle(enemyVec);
        }
        //If squad still alive (Automatically true if newCell was empty)
        if(s->isAlive())
        {
            //Set newCell as occupyingCell of squad
            s->setOccupyingCell(newCell);
            //Add squad to occupyingForce vector of new cell
            newCell->setOccupyingForce(s);
            //clones squad
            Squad* m=s->clone(); 
            //Setting belongsTo to nullptr avoids potential segfaults in the event
            // that the cell deletes the unit after its owner was deleted
            m->setOwner(nullptr);
            //leaves clone behind to defend, but its owner does not have visibility 
            // to it and it can thus not be moved via aParticipants::moveArmy()
            currentCell->setOccupyingForce(m); 
        }
    }
}
