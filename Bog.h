#ifndef BOG_H
#define BOG_H

#include "Cell.h"

class Bog : public Cell {

public:
    Bog();
    double resourceUseMultiplier;
    void add(Cell * addition){ std::cout << "Cannot add anymore additional resources to this Bog cell" << endl};
};


#endif //BOG_H
