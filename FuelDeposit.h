#ifndef FUELDEPOSIT_H
#define FUELDEPOSIT_H

#include "CellFeatures.h"

class FuelDeposit : public CellFeatures {

public:
    FuelDeposit();
    void setOccupyingForce(MilitaryUnit * m);
    ~FuelDeposit();
};

#endif //FUELDEPOSIT_H
