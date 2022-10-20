#ifndef CELLFEATURES_H
#define CELLFEATURES_H

#include "Cell.h"

class CellFeatures : public Cell {


public:
    CellFeatures();
    void add(Cell* feature);
    ~CellFeatures();

};

#endif //CELLFEATURES_H
