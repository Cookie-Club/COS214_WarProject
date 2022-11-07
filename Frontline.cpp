#include "Frontline.h"

void Frontline::execute(Squad *s) {
    int newX;
    if (s->getParticipant() == Allied) {
        //If Allied go right
        newX = s->getOccupyingCell()->getX() + 1;
    } else {
        //If Central go left
        newX = s->getOccupyingCell()->getX() - 1;
    }
    //Y-coordinate does not change
    int y = s->getOccupyingCell()->getY();
    //get WorldMap to find newCell
    WorldMap *m = s->getMap();
    //If new coordinates are within bounds
    if (newX < m->getSize() && y < m->getSize()) {
        //Get new cell
        Cell ***grid = m->getGrid();
        Cell *newCell = grid[newX][y];
        //Get current cell
        Cell *currentCell = s->getOccupyingCell();

        //If newCell is occupied
        if (!newCell->getOccupyingForce().empty()) {
            //Get vector of enemy units
            vector < MilitaryUnit * > enemyVec = newCell->getOccupyingForce();
            //Fight! Fight! Fight!
            s->battle(enemyVec);
        }
        //If squad still alive (Automatically true if newCell was empty)
        if (s->isAlive()) {
            //Set newCell as occupyingCell of squad
            s->setOccupyingCell(newCell);
            //Add squad to occupyingForce vector of new cell
            newCell->setOccupyingForce(s);
            //clones squad
            Squad *m = s->clone();
            //Setting belongsTo to nullptr avoids potential segfaults in the event
            // that the cell deletes the unit after its owner was deleted
            m->setOwner(nullptr);
            //leaves clone behind to defend, but its owner does not have visibility 
            // to it and it can thus not be moved via aParticipants::moveArmy()
            currentCell->setOccupyingForce(m);
        }
    }
}
