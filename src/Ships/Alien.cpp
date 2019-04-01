/*
 * Alien.cpp
 *
 *  Created on: Mar 3, 2019
 *      Author: kylebrain
 */

#include "Alien.h"
#include "Physics.h"
#include "Renderable.h"
#include "AI.h"

Alien::Alien() :
		Entity381() {
	InitAspects();
}
Alien::Alien(Engine * engine, Ogre::Vector3 pos, float heading,
		int id) :
		Entity381(engine, "alienship.mesh", pos, heading, 0, 200, 100, 50, id) {
	InitAspects();
}
Alien::~Alien() {
}

void Alien::InitAspects() {
	aspects.reserve(2);
	aspects.push_back(new Physics(this));
	aspects.push_back(new Renderable(this));
	aspects.push_back(new AI(this));
}


