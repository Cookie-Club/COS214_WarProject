#include "AlliedFactory.h"

Infantry *AlliedFactory::createInfantry() {
    /// @todo Decide one default values. Current parameters are temporary
    return new AlliedInfantry(10, 100, nullptr, 10);
}

Tank *AlliedFactory::createTank() {
    /// @todo Decide one default values. Current parameters are temporary
    return new AlliedTank(10, 100, nullptr, 10);
}
