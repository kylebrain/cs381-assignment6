/*
 * InputMgr.h
 *
 *  Created on: Mar 10, 2019
 *      Author: kylebrain
 */

#ifndef INC_INPUTMGR_H_
#define INC_INPUTMGR_H_

#include <OgreWindowEventUtilities.h>

#include <OISEvents.h>
#include <OISInputManager.h>
#include <OISKeyboard.h>
#include <OISMouse.h>

#include "Mgr.h"

class InputMgr: public Mgr,
		public Ogre::WindowEventListener,
		public OIS::KeyListener,
		public OIS::MouseListener {
public:
	InputMgr(Engine * engine);

	virtual void Init();
	virtual void Tick(float dt);
	virtual void LoadLevel();
	virtual void Stop();

	OIS::InputManager* mInputMgr;
	OIS::Keyboard* mKeyboard;
	OIS::Mouse* mMouse;

protected:
	virtual bool keyPressed(const OIS::KeyEvent &arg);
	virtual bool keyReleased(const OIS::KeyEvent &arg);
	virtual bool mouseMoved(const OIS::MouseEvent &arg);
	virtual bool mousePressed(const OIS::MouseEvent &arg,
			OIS::MouseButtonID id);
	virtual bool mouseReleased(const OIS::MouseEvent &arg,
			OIS::MouseButtonID id);

private:
	int GetClickedEntityIndex(Ogre::Vector3 clickedPos);
	Ogre::Vector3 GetClickPosition(const OIS::MouseEvent &arg);
	bool shiftPressed;
};

#endif /* INC_INPUTMGR_H_ */
