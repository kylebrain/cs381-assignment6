/*
 * Renderable.cpp
 *
 *  Created on: Feb 24, 2019
 *      Author: kylebrain
 */

#include "Renderable.h"
#include "Entity381.h"

Renderable::Renderable(Entity381 * _entity) : Aspect(_entity) {}
Renderable::~Renderable() {

}

void Renderable::Tick(float dt) {
	entity->ogreSceneNode->setPosition(entity->position);
	entity->ogreSceneNode->resetOrientation();
	entity->ogreSceneNode->yaw(Ogre::Degree(-entity->heading));
}


