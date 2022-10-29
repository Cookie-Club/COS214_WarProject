/**
    \file CellFeatures.h
    \brief Details the specifics of a Cell.
    \details Provides an abstract interface for creating the specific
    Factory: Product
    Decorator: Decorator 
    \ingroup FeatureFactory
    \author Megan Hugo
*/
#ifndef CELLFEATURES_H
#define CELLFEATURES_H

#include "Cell.h"

class CellFeatures : public Cell {


public:
    CellFeatures();
    void setState(CellState *state);
    CellState* getState();
    void add(Cell* feature);
    ~CellFeatures();
};

#endif //CELLFEATURES_H
