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
#include "Enumerations.h"
#include <iostream>
using namespace std;

//Forward declaration of Squad class
class Squad;

class Action {
protected:
    //Action type either aggressive(Agg) or defensive (Def)
    ActionType type;
public:
    /**
     * \fn Action::Action
     * \brief Default constructor
     */
    Action();

    /**
     * \fn Action::handle
     * \param s The squad to which state belongs
     * \brief Pure virtual method in the State pattern that will set strategy of given squad
      */
    virtual void handle(Squad* s) = 0;

    /**
     * \fn Action::getType
     * @return ActionType
     * \brief Getter method for type variable
     */
    ActionType getType();
};

#endif

#include "Squad.h"