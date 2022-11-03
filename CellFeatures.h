/**
    \file CellFeatures.h
    \brief Details the specifics of a Cell.
    \details Provides an abstract interface for creating the specific
    Factory: Product
    Decorator: Decorator 
    \ingroup FeatureFactory
    \authors Megan Hugo, Robert Officer
*/
#ifndef CELLFEATURES_H
#define CELLFEATURES_H

#include "Cell.h"
#include "Enumerations.h"

class CellFeatures : public Cell {
    public:
        CellFeatures();
        void add(Cell* feature);
        ~CellFeatures();
        virtual void setOccupyingForce(MilitaryUnit * m) = 0;
        void execute(){};
        CellAttribute getAttribute(){return attribute;};
    protected:
        Cell * feature;
        CellAttribute attribute;

};

#endif //CELLFEATURES_H
