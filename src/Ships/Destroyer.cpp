/*
 * Destroyer.cpp
 *
 *  Created on: Mar 3, 2019
 *      Author: kylebrain
 */

#include "Destroyer.h"
#include "Physics.h"
#include "Renderable.h"
#include "AI.h"

Destroyer::Destroyer() :
		Entity381() {
	InitAspects();
}
Destroyer::Destroyer(Engine * engine, Ogre::Vector3 pos, float heading,
		int id) :
		Entity381(engine, "ddg51.mesh", pos, heading, 0, 80, 8, 5, id) {
	InitAspects();
}
Destroyer::~Destroyer() {
}

void Destroyer::InitAspects() {
	aspects.reserve(2);
	aspects.push_back(new Physics(this));
	aspects.push_back(new Renderable(this));
	aspects.push_back(new AI(this));
}

