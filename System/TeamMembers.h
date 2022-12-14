/**
    \file TeamMembers.h
    \class TeamMembers
	\brief Abstract interface for basic military units
	\details Defines damage and healthpoitns variables and their getters/setters
    Composite pattern: Leaf
	\author Wian Koekemoer
    \date 30/10/22
*/

#ifndef TEAMMEMBERS_H
#define TEAMMEMBERS_H

#include <iostream>

#include "MilitaryUnit.h"

//Forward declaration for squad type
class Squad;

class TeamMembers : public MilitaryUnit {

public:
    /**
        \fn TeamMembers::TeamMembers
        \brief Constructor
        \details Sets damage and healthpoints
        \param[in] damage       The total damage the TeamMembers object should deal to other units
        \param[in] healthpoints The number of healthpoints the TeamMembers object should have
        \param[in] type         A UnitType value that describes which kind of unit the TeamMembers object is
        \param[in] belongsTo    Pointer to Participants object that owns the Squad object
    */
    TeamMembers(int damage, int healthpoints, UnitType type, Participants *belongsTo);

    /**
        \fn TeamMembers::~TeamMembers
        \brief virtual destructor
     */
    virtual ~TeamMembers() {};

    /**
        \fn TeamMembers::clone
        \brief Inherited from MilitaryUnit, not implemented
    */
    virtual MilitaryUnit *clone() = 0;

    /**
        \fn TeamMembers::setHealthpoints
        \brief Setter for healthpoints variable
        \param[in] healthpoints The number of healthpoints the TeamMembers object should have
    */
    void setHealthpoints(int healthpoints);

    /**
        \fn TeamMembers::setDamage
        \brief Setter for damage
        \param[in] damage   The total damage the TeamMembers object should deal to other units
    */
    void setDamage(int damage);

    /**
        \fn TeamMembers::getHealthpoints
        \brief Getter for healthpoints variable
        \details Inherited from MilitaryUnit
        \return Returns the current value of the unit's healthpoints
    */
    virtual int getHealthpoints();

    /**
        \fn TeamMembers::getDamage
        \brief Getter for damage
        \details Inherited from MilitaryUnit
        \return Returns the current value of the unit's damage
    */
    virtual int getDamage();

    /**
        \fn TeamMembers::isLeaf
        \brief Returns true to communicate object is leaf in Composite structure
    */
    virtual bool isLeaf();

    /**
        \fn TeamMembers::isAlive
        \brief Checks if unit is alive
        \details Inherited from MilitaryUnit
        \return True if health is greater than 0, False otherwise
    */
    virtual bool isAlive();

    /**
        \fn TeamMembers::receiveDamage
        \brief Reduces unit healthpoints
        \details Receives damage as a parameter and subtracts it from the unit's healthpoints.
        Returns false if the unit died, and true if otherwise
        \param[in] damage   Total damage which should be dealt to the TeamMembers object
    */
    bool receiveDamage(int damage);

protected:
    int damage;
    int healthpoints;
};


#endif
