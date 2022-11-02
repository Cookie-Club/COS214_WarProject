/**
    \file Action.h
    \class Action
    \brief State class of the State Pattern
    \details The Action class defines an interface for encapsulating the behaviour associated with a particular state,
    either Aggressive or defensive, of the Squad (context of the state pattern)
    State: state
    \defgroup Action
    \author Kaitlyn Sookdhew
*/
#ifndef ACTION_H
#define ACTION_H
#include "Squad.h"
#include "Enumerations.h"
#include <iostream>
using namespace std;


class Action {
protected:
    ActionType type;
public:
    /**
          \fn Action::Action
          \brief Constructor
          \param[in] ActionType Variable to initialise type attribute
      */
    Action(ActionType);

    /**
     *
     * @param s
     * @return
     */
    virtual int handle(Squad* s) = 0;

    /**
     *
     * @return
     */
    ActionType getType();
};

#endif