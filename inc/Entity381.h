/*
 * Entity381.h
 *
 *  Created on: Feb 24, 2019
 *      Author: kylebrain
 */
//now includes all ship classes that cannot fly

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

//-----------------------------------------------------------------------------------------------------------

class Alien : public Entity381 {
public:
	Alien();
	Alien(Engine * engine, Ogre::Vector3 pos, float heading, int id);
	virtual ~Alien();

	virtual void InitAspects();
};

//-----------------------------------------------------------------------------------------------------------

class Carrier : public Entity381 {
public:
	Carrier();
	Carrier(Engine * engine, Ogre::Vector3 pos, float heading, int id);
	virtual ~Carrier();

	virtual void InitAspects();
};

//-----------------------------------------------------------------------------------------------------------

class Destroyer : public Entity381 {
public:
	Destroyer();
	Destroyer(Engine * engine, Ogre::Vector3 pos, float heading, int id);
	virtual ~Destroyer();

	virtual void InitAspects();
};

//-----------------------------------------------------------------------------------------------------------

class Frigate : public Entity381 {
public:
	Frigate();
	Frigate(Engine * engine, Ogre::Vector3 pos, float heading, int id);
	virtual ~Frigate();

	virtual void InitAspects();
};

//-----------------------------------------------------------------------------------------------------------

class Speedboat : public Entity381 {
public:
	Speedboat();
	Speedboat(Engine * engine, Ogre::Vector3 pos, float heading, int id);
	virtual ~Speedboat();

	virtual void InitAspects();
};

#endif /* INC_ENTITY381_H_ */
