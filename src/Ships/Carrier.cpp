/*
 * Carrier.cpp
 *
 *  Created on: Mar 3, 2019
 *      Author: kylebrain
 */

#include "Carrier.h"
#include "Physics.h"
#include "Renderable.h"
#include "AI.h"

Carrier::Carrier() :
		Entity381() {
	InitAspects();
}
Carrier::Carrier(Engine * engine, Ogre::Vector3 pos, float heading,
		int id) :
		Entity381(engine, "cvn68.mesh", pos, heading, 0, 100, 8, 5, id) {
	InitAspects();
}
Carrier::~Carrier() {
}

void Carrier::InitAspects() {
	aspects.reserve(2);
	aspects.push_back(new Physics(this));
	aspects.push_back(new Renderable(this));
	aspects.push_back(new AI(this));
}


