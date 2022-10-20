#ifndef MILITARYUNIT_H
#define MILITARYUNIT_H

#include <string>

#include "Order.h"

using namespace std;

class MilitaryUnit {
	public:
		virtual MilitaryUnit* clone() = 0;
		virtual ~MilitaryUnit();
		virtual bool isLeaf() = 0;
		virtual void receiveDamage(int damagae) = 0;
		virtual string getType() = 0;
	protected:
		string type;
};

#endif