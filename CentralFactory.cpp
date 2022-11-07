#include "CentralFactory.h"

Infantry *CentralFactory::createInfantry(Participants *belongsTo) {
    /// @todo Decide on default values. Current parameters are temporary
<<<<<<< Updated upstream
    return new CentralInfantry(10, 10, belongsTo, 10);
=======
    return new CentralInfantry(10, 100, belongsTo, 10);
>>>>>>> Stashed changes
}

Tank *CentralFactory::createTank(Participants *belongsTo) {
    /// @todo Decide on default values. Current parameters are temporary
<<<<<<< Updated upstream
    return new CentralTank(10, 10, belongsTo, 10);
=======
    return new CentralTank(10, 100, belongsTo, 10);
>>>>>>> Stashed changes
}