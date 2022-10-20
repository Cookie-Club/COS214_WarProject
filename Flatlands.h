#ifndef FLATLANDS_H
#define FLATLANDS_H

#include "Cell.h"

class Flatlands : public Cell {
public:
    void getState();
    void setState(CellState* state);
};


#endif //FLATLANDS_H
