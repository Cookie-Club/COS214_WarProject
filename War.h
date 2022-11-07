/**
    \file War.h
    \class War
    \brief Originator class of the Memento pattern which links all the aspects of the game
    \details Stores the world map and keeps track of all the participants on it
    \author Robert Officer, Latasha Friend
*/
#ifndef WAR_H
#define WAR_H

#include "WorldMap.h"
#include "Participants.h"
#include "SaveState.h"

class War {

private:
    WorldMap* world;
    std::vector<Participants*> participants;
    void createWorld(int worldSize);
    SaveState * lastSave;

public:
    /**
        \fn War::War
        \brief Constructor
        \param[in] world 		The object of worldMap already made
        \param[in] participants 		A vector of all the participants in the simulation
    */
    War(WorldMap* world, std::vector<Participants *> participants);
    /**
        \fn War::createSave
        \brief Creates a Memento of the current state to Save it for later use
        \return Returns a pointer to a new Memento object of the current state
    */
    SaveState* createSave();
    /**
        \fn War::getWorld
        \brief Getter for world
        \return Returns a pointer to the WorldMap object
    */
    WorldMap* getWorld();
    /**
        \fn War::getWorld
        \brief Getter for the participants vector
        \return Returns a vector of pointers to Participants
    */
    std::vector<Participants *> getParticipants();
    /**
        \fn War::setWar
        \brief Setter for the current state of War
        \param[in] ss 		The state that the War has to be set to
    */
    //void setParticipants();
    void setWar(SaveState * ss);
    /**
        \fn War::sendMap
        \brief Sends world to the object that needs it
    */
    void sendMap();
};

#endif
