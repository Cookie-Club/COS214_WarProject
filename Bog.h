/**
    \file Bog.h
<<<<<<< Updated upstream
    \class Bog
=======
>>>>>>> Stashed changes
	\brief Class definition of a Bog cell type
    Decorator: ConcreteComponent
    \ingroup Cell
    \author Robert Officer
    \date 03/11/22
*/

#ifndef BOG_H
#define BOG_H

#include "Cell.h"

class Bog : public Cell {
public:
    /**
        \fn Bog::Bog
        \brief Constructor
    */
    Bog();

    /**
        \fn Bog::execute
<<<<<<< Updated upstream
        \brief Tells the Bog cell to perform specific actiosn
        \details For the Bog class, the specific actions include reducing the incoming squads rations and fuel reserves based
        on how many team members are in the squad and adding a resourceUsemultiplier to the calculated answer
=======
        \brief Tells the Bog cell to perform specific action
        \details For the Bog class, the specific actions include reducing the incoming squads rations and fuel reserves based
        on how many team members are in the squad and adding a resourceUse-multiplier to the calculated answer
>>>>>>> Stashed changes
        \param[in] m  A MilitaryUnit pointer that points to the squad being added into the cells occupying force
    */
    void execute(MilitaryUnit *m);

    /**
<<<<<<< Updated upstream
        \fn Bog::printSymbol
        \param[in] s     String input to print
        \brief
    */
    virtual void printSymbol(std::string s = "  ");

=======
    \fn Bog::printSymbol
    \param[in] s     String input to print
    \brief
 */
    virtual void printSymbol(std::string s = "  ");

    /**
    \fn Bog::execute
    \brief Tells the Bog cell to perform specific action
    \details For the Bog class, the specific actions include reducing the incoming squads rations and fuel reserves based
    on how many team members are in the squad and adding a resourceUse-multiplier to the calculated answer
    \param[in] m  A vector of MilitaryUnit pointers that points to the squad being added into the cells occupying force
*/
    void execute(std::vector<MilitaryUnit *> m);

>>>>>>> Stashed changes
private:
    double resourceUseMultiplier;

};


#endif //BOG_H
