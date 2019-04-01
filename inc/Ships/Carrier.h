/*
 * Carrier.h
 *
 *  Created on: Mar 3, 2019
 *      Author: kylebrain
 */

#ifndef INC_CARRIER_H_
#define INC_CARRIER_H_

#include "Entity381.h"

class Carrier : public Entity381 {
public:
	Carrier();
	Carrier(Engine * engine, Ogre::Vector3 pos, float heading, int id);
	virtual ~Carrier();

	virtual void InitAspects();
};



#endif /* INC_CARRIER_H_ */
