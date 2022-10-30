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
//Forward declaration for type of belongsTo and getArmy() usage by SquadDamage
class Participants
{
	public:
		std::vector<MilitaryUnit*> getArmy();
};
/**
   \enum UnitType
   \brief Used to identify the type of the MilitaryUnit object. 
   \details It is used in Chain of Responsibility to check if a ConcreteHandler is meant to deal with that specific object. 
*/
enum UnitType { infantry, tank, squad };

class MilitaryUnit {
	public:
		/**
            \fn MilitaryUnit:MilitaryUnit
            \brief Constructor
			\details sets belongsTo and type
        */
        MilitaryUnit(Participants* belongsTo, UnitType type)
		{
			this->belongsTo = belongsTo;
			this->type = type;
		}
		/**
            \fn MilitaryUnit:clone
            \brief Pure virtual clone method of Prototype pattern
        */
        virtual MilitaryUnit* clone() = 0;
		/**
            \fn MilitaryUnit:~MilitaryUnit
            \brief Virtual Destructor
        */
        virtual ~MilitaryUnit();
		/**
            \fn MilitaryUnit:isLeaf
            \brief Definition for children's implementation
			\details Returns true or false to communicate whether object is 
			\details leaf participant of Composite pattern
        */
        virtual bool isLeaf() = 0;
		/**
            \fn MilitaryUnit:receiveDamage
            \brief Definition for children's implementation
			\details Reduces healthpoints of TeamMembers, or delegated to members of Squad
        */
        virtual bool receiveDamage(int damage) = 0;
		/**
            \fn MilitaryUnit:getType
            \brief Getter for type
			\details Used to determine which class to cast to
        */
        UnitType getType(){return this->type;};
		/**
            \fn MilitaryUnit:getOwner
            \brief Getter for belongsTo
			\details Used to determine which Participant to object belongs to
        */
        Participants* getOwner(){return belongsTo;};
	protected:
		UnitType type;
		Participants* belongsTo;
};

#endif