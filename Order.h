
/**
	\file Order.h
	\class Order
   	\brief Order forms the Command Participant
   	\details An abstract interface that forms part of the Command pattern used for delivering requests to certain classes and objects
   	\defgroup Order
   	\author Robert Officer
	\date 30/10/22
*/

#ifndef ORDER_H
#define ORDER_H

#include <vector>

class Order {
public:
	/**
		\fn Order::execute
		\brief Pure virtual function
		\details Defined in the children of the Order class
	*/
	virtual void execute() = 0;
};

#endif
