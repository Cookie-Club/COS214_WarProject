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
        /**
            \fn Infantry::Infantry
            \brief Constructor
        */
        Infantry(int damage, int healthpoints, Participants* belongsTo, int rationConsumption);
        virtual MilitaryUnit* clone() = 0;
        /**
            \fn Infantry::Infantry
            \brief Default constructor
            \details Sets type to Infantry
        */
        Infantry();
        /**
            \fn Tank::getRationConsumption
            \brief Getter for rationConsumption
        */
        int getRationConsumption();
        /**
            \fn Tank::setRationConsumption
            \brief Setter for rationConsumption
        */
        void setRationConsumption(int);
    protected:
        int rationConsumption;
};


#endif
