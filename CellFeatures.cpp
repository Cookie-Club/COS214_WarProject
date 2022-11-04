#include "CellFeatures.h"

CellFeatures::CellFeatures(){}

void CellFeatures::add(Cell* feature){
    if(this->feature == nullptr){
        this->feature = feature;
        // std::cout << ((Cell*)feature)->type << " added to: ";
        // switch (attribute)
        // {
        //     case AmmoDepo: 
        //     {
        //         std::cout << " AmmoDepo";
        //         break;
        //     }
        //     case FuelDepo: 
        //     {
        //         std::cout << " FuelDepo";
        //         break;
        //     }
        //     default:
        //     {break;}
        // };
    }
    else{
        this->feature->add(feature);
    }
}

CellAttribute CellFeatures::getAttribute()
{
    return attribute;
}
