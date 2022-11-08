/**
    \file Defensive.h
    \class Defensive
    \brief Concrete State class of the State Pattern
    \details The Aggressive class Implements a behaviour associated with the state of the squad context
    State: ConcreteState
    \ingroup Action
    \author Kaitlyn Sookdhew
*/
#ifndef DEFENSIVE_H
#define DEFENSIVE_H

#include "Action.h"
#include "Frontline.h"

class Defensive : public Action {
public:
    /**
 * \fn Defensive::Defensive
 * \brief default constructor that will set Actiontype to Def
 */
    Defensive();

    /**
     * \fn Defensive::hande
     * \param[in] s The squad to which the defensive state belongs
     * \brief Concrete state handle method of state pattern that will set the strategy attribute of
     * the given squad to Frontline
     */
    void handle(Squad* s);
};


#endif //DEFENSIVE_H