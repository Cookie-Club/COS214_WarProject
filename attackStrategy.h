/**
    \file attackStrategy.h
    \class attackStrategy
    \brief Strategy class of the Strategy Pattern
    \details Declares an interface common to all supported algorithms
    Strategy: Strategy
    \defgroup attackStrategy
   \author Kaitlyn Sookdhew
*/
#ifndef ATTACKSTRATEGY_H
#define ATTACKSTRATEGY_H

class Squad;//forward declaration of Squad class

class attackStrategy {
public:
    /**
     * \fn execute
     * \param[in] s The squad object to execute the attack strategy
     * \brief pure virtual method the strategy that will be executed
     */
    virtual void execute(Squad *s) = 0;
};

#endif

#include "Squad.h"
