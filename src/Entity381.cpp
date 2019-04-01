/*
 * Entity381.cpp
 *
 *  Created on: Feb 24, 2019
 *      Author: kylebrain
 */

#include "Entity381.h"
#include "GfxMgr.h"

Entity381::Entity381() :
	entityId(-1),
	entityName(""),
	minSpeed(0),
	maxSpeed(0),
	speed(0),
	heading(0),
	desiredSpeed(0),
	desiredHeading(0),
	acceleration(0),
	turningRate(0),
	meshFile(""),
	position(Ogre::Vector3::ZERO),
	velocity(Ogre::Vector3::ZERO),
	ogreSceneNode(NULL),
	ogreEntity(NULL),
	followEnt(0)
{}

Entity381::Entity381(Engine * engine, string meshName,
		Ogre::Vector3 pos, float _heading, float _minSpeed, float _maxSpeed,
		float _acceleration, float _turningRate, int id) :
		entityId(id),
		entityName(""),
		minSpeed(_minSpeed),
		maxSpeed(_maxSpeed),
		speed(0),
		heading(_heading),
		desiredSpeed(0),
		desiredHeading(_heading),
		acceleration(_acceleration),
		turningRate(_turningRate),
		position(pos),
		velocity(Ogre::Vector3::ZERO),
		followEnt(0)
{
	ogreEntity = engine->gfxMgr->mSceneMgr->createEntity(meshName);
	meshFile = meshName;
	ogreSceneNode = engine->gfxMgr->mSceneMgr->getRootSceneNode()->createChildSceneNode();
	ogreSceneNode->attachObject(ogreEntity);

}

Entity381::~Entity381() {
	for(int i = 0; i < aspects.size(); i++) {
		if(aspects[i] != NULL) {
			delete aspects[i];
		}
	}
}

void Entity381::Tick(float dt) {
	for(int i = 0; i < aspects.size(); i++) {
		aspects[i]->Tick(dt);
	}
}

void Entity381::InitAspects() {}

