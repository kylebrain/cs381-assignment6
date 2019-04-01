/*
 * Physics.cpp
 *
 *  Created on: Feb 24, 2019
 *      Author: kylebrain
 */

#include "Physics.h"
#include <OgreMath.h>
#include "Entity381.h"
#include <iostream>

Physics::Physics(Entity381 * _entity) :
		Aspect(_entity) {
}
Physics::~Physics() {

}

void Physics::Tick(float dt) {

	// calculate speed from desiredSpeed

	entity->desiredSpeed = Ogre::Math::Clamp(entity->desiredSpeed, entity->minSpeed, entity->maxSpeed);
	if (entity->desiredSpeed > entity->speed) {
		entity->speed += entity->acceleration * dt;

		if (entity->speed > entity->desiredSpeed) {
			entity->speed = entity->desiredSpeed;
		}

	} else {
		entity->speed -= entity->acceleration * dt;
		if (entity->speed < entity->desiredSpeed) {
			entity->speed = entity->desiredSpeed;
		}
	}

	entity->speed = Ogre::Math::Clamp(entity->speed, entity->minSpeed,
			entity->maxSpeed);


	// calculate heading from desiredHeading
	float adjustedDesiredAngle = entity->desiredHeading = NormalizeAngle(entity->desiredHeading);


	float angleDifference = NormalizeAngle(adjustedDesiredAngle - entity->heading);

	if (angleDifference <= 180) {
		entity->heading += entity->turningRate * dt;
		/*
		if (entity->heading > entity->desiredHeading) {
			entity->heading = entity->desiredHeading;
		}
		*/

	} else {
		entity->heading -= entity->turningRate * dt;

		/*
		if (entity->heading < entity->desiredHeading) {
			entity->heading = entity->desiredHeading;
		}
		*/
	}

	entity->heading = NormalizeAngle(entity->heading);


	// update velocity and position accordingly
	entity->velocity = entity->speed
			* Ogre::Vector3(Ogre::Math::Cos(Ogre::Degree(-entity->heading)), 0,
					-Ogre::Math::Sin(Ogre::Degree(-entity->heading)));
	entity->position += entity->velocity * dt;
}

float Physics::NormalizeAngle(float angle) {
	float ret = angle;
	while (ret < 0) {
		ret += 360;
	}

	while(ret >= 360) {
		ret -= 360;
	}

	return ret;
}

