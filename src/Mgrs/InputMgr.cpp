/*
 * InputMgr.cpp
 *
 *  Created on: Mar 10, 2019
 *      Author: kylebrain
 */

#include "InputMgr.h"
#include <OgreVector3.h>
#include <OgreRenderWindow.h>
#include <exception>
//#include <CEGUI/CEGUI.h>

#include "Engine.h"
#include "GfxMgr.h"
#include "EntityMgr.h"
#include "GameMgr.h"
#include "Command.h"
#include "UnitAI.h"

InputMgr::InputMgr(Engine * engine) :
		Mgr(engine), mInputMgr(0), mMouse(0), mKeyboard(0), shiftPressed(false) {
}

void InputMgr::Tick(float dt) {

	mKeyboard->capture();
	mMouse->capture();

	engine->gameMgr->cameraSpeed = 100;
	engine->gameMgr->cameraYawSpeed = .01f;

	if (mKeyboard->isKeyDown(OIS::KC_ESCAPE)) {
		engine->keepRunning = false;
	}
	if (mKeyboard->isKeyDown(OIS::KC_P)) {
		engine->keepRunning = false;
	}

	Ogre::Vector3 cameraMovement = Ogre::Vector3::ZERO;

	if (mKeyboard->isKeyDown(OIS::KC_LSHIFT)) {
		engine->gameMgr->cameraSpeed = 250;
		engine->gameMgr->cameraYawSpeed = .025f;
	}
	if (mKeyboard->isKeyDown(OIS::KC_R)) {
		cameraMovement += Ogre::Vector3::UNIT_Y * engine->gameMgr->cameraSpeed
				* dt;
	}
	if (mKeyboard->isKeyDown(OIS::KC_F)) {
		if (engine->gfxMgr->cameraNode->getPosition().y <= 10) {
			return;
		}
		cameraMovement += Ogre::Vector3::NEGATIVE_UNIT_Y
				* engine->gameMgr->cameraSpeed * dt;
	}

	if (mKeyboard->isKeyDown(OIS::KC_W)) {
		cameraMovement += Ogre::Vector3::NEGATIVE_UNIT_Z
				* engine->gameMgr->cameraSpeed * dt;
	}
	if (mKeyboard->isKeyDown(OIS::KC_S)) {
		cameraMovement += Ogre::Vector3::UNIT_Z * engine->gameMgr->cameraSpeed
				* dt;
	}
	if (mKeyboard->isKeyDown(OIS::KC_A)) {
		cameraMovement += Ogre::Vector3::NEGATIVE_UNIT_X
				* engine->gameMgr->cameraSpeed * dt;
	}
	if (mKeyboard->isKeyDown(OIS::KC_D)) {
		cameraMovement += Ogre::Vector3::UNIT_X * engine->gameMgr->cameraSpeed
				* dt;
	}
	if (mKeyboard->isKeyDown(OIS::KC_Z)) {
		engine->gfxMgr->cameraNode->pitch(
				Ogre::Radian(-engine->gameMgr->cameraYawSpeed),
				Ogre::Node::TransformSpace::TS_LOCAL);
	}
	if (mKeyboard->isKeyDown(OIS::KC_X)) {
		engine->gfxMgr->cameraNode->pitch(
				Ogre::Radian(engine->gameMgr->cameraYawSpeed),
				Ogre::Node::TransformSpace::TS_LOCAL);
	}
	if (mKeyboard->isKeyDown(OIS::KC_Q)) {
		engine->gfxMgr->cameraNode->yaw(
				Ogre::Radian(engine->gameMgr->cameraYawSpeed),
				Ogre::Node::TransformSpace::TS_WORLD);
	}
	if (mKeyboard->isKeyDown(OIS::KC_E)) {
		engine->gfxMgr->cameraNode->yaw(
				Ogre::Radian(-engine->gameMgr->cameraYawSpeed),
				Ogre::Node::TransformSpace::TS_WORLD);
	}

	engine->gfxMgr->cameraNode->translate(cameraMovement,
			Ogre::Node::TransformSpace::TS_LOCAL);
}

bool InputMgr::keyPressed(const OIS::KeyEvent &arg) {

	float newSpeed = engine->entityMgr->GetSelectedDesiredSpeed();
	float newHeading = engine->entityMgr->GetSelectedDesiredHeading();
	float newAltitude = engine->entityMgr->GetSelectedDesiredAltitude();

	switch (arg.key) {
	case OIS::KC_NUMPAD8:
		newSpeed += engine->gameMgr->speedIncreasePerPress;
		break;
	case OIS::KC_NUMPAD2:
		newSpeed -= engine->gameMgr->speedIncreasePerPress;
		break;
	case OIS::KC_NUMPAD6:
		newHeading += engine->gameMgr->speedIncreasePerPress;
		break;
	case OIS::KC_NUMPAD4:
		newHeading -= engine->gameMgr->speedIncreasePerPress;
		break;
	case OIS::KC_PGUP:
		newAltitude += engine->gameMgr->altitudeIncreasePerPress;
		break;
	case OIS::KC_PGDOWN:
		newAltitude -= engine->gameMgr->altitudeIncreasePerPress;
		break;
	case OIS::KC_TAB:
		engine->entityMgr->CycleSelectEntity();
		newSpeed = engine->entityMgr->GetSelectedDesiredSpeed();
		newHeading = engine->entityMgr->GetSelectedDesiredHeading();
		newAltitude = engine->entityMgr->GetSelectedDesiredAltitude();
		break;
	case OIS::KC_LSHIFT:
		shiftPressed = true;
		break;
	default:
		// not implemented!
		break;

	}

	engine->entityMgr->SetSelectedDesiredSpeed(newSpeed);
	engine->entityMgr->SetSelectedDesiredHeading(newHeading);
	engine->entityMgr->SetSelectedDesiredAltitude(newAltitude);

	return true;
}

