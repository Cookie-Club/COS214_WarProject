#include "Infantry.h"

/**
    \fn Infantry::Infantry
    \brief Default constructor
    \details Sets type to Infantry
*/
Infantry::Infantry(){
    type = infantry;
}

/**
    \fn Tank::getRationConsumption
    \brief Getter for rationConsumption
*/
int Infantry::getRationConsumption()
{
    return this->rationConsumption;
}

/**
    \fn Tank::setRationConsumption
    \brief Setter for rationConsumption
*/
void Infantry::setRationConsumption(int rationConsumption)
{
    this->rationConsumption = rationConsumption;
}