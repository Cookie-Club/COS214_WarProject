#ifndef SQUAD_H
#define SQUAD_H

#include "MilitaryUnit.h"
#include "Cell.h"

class Squad : public MilitaryUnit {

private:
    Cell* occupyingCell;
    MilitaryUnit* members;
    int Ammo;

public:
    void moveSquad();
    void setOccupyingCell();
};


#endif //SQUAD_H
