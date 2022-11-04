#ifndef ENUMERATIONS_H
#define ENUMERATIONS_H

enum ActionType {Agg, Def};
/**
   \enum UnitType
   \brief Used to identify the type of the MilitaryUnit object. 
   \details It is used in Chain of Responsibility to check if a ConcreteHandler is meant to deal with that specific object. 
*/
enum UnitType { infantry, tank, squad };
enum Participant{Allied,Central};
enum CellAttribute{AmmoDepo, FuelDepo};

#endif