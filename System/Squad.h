/**
    \file Squad.h
    \class Squad
	\brief Composite satructure of military units
	\details Stores TeamMember objects, stores occupying cell, implements movement
    Composite pattern: Composite participant
    \ingroup MilitaryUnit
	\authors Wian Koekemoer, Robert Officer, Kaitlyn Sookdhew
*/

#ifndef SQUAD_H
#define SQUAD_H

#include <vector>
#include "MilitaryUnit.h"
#include "Bombardment.h"
#include "attackStrategy.h"
#include "Aggressive.h"
#include "Defensive.h"


//Forward declaration for callInBombardment usage of the constructor and execute methods
class Bombardment;

class Cell;

class Squad : public MilitaryUnit {
protected:
    Cell *occupyingCell;
    std::vector<MilitaryUnit *> members;
    int Ammo;
    int rations;
    int fuel;
    Action *state;
    attackStrategy *strategy;
    string name;
public:
    /**
        \fn Squad::Squad
        \brief Constructor
        \param[in] belongsTo    Pointer to Participants object that owns the Squad object
    */
    Squad(Participants *belongsTo);

    /**
        \fn Squad::~Squad
        \brief Destructor
        \details Deletes members
    */
    virtual ~Squad();

    /**
        \fn Squad::moveSquad
        \brief Select cell to move to
        \todo Decide if this is necessary
    */
    void moveSquad();

    /**
        \fn Squad::setOccupyingCell
        \brief Stores the cell on which the squad is located
        \details Receives a cell reference
        Requests old cell to remove the squad from its occupying forces variable
        Saves cell reference that was passed as parameter
        Requests that new cell add the squad to its occupying forces variable
        \param[in] c    Pointer to Cell object on which the Squad object is located
    */
    void setOccupyingCell(Cell *c);

    /**
        \fn Squad::getOccupyingCell
        \brief Getter for occupyingCell
        \return a Cell pointer to the cell that the squad is occupying
    */
    Cell* getOccupyingCell(){return occupyingCell;};

    /**
        \fn Squad::clone
        \brief Clone operation of Prototype pattern
        \details Creates and returns a copy of the Squad's TeamMembers
    */
    Squad *clone();

    /**
        \fn Squad::isLeaf
        \brief Returns false to communicate object is not a leaf in Composite structure
    */
    bool isLeaf();

    /**
         \fn Squad::isAlive
         \brief Checks if any Squad members are alive
         \details Inherited from MilitaryUnit
         \return True if number of units is greater than 0, False otherwise
     */
    bool isAlive();

    /**
        \fn Squad::addMember
        \brief Expands members variable
        \details Adds parameter to members vector
        \param[in] m Pointer to MilitaryUnit object which should be added to members vector
    */
    void addMember(MilitaryUnit *m);

    /**
        \fn Squad::removeSquadMember
        \brief Removes a military unit from the list of members
        \param[in] member   Pointer to member which should be removed from members vector
    */
    void removeSquadMember(MilitaryUnit *member);

    /**
        \fn Squad::getMembers
        \brief Getter for members vector
    */
    virtual std::vector<MilitaryUnit *> getMembers();

    /**
        \fn Squad::receiveDamage
        \brief Receives damage
        \details Receives damage input and divides it equally among members
        \param[in] damage   Total damage which should be dealt to the Squad object
        \return Boolean value: True if squad is still alive, false otherwise
    */
    virtual bool receiveDamage(int damage);

    /**
        \fn Squad::callInBombardment
        \brief Executes the Command and Chain of Responsibility
        \details Creates a new bombardment order and executes the new order on the passed in cell.
    */
    void callInBombardment(Cell *targetedCell);

    /**
        \fn Squad::getDamage
        \brief Gets total damage of the Squad's members
        \details Inherited from MilitaryUnit. 
        \details Iterates through members vector and adds up damage of units inside
        \return An int value equal to the sum total damage of the squad's members
    */
    virtual int getDamage();

    /**
        \fn Squad::getHealth
        \brief Gets total health of the Squad's members
        \details Inherited from MilitaryUnit. 
        \details Iterates through members vector and adds up health of units inside
        \return An int value equal to the sum total health of the suad's members
    */
    virtual int getHealthpoints();

    /**
    * \fn Squad::getState
    * \return  Action pointer
    * \brief getter for state variable
    */
    Action *getState();

    /**
     * \fn Squad::setState
     * \param[in] state     Action Pointer
     * \brief setter method for state variable
     */
    void setState(Action *state);

    /**
    * \fn Squad::getStrategy
    * \return  Strategy pointer
    * \brief getter for strategy variable
    */
    attackStrategy *getStrategy();

    /**
    * \fn Squad::setStrategy
    * \param[in] strategy     attackStrategy Pointer
    * \brief setter method for strategy variable
    */
    void setStrategy(attackStrategy *strategy);

    /**
     * \fn Squad::attack
     * \param[in] x     int value representing x co-ordinate of cell
     * \param[in] y     int value representing y co-ordinate of cell
     * \brief Method to execute the strategy pattern
     */
    void attack(int x, int y);

    /**
    * \fn Squad::getAmmo
    * \return  int value
    * \brief getter for ammo variable
    */
    int getAmmo();

    /**
    * \fn Squad::setAmmo
    * \param[in] ammo     int value
    * \brief setter method for ammo variable
    */
    void setAmmo(int ammo);

    /**
    * \fn Squad::getFuel
    * \return  int value
    * \brief getter for fuel variable
    */
    int getFuel();

    /**
    * \fn Squad::setFuel
    * \param fuel     int value
    * \brief setter method for fuel variable
    */
    void setFuel(int fuel);

    /**
    * \fn Squad::getRations
    * \return  int value
    * \brief getter for rations variable
    */
    int getRations();

    /**
    * \fn Squad::setRations
    * \param[in] rations     int value
    * \brief setter method for rations variable
    */
    void setRations(int rations);

    /**
     * \fn Squad::battle
     * \param[in] enemyMembers      MilitaryUnit vector of enemy army
     * \return boolean value whether squad has won the battle
     * \brief
     */
    bool battle(std::vector<MilitaryUnit *> enemyMembers);

    /**
     * \fn Squad::getSquadHealth
     * \return int value
     * \brief method to calculate and return the total squad health points
     */
    int getSquadHealth();

    /**
        \fn Squad::getSquadDamage
        \brief gets how much damage squad members do in total
        \return Returns sum damage of all squad members
    */
    int getSquadDamage();

    /**
     * \fn Squad::setMap
     * \param[in] map   WorldMap*
     * \brief Virtual method to set Map
     */
    virtual void setMap(WorldMap *map);

    /**
    * \fn Squad::getName
    * \return  string value
    * \brief getter for name variable
    */
    string getName();
};


#endif //SQUAD_H

#include "TeamMembers.h"
#include "Order.h"
