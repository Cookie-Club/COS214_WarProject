/**
	\file Order.h
   	\brief Order forms the Command Participant
   	\details An abstract interface that forms part of the Command pattern used for delivering requests to certain classes and objects 
   	\author Robert Officer
	\class Order
*/

#ifndef ORDER_H
#define ORDER_H

class Order {
public:
	virtual void execute() = 0;
};

#endif
