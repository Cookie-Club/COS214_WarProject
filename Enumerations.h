/**
    \file Enumerations.h
    \brief file to define enumertions
    \authors Robert Officer, Wian Koekemoer
*/
#ifndef ENUMERATIONS_H
#define ENUMERATIONS_H

/**
   \enum ActionType
   \brief Used to identify the state of the object.
   \details It is used in State pattern to store whether a squad is in an aggressive or defensive state.
*/
enum ActionType {
    Agg, Def
};
/**
   \enum UnitType
   \brief Used to identify the type of the MilitaryUnit object. 
   \details It is used in Chain of Responsibility to check if a ConcreteHandler is meant to deal with that specific object. 
*/
enum UnitType {
    infantry, tank, squad
};

/**
   \enum Participant
   \brief Used to identify the type of Participant.
   \details It is used in template method to check the type of participant
*/
enum ParticipantType {
    Allied = 32, Central = 41
};

/**
   \enum CellAttribute
   \brief Used to identify the type of feature for a cell
   \details
*/
enum CellAttribute {
    AmmoDepo, FuelDepo
};

#endif