/**
	\file SaveState.h
	\class SaveState
	\brief Memento class of the Memento Pattern
    \details Save state is in charge of making a copy of the current state of the War
    \author Latasha Friend
*/
#ifndef SAVESTATE_H
#define SAVESTATE_H

#include "WorldMap.h"
#include "Participants.h"

class SaveState {
private:
    WorldMap *World;
    vector<Participants *> participants;
    static int counter;
    const int id;
public:
    /**
        \fn SaveState::SaveState
        \brief Constructor
        \param[in] world 		The current WorldMap state
        \param[in] participants 		A vector of participants currently on the map

    */
    SaveState(WorldMap *world, vector<Participants *> participants);
    /**
        \fn SaveState::getWorld
        \brief Getter for method for World
        \return Returns pointer to WorldMap object
    */
    WorldMap *getWorld();
    /**
        \fn SaveState::getParticipants
        \brief Getter for method for participants
        \return Returns a vector of participants
    */
    vector<Participants *> getParticipants();
    /**
        \fn SaveState::getID
        \brief Getter for method for id (the Memento's id)
        \return Returns an integer
    */
    int getID();
    // void setState(SaveState *);
};

#endif
