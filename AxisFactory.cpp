
#include "AxisFactory.h"

Infantry *AxisFactory::createInfantry() {
    /// @todo Decide one default values. Current parameters are temporary
    return new AxisInfantry(10,10,nullptr,10);
}
Tank *AxisFactory::createTank() {
    /// @todo Decide one default values. Current parameters are temporary
    return new AxisTank(10,10,nullptr,10);
}