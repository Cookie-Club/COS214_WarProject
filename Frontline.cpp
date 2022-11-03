/**
    \todo Finish the last else statement
*/
#include "Frontline.h"

void Frontline::execute(Squad* s)
{
    int newX;
    if(s->getParticipant()==Allied){
        newX=s->getOccupyingCell()->getX()+1;
    }else{
        newX=s->getOccupyingCell()->getX()-1;
    }
    int y=s->getOccupyingCell()->getY();

    WorldMap* m=s->getMap();
    if(newX<m->getSize()&&y<m->getSize()) {
        Cell ***grid = m->getGrid();
        Cell *newCell = grid[newX][y];
        Cell* currentCell=s->getOccupyingCell();
        if (newCell->getOccupyingForce().empty()) {
            s->setOccupyingCell(newCell);
            newCell->setOccupyingForce(s->getMembers());
            std::vector<MilitaryUnit*> m=s->clone()->getMembers(); //clones squad and gets members
            currentCell->setOccupyingForce(m); //leaves behind to defend but they are unable to move forward and attack
        } else {
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
