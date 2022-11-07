/**
    \file Factory.h
    \class Factory
    \brief Abstract factory class of the Abstract factory Pattern
    \details provides an interface to produce abstract product objects
    AbstractFactory: AbstractFactory
    \defgroup Factory
   \author Kaitlyn Sookdhew
*/
#ifndef FACTORY_H
#define FACTORY_H
#include "Infantry.h"
#include "Tank.h"
class Factory {
public:

    /**
     * \fn Factory::createInfantry
     * \return Infantry*
     * \brief pure virtual method that will produce concrete infantry products
     */
    virtual Infantry* createInfantry(Participants * belongsTo) = 0;
    /**
    * \fn Factory::createTank
    * \return Tank*
    * \brief pure virtual method that will produce concrete Tank products
    */
    virtual Tank* createTank(Participants * belongsTo) = 0;

};

#endif
