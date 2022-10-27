
#ifndef SQUAD_H
#define SQUAD_H

#include "TeamMembers.h"
#include "Cell.h"
#include <vector>

class Squad : public MilitaryUnit {

    public:
        Squad();
        void moveSquad();
        void setOccupyingCell(Cell* c);
        MilitaryUnit* clone();
        bool isLeaf();
        void addMember(MilitaryUnit* m);
        virtual std::vector<MilitaryUnit*> getMembers();
        virtual bool receiveDamage(int damage);
    protected:
        Cell* occupyingCell;
        std::vector<MilitaryUnit*> members;
        int Ammo;
        int rations;
        float fuel;
};


#endif //SQUAD_H
