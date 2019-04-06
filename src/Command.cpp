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

void Command::Goto(Ogre::Vector3 pos) {
	Ogre::Vector3 distanceVector = pos - entity->position;
	entity->desiredHeading = Ogre::Math::ATan2(distanceVector.z,
			distanceVector.x).valueDegrees();
	entity->desiredSpeed = entity->maxSpeed;
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
	Goto(targetLocation);
}
bool MoveTo::done() {
	return targetLocation.distance(entity->position) <= MOVE_DISTANCE_THRESHOLD;
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
	Ogre::Vector3 relativeVel = targetEntity->velocity - entity->velocity;
	Ogre::Vector3 distanceVector = targetEntity->position - entity->position;

	if (relativeVel.length() == 0) {
		Goto(targetEntity->position);
	} else {
		float interceptTime = distanceVector.length() / relativeVel.length();
		Ogre::Vector3 targetPos = targetEntity->position
				+ targetEntity->velocity * interceptTime;
		Goto(targetPos);
	}
}
bool Intercept::done() {
	return targetEntity->position.distance(entity->position) <= MOVE_DISTANCE_THRESHOLD;
}

