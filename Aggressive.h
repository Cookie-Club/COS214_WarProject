/**
    \file Aggressive.h
    \class Aggressive
    \brief Concrete State class of the State Pattern
    \details The Aggressive class Implements a behaviour associated with the state of the squad context
    State: ConcreteState
    \ingroup Action
    \author Kaitlyn Sookdhew
*/
#ifndef AGGRESSIVE_H
#define AGGRESSIVE_H

#include "Action.h"
#include "Mining.h"

class Aggressive : public Action {
public:
    /**
     * \fn Aggressive::Aggressive
     * \brief default constructor that will set Actiontype to Agg
     */
    Aggressive();

    /**
     * \fn Aggressive::hande
     * \param s The squad to which the aggressive state belongs
     * \brief Concrete state handle method of state pattern that will set the strategy attribute of
     * the given squad to mining
     */
    void handle(Squad *s);
};


#endif //AGGRESSIVE_H