/*
 * GfxMgr.cpp
 *
 *  Created on: Mar 10, 2019
 *      Author: kylebrain
 */

#include <OgreConfigFile.h>
#include <OgreRenderWindow.h>
#include <OgreSceneNode.h>
#include <OgreEntity.h>

#include "GfxMgr.h"

GfxMgr::GfxMgr(Engine * engine) :
		Mgr(engine), mRoot(0), mResourcesCfg(Ogre::StringUtil::BLANK), mPluginsCfg(
				Ogre::StringUtil::BLANK), mWindow(0), mSceneMgr(0), mCamera(0), cameraNode(
		NULL) {
}

void GfxMgr::Tick(float dt) {

	mRoot->renderOneFrame();;
}

void GfxMgr::Init() {
#ifdef _DEBUG
	mResourcesCfg = "resources_d.cfg";
	mPluginsCfg = "plugins_d.cfg";
#else
	mResourcesCfg = "resources.cfg";
	mPluginsCfg = "plugins.cfg";
#endif

	mRoot = new Ogre::Root(mPluginsCfg);

	Ogre::ConfigFile cf;
	cf.load(mResourcesCfg);

	Ogre::String name, locType;
	Ogre::ConfigFile::SectionIterator secIt = cf.getSectionIterator();

	while (secIt.hasMoreElements()) {
		Ogre::ConfigFile::SettingsMultiMap* settings = secIt.getNext();
		Ogre::ConfigFile::SettingsMultiMap::iterator it;

		for (it = settings->begin(); it != settings->end(); ++it) {
			locType = it->first;
			name = it->second;

			Ogre::ResourceGroupManager::getSingleton().addResourceLocation(name,
					locType);
		}
	}

	mRoot->showConfigDialog();

	mWindow = mRoot->initialise(true, "Assignment 4");

	Ogre::TextureManager::getSingleton().setDefaultNumMipmaps(5);
	Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();

	mSceneMgr = mRoot->createSceneManager(Ogre::ST_GENERIC);

	// create camera
	mCamera = mSceneMgr->createCamera("MainCam");
	mCamera->setPosition(0, 0, 80);
	mCamera->lookAt(0, 0, -300);
	mCamera->setNearClipDistance(5);

	vp = mWindow->addViewport(mCamera);
	vp->setBackgroundColour(Ogre::ColourValue(0, 0, 0));

	mCamera->setAspectRatio(
			Ogre::Real(vp->getActualWidth())
					/ Ogre::Real(vp->getActualHeight()));

	cameraNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
	cameraNode->attachObject(mCamera);
	cameraNode->setPosition(0, 180, 800);
}
void GfxMgr::LoadLevel() {

}
void GfxMgr::Stop() {
	delete mRoot;
}

