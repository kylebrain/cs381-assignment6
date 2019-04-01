/*
 * Speedboat.h
 *
 *  Created on: Mar 3, 2019
 *      Author: kylebrain
 */

#ifndef INC_SPEEDBOAT_H_
#define INC_SPEEDBOAT_H_

#include "Entity381.h"

class Speedboat : public Entity381 {
public:
	Speedboat();
	Speedboat(Engine * engine, Ogre::Vector3 pos, float heading, int id);
	virtual ~Speedboat();

	virtual void InitAspects();
};



#endif /* INC_SPEEDBOAT_H_ */
