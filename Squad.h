
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
        Squad();
        void moveSquad();
        void setOccupyingCell(Cell* c);
        MilitaryUnit* clone();
        bool isLeaf();
        void addMember(MilitaryUnit* m);
};


#endif //SQUAD_H
