/**
    \file CellFeatures.h
    \brief Holds the definition of the abstract class CellFeatures
    \author Robert Officer
    \date 03/11/22
*/
/**
	\class CellFeatures
	\brief Abstract Class used to share shared functions between the different ConcreteDecorators
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
        void add(Cell* feature);
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
        virtual void removeOccupyingForce(std::vector<MilitaryUnit*> m);
        /**
            \fn CellFeatures::removeOccupyingForce
            \brief Removes the passed in MilitaryUnit from the occupyingForce vector
            \details Iterates through the occupyingForce and checks to see where the passed in MilitaryUnit is and when found, the unit is removed
            \param[in] m  A MilitaryUnit pointer that points to the squad being removed from the occupyingForce
        */
        virtual void removeOccupyingForce(MilitaryUnit* m);
        /**
            \fn CellFeatures::setOccupyingForce
            \brief Adds MilitaryUnits to the occupyingForce attribute
            \details Uses the vector class's pre-derived function push_back() to add the MilitaryUnit passed in to the end of the occupyingForce vector
            \param[in] m  A MilitaryUnit pointer that points to the squad being added to the occupyingForce
        */
        virtual void setOccupyingForce(MilitaryUnit* m);
        virtual void setOccupyingForce(std::vector<MilitaryUnit*> m);
        std::vector<MilitaryUnit*>  getOccupyingForce();
    protected:
        Cell * feature;
        CellAttribute attribute;

};

#endif //CELLFEATURES_H
