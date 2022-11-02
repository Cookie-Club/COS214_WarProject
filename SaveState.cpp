#include "SaveState.h"

SaveState::SaveState(WorldMap * world, vector<Participants*> participants, int id) {
	this->World = world;
	this->participants=participants;
	this->id =id;
}

WorldMap* SaveState::getWorld() {
	return World;
}

vector<Participants*> SaveState::getParticipants() {
	return this->participants;
	return std::vector<Participants*>();
}

int SaveState::getID() {
 	return id;
 }
