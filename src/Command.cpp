/*
 * Command.cpp
 *
 *  Created on: Apr 6, 2019
 *      Author: kylebrain
 */

#include "Command.h"

Command::Command(Entity381* ent, COMMAND_TYPE ct) :
		entity(ent), commandType(ct) {
}
Command::~Command() {
}


// MoveTo
MoveTo::MoveTo(Entity381* ent, Ogre::Vector3 location) :
		Command(ent, COMMAND_TYPE::MOVE_TO), targetLocation(location), MOVE_DISTANCE_THRESHOLD(
				20) {
}
MoveTo::~MoveTo() {
}

void MoveTo::init() {
}
void MoveTo::tick(float dt) {
}
bool MoveTo::done() {
	return true;
}


// Intercept
Intercept::Intercept(Entity381* ent, Entity381* target) :
		Command(ent, COMMAND_TYPE::INTERCEPT), targetEntity(target), MOVE_DISTANCE_THRESHOLD(
				20) {
}
Intercept::~Intercept() {
}

void Intercept::init() {
}
void Intercept::tick(float dt) {
}
bool Intercept::done() {
	return true;
}

