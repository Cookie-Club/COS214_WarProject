/**
    \file Frontline.h
    \class Frontline
    \brief ConcreteStrategy of the strategy pattern
    \details Implements the algorithm defined by the Strategy interface
    Strategy:ConcreteStrategy
    \ingroup attackStrategy
    \author Kaitlyn Sookdhew
*/
#ifndef FRONTLINE_H
#define FRONTLINE_H

#include "attackStrategy.h"

class Frontline : public attackStrategy {

public:
    /**
        \fn execute
        \param[in] s The squad object to execute the attack strategy
        \brief method that will execute the frontline attack strategy for the given squad
     */
    void execute(Squad *s);
};

#endif //FRONTLINE_H
