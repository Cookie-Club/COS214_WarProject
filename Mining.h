/**
    \file Mining.h
    \class Mining
    \brief ConcreteStrategy of the strategy pattern
    \details Implements the algorithm defined by the Strategy interface
    Strategy:ConcreteStrategy
    \ingroup attackStrategy
    \author Kaitlyn Sookdhew
*/
#ifndef MINING_H
#define MINING_H

#include "attackStrategy.h"

class Mining : public attackStrategy {
public:
    /**
* \fn execute
* @param s The squad object to execute the attack strategy
* \brief method that will execute the Mining attack strategy for the given squad
*/
    void execute(Squad* s);
};

#endif //MINING_H
