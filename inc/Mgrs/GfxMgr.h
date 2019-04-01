/*
 * GfxMgr.h
 *
 *  Created on: Mar 10, 2019
 *      Author: kylebrain
 */

#ifndef INC_GFXMGR_H_
#define INC_GFXMGR_H_

#include <OgreRoot.h>

#include "Mgr.h"

class GfxMgr: public Mgr {
public:

	GfxMgr(Engine * engine);

	virtual void Init();
	virtual void Tick(float dt);
	virtual void LoadLevel();
	virtual void Stop();

	Ogre::Root* mRoot;
	Ogre::String mResourcesCfg;
	Ogre::String mPluginsCfg;

	Ogre::RenderWindow* mWindow;
	Ogre::SceneManager* mSceneMgr;
	Ogre::Camera* mCamera;
	Ogre::SceneNode * cameraNode;
	Ogre::Viewport* vp;
};

#endif /* INC_GFXMGR_H_ */
