#include "CellFeatures.h"

CellFeatures::CellFeatures() {}

void CellFeatures::add(Cell *feature) {
    //checks to see if there is currently a feature added to the classes attribute and then goes down the chain of features until an empty slot is open
    if (this->feature == nullptr) {
        this->feature = feature;
    } else {
        this->feature->add(feature);
    }
}

CellAttribute CellFeatures::getAttribute() {
    return attribute;
}
void CellFeatures::removeOccupyingForce(std::vector<MilitaryUnit*> m)
{
    feature->removeOccupyingForce(m);
}
void CellFeatures::removeOccupyingForce(MilitaryUnit* m)
{
    feature->removeOccupyingForce(m);
}
void CellFeatures::setOccupyingForce(MilitaryUnit* m)
{
    feature->setOccupyingForce(m);
}
void CellFeatures::setOccupyingForce(std::vector<MilitaryUnit*> m)
{
    feature->setOccupyingForce(m);
}

std::vector<MilitaryUnit*> * CellFeatures::getOccupyingForce(){
    return feature->getOccupyingForce();
}