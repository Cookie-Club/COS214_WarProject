#ifndef BOG_H
#define BOG_H

#include "Cell.h"

class Bog : public Cell {
    public:
        Bog();
        void add(Cell * addition){ std::cout << "Cannot add anymore additional resources to this Bog cell" << endl;};
        void execute(MilitaryUnit * m);
    private:
        double resourceUseMultiplier;
};


#endif //BOG_H
