/**
    \file Cell.h
    \brief Contains the definition of the Cell class
    \authors Robert Officer, Kaitlyn Sookdhew
    \date 03/11/22
*/
/**
	\class Flatlands
	\brief Class definition of a flatlands cell type
    Decorator: ConcreteComponent
	\authors Robert Officer, Kaitlyn Sookdhew
*/
#ifndef CELL_H
#define CELL_H

#include <vector>

class MilitaryUnit;
class Cell {

    protected:
        int x;
        int y;
        std::vector<MilitaryUnit*> occupyingForce;

    public:
        /**
            \fn Cell::Cell
            \brief Constructor
        */
        Cell();
        /**
            \fn Cell::removeOccupyingForce
            \brief Removes the passed in MilitaryUnit from the occupyingForce vector
            \details Iterates through the occupyingForce and checks to see where the passed in MilitaryUnit is and when found, the unit is removed
            \param[in] m  A MilitaryUnit pointer that points to the squad being removed from the occupyingForce
        */
        void removeOccupyingForce(std::vector<MilitaryUnit*> m);
        void removeOccupyingForce(MilitaryUnit* m);
        /**
            \fn Cell::setOccupyingForce
            \brief Adds MilitaryUnits to the occupyingForce attribute
            \details Uses the vector class's pre-derived function push_back() to add the MilitaryUnit passed in to the end of the occupyingForce vector
            \param[in] m  A MilitaryUnit pointer that points to the squad being added to the occupyingForce
        */
        virtual void setOccupyingForce(MilitaryUnit* m);
        virtual void setOccupyingForce(std::vector<MilitaryUnit*> m);
        /**
            \fn Cell::getOccupyingForce
            \brief Gets the occupyingForce of a cell
            \return A vector of MilitaryUnit pointers
        */
        std::vector<MilitaryUnit*> getOccupyingForce();
        /**
            \fn Cell::setCoordinates
            \brief Sets the x and y coordinate attributes of the cell
            \param[in] _x The x coordinate of the cell
            \param[in] _y The y coordinate of the cell
        */
        void setCoordinates(int _x, int _y);
        int getX();
        int getY();
        virtual void add(Cell * addition){};
        virtual void execute(MilitaryUnit * m){};
};

#endif

#include "MilitaryUnit.h"