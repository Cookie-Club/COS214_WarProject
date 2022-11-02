#ifndef FLATLANDS_H
#define FLATLANDS_H

#include "Cell.h"

class Flatlands : public Cell {
    public:
        void add(Cell * addition){ std::cout << "Cannot add anymore additional resources to this Flatland cell" << endl};
        void execute(MilitaryUnit * m);
};


#endif //FLATLANDS_H
