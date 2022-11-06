#include "CentralFactory.h"

Infantry *CentralFactory::createInfantry(Participants *belongsTo) {
    /// @todo Decide on default values. Current parameters are temporary
    return new CentralInfantry(10, 10, belongsTo, 10);
}

Tank *CentralFactory::createTank(Participants *belongsTo) {
    /// @todo Decide on default values. Current parameters are temporary
    return new CentralTank(10, 10, belongsTo, 10);
}