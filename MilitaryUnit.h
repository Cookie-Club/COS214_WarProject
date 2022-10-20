#ifndef MILITARYUNIT_H
#define MILITARYUNIT_H
#include "Order.h"
class MilitaryUnit {
	public:
		virtual MilitaryUnit* clone() = 0;
		virtual ~MilitaryUnit();
		virtual bool isLeaf() = 0;
	protected:
		Order* orders;
};

#endif