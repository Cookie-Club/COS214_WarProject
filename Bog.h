#ifndef BOG_H
#define BOG_H

#include "Cell.h"
#include "CellState.h"

class Bog : public Cell {

public:
    double resourceUseMultiplier;
    CellState* getState();
    void setState(CellState* state);
};


#endif //BOG_H
