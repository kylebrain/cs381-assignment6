/*
 * Frigate.cpp
 *
 *  Created on: Mar 3, 2019
 *      Author: kylebrain
 */

#include "Frigate.h"
#include "Physics.h"
#include "Renderable.h"
#include "AI.h"

Frigate::Frigate() :
		Entity381() {
	InitAspects();
}
Frigate::Frigate(Engine * engine, Ogre::Vector3 pos, float heading,
		int id) :
		Entity381(engine, "sleek.mesh", pos, heading, 0, 60, 15, 10, id) {
	InitAspects();
}
Frigate::~Frigate() {
}

void Frigate::InitAspects() {
	aspects.reserve(2);
	aspects.push_back(new Physics(this));
	aspects.push_back(new Renderable(this));
	aspects.push_back(new AI(this));
}


