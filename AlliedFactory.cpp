#include "AlliedFactory.h"

Infantry *AlliedFactory::createInfantry(Participants* belongsTo) {
    /// @todo Decide on default values. Current parameters are temporary
    return new AlliedInfantry(10, 100, belongsTo, 10);
}

Tank *AlliedFactory::createTank(Participants* belongsTo) {
    /// @todo Decide on default values. Current parameters are temporary
    return new AlliedTank(10, 100, belongsTo, 10);
}
