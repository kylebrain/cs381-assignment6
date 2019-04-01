/*
 * Destroyer.h
 *
 *  Created on: Mar 3, 2019
 *      Author: kylebrain
 */

#ifndef INC_DESTROYER_H_
#define INC_DESTROYER_H_

#include "Entity381.h"

class Destroyer : public Entity381 {
public:
	Destroyer();
	Destroyer(Engine * engine, Ogre::Vector3 pos, float heading, int id);
	virtual ~Destroyer();

	virtual void InitAspects();
};



#endif /* INC_DESTROYER_H_ */
