/**
	\file SaveState.h
	\class SaveState
	\brief **  Documentation Pending **
	\todo Documentation
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
    SaveState(WorldMap *world, vector<Participants *> participants);

<<<<<<< Updated upstream
    WorldMap *getWorld();

    vector<Participants *> getParticipants();

=======
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
>>>>>>> Stashed changes
    int getID();
    // void setState(SaveState *);
};

#endif
