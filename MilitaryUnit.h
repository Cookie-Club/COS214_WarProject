/**
    \file MilitaryUnit.h
    \brief Defines MilitaryUnit class and UnitType enum
    \authors Wian Koekemoer, Robert Officer
    \date 30/10/22
    \todo Documentation for MilitaryUnit::getMap and MilitaryUnit::setMap on lines 87-88
*/
/**
	\class MilitaryUnit
	\brief Abstract interface for all military unit objects
	\details An abstract interface
	Composite pattern: Component
	\defgroup MilitaryUnit
	\authors Robert Officer, Wian Koekemoer
*/
#ifndef MILITARYUNIT_H
#define MILITARYUNIT_H


#include <string>
#include <vector>
#include <cstdlib>
#include "Enumerations.h"
// class Action;//Required for the return type of the forward  declared Participant::getState()
// class MilitaryUnit;//Required for the return type of the forward  declared Participant::getArmy()
//Forward declaration for type of belongsTo and getArmy() usage by SquadDamage
class Participants;
class WorldMap; //forward declaration of WorldMap class
class Squad;
class MilitaryUnit {

	public:
		/**
            \fn MilitaryUnit:MilitaryUnit
            \brief Constructor
			\details Sets belongsTo and type
            \param[in] belongsTo    A pointer to the Participants object that owns the MilitaryUnit object
            \param[in] type         A UnitType value that describes which kind of unit the MilitaryUnit object is
        */
        MilitaryUnit(Participants* belongsTo, UnitType type);
		/**
            \fn MilitaryUnit::clone
            \brief Pure virtual clone method of Prototype pattern
        */
        virtual MilitaryUnit* clone() = 0;
		/**
            \fn MilitaryUnit::~MilitaryUnit
            \brief Virtual Destructor
        */
        virtual ~MilitaryUnit(){};
		/**
            \fn MilitaryUnit::isLeaf
            \brief Definition for children's implementation
			\details Returns true or false to communicate whether object is 
			\details leaf participant of Composite pattern
        */
        virtual bool isLeaf() = 0;
		/**
            \fn MilitaryUnit::receiveDamage
            \brief Definition of abstract operation; to be implemented in children
            \param[in] damage   Integer number that represents the total damage the unit can dealz
        */
        virtual bool receiveDamage(int damage) = 0;
		/**
            \fn MilitaryUnit::getType
            \brief Getter for type variable
			\details Called by other objects to determine which class to cast the object to
        */
        UnitType getType();
		/**
            \fn MilitaryUnit::getOwner
            \brief Getter for belongsTo variable
			\details called to determine which Participant the object belongs to
        */
        Participants* getOwner();
        /**
           \fn MilitaryUnit::getParticipant
           \brief Getter for what kind of participant the MilitaryUnit belongs to
           \return Participant enum value
        */
        Participant getParticipant();
        /**
            \fn MilitaryUnit::getSquad
            \brief Getter for squad
        */
        Squad* getSquad();
        /**
            \fn MilitaryUnit::getSquad
            \brief Getter for squad
            \param[in] squad    The Squad object to which the TeamMembers object belongs
        */
        void setSquad(Squad* squad);
        /**
            \fn MilitaryUnit::removeSquad
            \brief Sets squad member variable to null
        */
        void removeSquad();
        
	protected:
        Squad* squad;
        UnitType type;
		Participants* belongsTo;
        WorldMap* map;
        
    public:
        WorldMap *getMap();
        void setMap(WorldMap *map);
};

#endif

#include "Participants.h"
#include "WorldMap.h"
#include "Squad.h"