/*
 * GameMgr.cpp
 *
 *  Created on: Mar 10, 2019
 *      Author: kylebrain
 */

#include <OgreMeshManager.h>

#include "GameMgr.h"
#include "GfxMgr.h"
#include "EntityMgr.h"

GameMgr::GameMgr(Engine * engine) : Mgr(engine), surfaceHeight(0), headingIncreasePerPress(15), speedIncreasePerPress(
		50), cameraSpeed(100), cameraYawSpeed(0.01f), altitudeIncreasePerPress(50) {}

void GameMgr::Tick(float dt) {
}

void GameMgr::Init() {

}
void GameMgr::LoadLevel() {
	CreateLighting();
	CreateFloor();
	CreateObjects();
}
void GameMgr::Stop() {

}

void GameMgr::CreateLighting() {
	engine->gfxMgr->mSceneMgr->setAmbientLight(
			Ogre::ColourValue(0.5, 0.5, 0.5));
	engine->gfxMgr->mSceneMgr->setShadowTechnique(
			Ogre::SHADOWTYPE_STENCIL_ADDITIVE);

	engine->gfxMgr->mSceneMgr->setSkyBox(true, "Examples/CloudyNoonSkyBox");

	Ogre::Light* pointLight = engine->gfxMgr->mSceneMgr->createLight(
			"PointLight");
	pointLight->setType(Ogre::Light::LT_POINT);
	pointLight->setPosition(250, 150, 250);
	pointLight->setDiffuseColour(Ogre::ColourValue::White);
	pointLight->setSpecularColour(Ogre::ColourValue::White);
}

void GameMgr::CreateFloor() {
	// create the plane
	Ogre::Plane plane(Ogre::Vector3::UNIT_Y, 0);
	groundPlane = plane;
	Ogre::MeshManager::getSingleton().createPlane("ground",
			Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, plane,
			10000, 10000, 20, 20, true, 1, 5, 5, Ogre::Vector3::UNIT_Z);

	Ogre::SceneNode* floorNode =
			engine->gfxMgr->mSceneMgr->getRootSceneNode()->createChildSceneNode();
	Ogre::Entity* floorEntity = engine->gfxMgr->mSceneMgr->createEntity(
			"ground");
	floorNode->attachObject(floorEntity);

	floorEntity->setMaterialName("OceanCg");
	floorEntity->setCastShadows(false);
	floorNode->setPosition(0, surfaceHeight, 0);
}

void GameMgr::CreateObjects() {
	const int spawnDistance = 250;

	// spawn Entities
	for (int i = 0; i < 6; i++) {
		engine->entityMgr->CreateEntityOfTypeAtPositionAndHeading(
				static_cast<EntityMgr::EntityType>(i),
				Ogre::Vector3(spawnDistance * (i - 3), 0, 0), 0);
	}
}

