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
        void add(Cell* feature);
        ~CellFeatures();
    protected:
        Cell * feature;
};

#endif //CELLFEATURES_H
