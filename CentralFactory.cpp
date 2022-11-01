
#include "CentralFactory.h"

Infantry *CentralFactory::createInfantry() {
    /// @todo Decide one default values. Current parameters are temporary
    return new CentralInfantry(10,10,nullptr,10);
}
Tank *CentralFactory::createTank() {
    /// @todo Decide one default values. Current parameters are temporary
    return new CentralTank(10,10,nullptr,10);
}