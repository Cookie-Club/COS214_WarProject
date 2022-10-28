/**
	\class Infantry
	\brief Abstract interface for infantry objects
    \details Prototype pattern: AbstractProduct
	\author Wian K
*/

#ifndef INFANTRY_H
#define PROJECT_INFANTRY_H

#include "TeamMembers.h"
#include "MilitaryUnit.h"

class Infantry : public TeamMembers {
    public:
        virtual MilitaryUnit* clone() = 0;
        Infantry();
        int getRationConsumption();
        void setRationConsumption(int);
    protected:
        int rationConsumption;
};


#endif
