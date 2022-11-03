#ifndef FLATLANDS_H
#define FLATLANDS_H

#include "Cell.h"

class Flatlands : public Cell {
    public:
        void add(Cell * addition);
        void execute(MilitaryUnit * m);
};


#endif //FLATLANDS_H
