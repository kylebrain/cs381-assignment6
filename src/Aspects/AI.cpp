/*
 * AI.cpp
 *
 *  Created on: Mar 25, 2019
 *      Author: kylebrain
 */

#include "AI.h"
#include "Entity381.h"
#include "OgreMath.h"

AI::AI(Entity381 * _entity) :
		Aspect(_entity) {
}
AI::~AI() {

}

void AI::Tick(float dt) {
	if (entity->followEnt != NULL) {
		Follow(entity->followEnt);
	}
}

void AI::MoveTo(Ogre::Vector3 position) {
	Ogre::Vector3 distanceVector =  position - entity->position;
	entity->desiredHeading = Ogre::Math::ATan2(distanceVector.z, distanceVector.x).valueDegrees();
	entity->desiredSpeed = entity->maxSpeed;
}

void AI::Follow(Entity381 * followEnt) {
	MoveTo(followEnt->position);
}

