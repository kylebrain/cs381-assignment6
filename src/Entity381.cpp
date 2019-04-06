/*
 * Entity381.cpp
 *
 *  Created on: Feb 24, 2019
 *      Author: kylebrain
 */
//now includes functions for all ships that cannot fly
#include <UnitAI.h>
#include "Physics.h"
#include "Renderable.h"
#include "Entity381.h"
#include "GfxMgr.h"

Entity381::Entity381() :
		entityId(-1), entityName(""), minSpeed(0), maxSpeed(0), speed(0), heading(
				0), desiredSpeed(0), desiredHeading(0), acceleration(0), turningRate(
				0), meshFile(""), position(Ogre::Vector3::ZERO), velocity(
				Ogre::Vector3::ZERO), ogreSceneNode(NULL), ogreEntity(NULL), ai(
				NULL) {
}

Entity381::Entity381(Engine * engine, string meshName, Ogre::Vector3 pos,
		float _heading, float _minSpeed, float _maxSpeed, float _acceleration,
		float _turningRate, int id) :
		entityId(id), entityName(""), minSpeed(_minSpeed), maxSpeed(_maxSpeed), speed(
				0), heading(_heading), desiredSpeed(0), desiredHeading(
				_heading), acceleration(_acceleration), turningRate(
				_turningRate), position(pos), velocity(Ogre::Vector3::ZERO), ai(
				NULL) {
	ogreEntity = engine->gfxMgr->mSceneMgr->createEntity(meshName);
	meshFile = meshName;
	ogreSceneNode =
			engine->gfxMgr->mSceneMgr->getRootSceneNode()->createChildSceneNode();
	ogreSceneNode->attachObject(ogreEntity);

}

Entity381::~Entity381() {
	for (int i = 0; i < aspects.size(); i++) {
		if (aspects[i] != NULL) {
			delete aspects[i];
		}
	}
}

void Entity381::Tick(float dt) {
	for (int i = 0; i < aspects.size(); i++) {
		aspects[i]->Tick(dt);
	}
}

void Entity381::InitAspects() {
}

//-----------------------------------------------------------------------------------------------------------

Alien::Alien() :
		Entity381() {
	InitAspects();
}
Alien::Alien(Engine * engine, Ogre::Vector3 pos, float heading, int id) :
		Entity381(engine, "alienship.mesh", pos, heading, 0, 200, 100, 50, id) {
	InitAspects();
}
Alien::~Alien() {
}

void Alien::InitAspects() {
	aspects.reserve(2);
	aspects.push_back(new Physics(this));
	aspects.push_back(new Renderable(this));
	ai = new UnitAI(this);
	aspects.push_back(ai);
}

//-----------------------------------------------------------------------------------------------------------

Carrier::Carrier() :
		Entity381() {
	InitAspects();
}
Carrier::Carrier(Engine * engine, Ogre::Vector3 pos, float heading, int id) :
		Entity381(engine, "cvn68.mesh", pos, heading, 0, 100, 8, 5, id) {
	InitAspects();
}
Carrier::~Carrier() {
}

void Carrier::InitAspects() {
	aspects.reserve(2);
	aspects.push_back(new Physics(this));
	aspects.push_back(new Renderable(this));
	ai = new UnitAI(this);
	aspects.push_back(ai);
}

//-----------------------------------------------------------------------------------------------------------

Destroyer::Destroyer() :
		Entity381() {
	InitAspects();
}
Destroyer::Destroyer(Engine * engine, Ogre::Vector3 pos, float heading, int id) :
		Entity381(engine, "ddg51.mesh", pos, heading, 0, 80, 8, 5, id) {
	InitAspects();
}
Destroyer::~Destroyer() {
}

void Destroyer::InitAspects() {
	aspects.reserve(2);
	aspects.push_back(new Physics(this));
	aspects.push_back(new Renderable(this));
	ai = new UnitAI(this);
	aspects.push_back(ai);
}

//-----------------------------------------------------------------------------------------------------------

Frigate::Frigate() :
		Entity381() {
	InitAspects();
}
Frigate::Frigate(Engine * engine, Ogre::Vector3 pos, float heading, int id) :
		Entity381(engine, "sleek.mesh", pos, heading, 0, 60, 15, 10, id) {
	InitAspects();
}
Frigate::~Frigate() {
}

void Frigate::InitAspects() {
	aspects.reserve(2);
	aspects.push_back(new Physics(this));
	aspects.push_back(new Renderable(this));
	ai = new UnitAI(this);
	aspects.push_back(ai);
}

//-----------------------------------------------------------------------------------------------------------

Speedboat::Speedboat() :
		Entity381() {
	InitAspects();
}
Speedboat::Speedboat(Engine * engine, Ogre::Vector3 pos, float heading, int id) :
		Entity381(engine, "cigarette.mesh", pos, heading, 0, 50, 20, 50, id) {
	InitAspects();
}
Speedboat::~Speedboat() {
}

void Speedboat::InitAspects() {
	aspects.reserve(2);
	aspects.push_back(new Physics(this));
	aspects.push_back(new Renderable(this));
	ai = new UnitAI(this);
	aspects.push_back(ai);
}

//-----------------------------------------------------------------------------------------------------------
