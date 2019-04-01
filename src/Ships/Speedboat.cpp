/*
 * Speedboat.cpp
 *
 *  Created on: Mar 3, 2019
 *      Author: kylebrain
 */

#include "Speedboat.h"
#include "Physics.h"
#include "Renderable.h"
#include "AI.h"

Speedboat::Speedboat() :
		Entity381() {
	InitAspects();
}
Speedboat::Speedboat(Engine * engine, Ogre::Vector3 pos, float heading,
		int id) :
		Entity381(engine, "cigarette.mesh", pos, heading, 0, 50, 20, 50, id) {
	InitAspects();
}
Speedboat::~Speedboat() {
}

void Speedboat::InitAspects() {
	aspects.reserve(2);
	aspects.push_back(new Physics(this));
	aspects.push_back(new Renderable(this));
	aspects.push_back(new AI(this));
}


