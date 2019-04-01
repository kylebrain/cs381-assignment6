/*
 * EntityMgr.cpp
 *
 *  Created on: Feb 24, 2019
 *      Author: kylebrain
 */

#include "EntityMgr.h"
#include "Destroyer.h"
#include "Carrier.h"
#include "Speedboat.h"
#include "Frigate.h"
#include "Alien.h"
#include "Entity3D.h"
#include "Banshee.h"
#include <exception>

EntityMgr::EntityMgr(Engine * engine) :
		Mgr(engine), idCount(0), selectedIndex(0), selectedEntity(NULL) {
}

EntityMgr::~EntityMgr() {

}

Entity381* EntityMgr::CreateEntityOfTypeAtPositionAndHeading(EntityType type,
		Ogre::Vector3 pos, float heading) {
	Entity381 * ret;
	switch (type) {
	case DestroyerType:
		ret = new Destroyer(engine, pos, heading, idCount);
		break;
	case CarrierType:
		ret = new Carrier(engine, pos, heading, idCount);
		break;
	case SpeedboatType:
		ret = new Speedboat(engine, pos, heading, idCount);
		break;
	case FrigateType:
		ret = new Frigate(engine, pos, heading, idCount);
		break;
	case AlienType:
		ret = new Alien(engine, pos, heading, idCount);
		break;
	case BansheeType:
		ret = new Banshee(engine, pos, heading, 0, idCount);
		break;
	default:
		throw runtime_error("Enum not implemented in EntityMgr CreateEntity!");
	}

	if (selectedEntity == NULL && entities.size() == 0) {
		selectedEntity = ret;
		selectedIndex = 0;
		selectedEntity->ogreSceneNode->showBoundingBox(true);
	}

	idCount++;
	entities.push_back(ret);

	return ret;

}

void EntityMgr::CycleSelectEntity() {
	selectedIndex = (selectedIndex + 1) % entities.size();
	selectedEntity->ogreSceneNode->showBoundingBox(false);
	selectedEntity = entities[selectedIndex];
	selectedEntity->ogreSceneNode->showBoundingBox(true);
}

int EntityMgr::GetClosestEntityIndex(Ogre::Vector3 clickedPos) {
	float minDist = entities[0]->position.squaredDistance(clickedPos);
	int minEnt = 0;

	for (int i = 1; i < entities.size(); i++) {
		float dist = entities[i]->position.squaredDistance(clickedPos);
		if (dist < minDist) {
			minEnt = i;
			minDist = dist;
		}
	}

	return minEnt;
}
void EntityMgr::SelectEntity(int entityIndex) {
	selectedIndex = entityIndex;
	selectedEntity->ogreSceneNode->showBoundingBox(false);
	selectedEntity = entities[selectedIndex];
	selectedEntity->ogreSceneNode->showBoundingBox(true);
}

void EntityMgr::SetSelectedDesiredSpeed(float speed) {
	if (selectedEntity != NULL) {
		selectedEntity->desiredSpeed = speed;
	}
}
float EntityMgr::GetSelectedDesiredSpeed() const {
	if (selectedEntity != NULL) {
		return selectedEntity->desiredSpeed;
	} else {
		return 0;
	}
}

void EntityMgr::SetSelectedDesiredHeading(float heading) {
	if (selectedEntity != NULL) {
		selectedEntity->desiredHeading = heading;
	}
}

float EntityMgr::GetSelectedDesiredHeading() const {
	if (selectedEntity != NULL) {
		return selectedEntity->desiredHeading;
	} else {
		return 0;
	}
}

void EntityMgr::SetSelectedDesiredAltitude(float altitude) {
	if (selectedEntity != NULL) {
		Entity3D * altEnt = dynamic_cast<Entity3D*>(selectedEntity);
		if (altEnt != NULL) {
			altEnt->desiredAltitude = altitude;
		}
	}
}
float EntityMgr::GetSelectedDesiredAltitude() const {
	if (selectedEntity != NULL) {
		Entity3D * altEnt = dynamic_cast<Entity3D*>(selectedEntity);
		if (altEnt != NULL) {
			return altEnt->desiredAltitude;
		} else {
			return 0;
		}
	} else {
		return 0;
	}
}

void EntityMgr::Tick(float dt) {
	for (int i = 0; i < entities.size(); i++) {
		entities[i]->Tick(dt);
	}
}

void EntityMgr::Init() {

}
void EntityMgr::LoadLevel() {

}
void EntityMgr::Stop() {
	for (int i = 0; i < entities.size(); i++) {
		if (entities[i] != NULL) {
			delete entities[i];
		}
	}
}

