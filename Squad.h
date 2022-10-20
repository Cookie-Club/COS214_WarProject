
#ifndef SQUAD_H
#define SQUAD_H

#include "MilitaryUnit.h"
#include "Cell.h"
#include <vector>

class Squad : public MilitaryUnit {

    private:
        Cell* occupyingCell;
        std::vector<MilitaryUnit*> members;
        int Ammo;

    public:
        void moveSquad();
        void setOccupyingCell(Cell* c);
        MilitaryUnit* clone();
        bool isLeaf(){return false;};
};


#endif //SQUAD_H
