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
    Cell*** grid=m->getGrid();
    Cell* newCell=grid[newX][y];
    if(newCell->getOccupyingForce()==NULL){
        s->setOccupyingCell(newCell);
    }else {
        vector<MilitaryUnit*> enemy = newCell->getOccupyingForce();
        while (s->isAlive() && enemy->isAlive()) {
            if (enemy->receiveDamage(s->getAmmo())) {
                s->setOccupyingCell(newCell);
            } else if (s->receiveDamage(enemy->getAmmo())) {
                enemy->setOccupyingCell(newCell);
            }
        }
    }
}
