#include "CellFeatures.h"

CellFeatures::CellFeatures(){}

void CellFeatures::add(Cell* feature){
    if(this->feature == 0){
        this->feature = feature;
    }
    else{
        this->feature->add(feature);
    }
}

