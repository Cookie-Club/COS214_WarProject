#ifndef AMMODEPOSIT_H
#define AMMODEPOSIT_H

#include "CellFeatures.h"

class AmmoDeposit : public CellFeatures {
public:
    AmmoDeposit();
    void setOccupyingForce(MilitaryUnit * m);
    ~AmmoDeposit();
};


#endif //AMMODEPOSIT_H
