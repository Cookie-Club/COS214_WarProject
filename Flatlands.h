#ifndef FLATLANDS_H
#define FLATLANDS_H

#include "Cell.h"

class Flatlands : public Cell {
public:
    void setState(cellState* state);
    void getState();
};


#endif //FLATLANDS_H
