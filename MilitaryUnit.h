#ifndef MILITARYUNIT_H
#define MILITARYUNIT_H

#include <string>

#include "Order.h"
#include <vector>
enum UnitType { infantry, tank, squad };

class MilitaryUnit {
	public:
		virtual MilitaryUnit* clone() = 0;
		virtual ~MilitaryUnit();
		virtual bool isLeaf() = 0;
		virtual bool receiveDamage(int damage) = 0;
		virtual UnitType getType(){return this->type;};
		virtual std::vector<MilitaryUnit*> getMembers() = 0;
	protected:
		UnitType type;
};

#endif