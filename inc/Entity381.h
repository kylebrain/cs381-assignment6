/*
 * Entity381.h
 *
 *  Created on: Feb 24, 2019
 *      Author: kylebrain
 */

#ifndef INC_ENTITY381_H_
#define INC_ENTITY381_H_

#include <string>
#include <vector>
#include <OgreVector3.h>
#include <OgreSceneNode.h>
#include <OgreEntity.h>

#include "EntityMgr.h"
#include "Aspect.h"
#include "Engine.h"

using namespace std;

class EntityMgr;

class Entity381 {

public:

	Entity381();
	Entity381(Engine * engine, string meshName,
			Ogre::Vector3 pos, float _heading, float _minSpeed, float _maxSpeed,
			float _acceleration, float _turningRate, int id);
	virtual ~Entity381();

	// identification
	int entityId;
	string entityName;

	// oriented physics
	float minSpeed;
	float maxSpeed;
	float speed;
	float heading;
	float desiredSpeed;
	float desiredHeading;

	float acceleration;
	float turningRate;

	// ai
	Entity381 * followEnt;

	// mesh
	string meshFile;

	// general physics
	Ogre::Vector3 position;
	Ogre::Vector3 velocity;

	// Ogre referrences
	Ogre::SceneNode * ogreSceneNode;
	Ogre::Entity * ogreEntity;

	vector<Aspect *> aspects;

	void Tick(float dt);
	virtual void InitAspects();

};

#endif /* INC_ENTITY381_H_ */