bool InputMgr::keyReleased(const OIS::KeyEvent &arg) {

	switch(arg.key) {
	case OIS::KC_LSHIFT:
		shiftPressed = false;
		break;
	default:
		break;
	}

	return true;
}

bool InputMgr::mouseMoved(const OIS::MouseEvent &arg) {

	return true;
}

bool InputMgr::mousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id) {

	int entIndex;
	switch (id) {
	case OIS::MB_Left:

		try {
			Ogre::Vector3 clickedPos = GetClickPosition(arg);
			engine->entityMgr->SelectEntity(GetClickedEntityIndex(clickedPos));
		} catch (const std::exception & e) {
		}

		break;
	case OIS::MB_Right: {

		try {
			Ogre::Vector3 clickedPos = GetClickPosition(arg);
			int index = GetClickedEntityIndex(clickedPos);
			Entity381 * clickedEntity = engine->entityMgr->entities[index];
			Command * newCommand;
			if(clickedEntity->position.distance(clickedPos) <= engine->gameMgr->entityClickThreshold) {
				// clicked on an entity
				newCommand = new Intercept(engine->entityMgr->selectedEntity, clickedEntity);
			} else {
				// clicked on the water
				newCommand = new MoveTo(engine->entityMgr->selectedEntity, clickedPos);

			}

			if(shiftPressed) {
				engine->entityMgr->selectedEntity->ai->AddCommand(newCommand);
			} else {
				engine->entityMgr->selectedEntity->ai->SetCommand(newCommand);
			}

		} catch (const std::exception & e) {
		}

		break;
	}
	default:
		break;
	}

	return true;
}

Ogre::Vector3 InputMgr::GetClickPosition(const OIS::MouseEvent &arg) {
	Ogre::Ray mouseRay = engine->gfxMgr->mCamera->getCameraToViewportRay(
			arg.state.X.abs / Ogre::Real(engine->gfxMgr->vp->getActualWidth()),
			arg.state.Y.abs
					/ Ogre::Real(engine->gfxMgr->vp->getActualHeight()));

	std::pair<bool, float> result = mouseRay.intersects(
			engine->gameMgr->groundPlane);
	if (result.first) {
		return mouseRay.getPoint(result.second);
	} else {
		throw logic_error("Did not intercept with plane!");
	}
}

int InputMgr::GetClickedEntityIndex(Ogre::Vector3 clickedPos) {
	return engine->entityMgr->GetClosestEntityIndex(clickedPos);
}

bool InputMgr::mouseReleased(const OIS::MouseEvent &arg,
		OIS::MouseButtonID id) {

	return true;
}

void InputMgr::Init() {
	// OIS
	Ogre::LogManager::getSingletonPtr()->logMessage("*** Initializing OIS ***");

	OIS::ParamList pl;
	size_t windowHandle = 0;
	std::ostringstream windowHandleStr;

	engine->gfxMgr->mWindow->getCustomAttribute("WINDOW", &windowHandle);
	windowHandleStr << windowHandle;
	pl.insert(std::make_pair(std::string("WINDOW"), windowHandleStr.str()));

#if defined OIS_WIN32_PLATFORM
	pl.insert(std::make_pair(std::string("w32_mouse"), std::string("DISCL_FOREGROUND" )));
	pl.insert(std::make_pair(std::string("w32_mouse"), std::string("DISCL_NONEXCLUSIVE")));
	pl.insert(std::make_pair(std::string("w32_keyboard"), std::string("DISCL_FOREGROUND")));
	pl.insert(std::make_pair(std::string("w32_keyboard"), std::string("DISCL_NONEXCLUSIVE")));
#elif defined OIS_LINUX_PLATFORM
	pl.insert(
			std::make_pair(std::string("x11_mouse_grab"),
					std::string("false")));
	pl.insert(
			std::make_pair(std::string("x11_mouse_hide"),
					std::string("false")));
	pl.insert(
			std::make_pair(std::string("x11_keyboard_grab"),
					std::string("false")));
	pl.insert(
			std::make_pair(std::string("XAutoRepeatOn"), std::string("true")));
#endif

	mInputMgr = OIS::InputManager::createInputSystem(pl);

	mKeyboard = static_cast<OIS::Keyboard*>(mInputMgr->createInputObject(
			OIS::OISKeyboard, true));
	mMouse = static_cast<OIS::Mouse*>(mInputMgr->createInputObject(
			OIS::OISMouse, true));

	mKeyboard->setEventCallback(this);
	mMouse->setEventCallback(this);

	windowResized(engine->gfxMgr->mWindow);
	Ogre::WindowEventUtilities::addWindowEventListener(engine->gfxMgr->mWindow,
			this);
}
void InputMgr::LoadLevel() {

}
void InputMgr::Stop() {

}

