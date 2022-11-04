/**
    \todo Finish the last else statement
*/
#include "Mining.h"

void Mining::execute(Squad* s)
{
    int newX;//new x coordinate of s
    if(s->getParticipant()==Allied){
        newX=s->getOccupyingCell()->getX()+3;//if allied, move 3 right
    }else{
        newX=s->getOccupyingCell()->getX()-3;//if central, move 3 left
    }
    int y=s->getOccupyingCell()->getY();//y coordinate of s

    WorldMap* m=s->getMap();
    if(newX<m->getSize()&&newX>=0&&y<m->getSize()&&y>=0) {
        Cell*** grid = m->getGrid();
        Cell* newCell = grid[newX][y];
        Cell* currentCell=s->getOccupyingCell();
        //if the new cell is uncontested
        if (newCell->getOccupyingForce().empty()) {
            s->setOccupyingCell(newCell);
            newCell->setOccupyingForce(s->getMembers());
            std::vector<MilitaryUnit*> m=s->clone()->getMembers(); //clones squad and gets members
            currentCell->setOccupyingForce(m); //leaves behind to defend but they are unable to move forward and attack
        } 
        //else if the new cell is contested
        else 
        {
            vector<MilitaryUnit *> enemyVec = newCell->getOccupyingForce();
            if (s->battle(enemyVec)) {
                s->setOccupyingCell(newCell);
                newCell->setOccupyingForce(s->getMembers());
                std::vector<MilitaryUnit*> m=s->clone()->getMembers();
                currentCell->setOccupyingForce(m);
            }
        }
    }
}
