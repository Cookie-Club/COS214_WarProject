/**
    \file Cell.h
    \class Cell
	\brief Class definition of the Cell interface
    Decorator: Component
    \defgroup Cell
    \authors Robert Officer, Kaitlyn Sookdhew, Megan Hugo
    \date 03/11/22
    \todo Documentation of Cell::removeOccupyingForce on line 37
*/

#ifndef CELL_H
#define CELL_H

#include <vector>
#include <string>

//Forward declaration of MilitaryUnit
class MilitaryUnit;

class Participants;

class Cell {

    protected:
        std::vector<MilitaryUnit*> occupyingForce;
        Participants* owner;
        int x;
        int y;

    public:
        std::string type;
        /**
            \fn Cell::Cell
            \brief Constructor
        */
        Cell(std::string type = "cell");
        /**
            \fn Cell::~Cell
            \brief Destructor
            \details deletes non-Squad MilitaryUnits
        */
        ~Cell();
        virtual void removeOccupyingForce(std::vector<MilitaryUnit*> m);
        /**
            \fn Cell::removeOccupyingForce
            \brief Removes the passed in MilitaryUnit from the occupyingForce vector
            \details Iterates through the occupyingForce and checks to see where the passed in MilitaryUnit is and when found, the unit is removed
            \param[in] m  A MilitaryUnit pointer that points to the squad being removed from the occupyingForce
        */
        virtual void removeOccupyingForce(MilitaryUnit* m);
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
        /**
            \fn Cell::getX
            \brief returns the X coordinate of the cell
        */
        int getX();
        /**
            \fn Cell::getY
            \brief returns the Y coordinate of the cell
        */
        int getY();
        virtual void add(Cell * addition){};
        virtual void execute(MilitaryUnit * m);
        virtual void execute(std::vector<MilitaryUnit*> m);
        virtual void printSymbol(std::string = "  ");
};

#endif

#include "MilitaryUnit.h"
#include "Participants.h"