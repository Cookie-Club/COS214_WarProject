
#include "AxisFactory.h"

Infantry *AxisFactory::createInfantry() {
    return new AxisInfantry();
}
Tank *AxisFactory::createTank() {
    return new AxisTank();
}