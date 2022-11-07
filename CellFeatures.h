/**
    \file CellFeatures.h
<<<<<<< Updated upstream
   \brief Abstract Class used to share shared functions between the different ConcreteDecorators
=======
    \brief Abstract Class used to share shared functions between the different ConcreteDecorators
>>>>>>> Stashed changes
    Decorator: Decorator
    Factory: AbstractProduct
    \defgroup CellFeatures
	\authors Megan Hugo, Robert Officer
    \date 03/11/22
*/

#ifndef CELLFEATURES_H
#define CELLFEATURES_H

#include "Cell.h"
#include "Enumerations.h"

class CellFeatures : public Cell {
public:
    /**
        \fn CellFeatures::CellFeatures
        \brief Constructor
    */
    CellFeatures();

    /**
        \fn CellFeatures::add
        \brief Allows features to be added on to the concreteDecorators
        \details Checks to see if the features attribute is set first. If not, it is set to the passed in pointer. Else if set, the responsibility of setting
        the passed in feature is given to the feature attribute
        \param[in] feature A Cell pointer that points to the cell feature needing to be added to the features attribute
    */
    void add(Cell *feature);

    /**
        \fn CellFeatures::~CellFeatures
        \brief Destructor
    */
    ~CellFeatures();
    //void execute(){};
    /**
        \fn CellFeatures::getAttribute
        \brief Returns the attribute of the ConcreteDecorator
        \returns Returns an enumeration that defines what the ConcreteDecorator is
    */
    CellAttribute getAttribute();

protected:
    Cell *feature;
    CellAttribute attribute;

};

#endif //CELLFEATURES_H
