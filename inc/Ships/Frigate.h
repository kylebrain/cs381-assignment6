/*
 * Frigate.h
 *
 *  Created on: Mar 3, 2019
 *      Author: kylebrain
 */

#ifndef INC_FRIGATE_H_
#define INC_FRIGATE_H_

#include "Entity381.h"

class Frigate : public Entity381 {
public:
	Frigate();
	Frigate(Engine * engine, Ogre::Vector3 pos, float heading, int id);
	virtual ~Frigate();

	virtual void InitAspects();
};



#endif /* INC_FRIGATE_H_ */
