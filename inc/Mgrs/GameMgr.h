/*
 * GameMgr.h
 *
 *  Created on: Mar 10, 2019
 *      Author: kylebrain
 */

#ifndef INC_GAMEMGR_H_
#define INC_GAMEMGR_H_

#include "Mgr.h"

class GameMgr: public Mgr {
public:
	GameMgr(Engine * engine);
	virtual void Init();
	virtual void Tick(float dt);
	virtual void LoadLevel();
	virtual void Stop();

	float surfaceHeight;
	float cameraYawSpeed;
	float speedIncreasePerPress;
	float headingIncreasePerPress;
	float altitudeIncreasePerPress;
	float cameraSpeed;

	Ogre::Plane groundPlane;
private:
	void CreateLighting();
	void CreateFloor();
	void CreateObjects();
};

#endif /* INC_GAMEMGR_H_ */
