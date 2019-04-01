/*
 * Alien.h
 *
 *  Created on: Mar 3, 2019
 *      Author: kylebrain
 */

#ifndef INC_ALIEN_H_
#define INC_ALIEN_H_

#include "Entity381.h"

class Alien : public Entity381 {
public:
	Alien();
	Alien(Engine * engine, Ogre::Vector3 pos, float heading, int id);
	virtual ~Alien();

	virtual void InitAspects();
};



#endif /* INC_ALIEN_H_ */
