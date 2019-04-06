/*
 * AI.h
 *
 *  Created on: Mar 25, 2019
 *      Author: kylebrain
 */

#ifndef INC_ASPECTS_UNITAI_H_
#define INC_ASPECTS_UNITAI_H_

#include "Aspect.h"
#include "OgreVector3.h"

class UnitAI : public Aspect {

public:
	UnitAI(Entity381 * _entity);
	~UnitAI();

	void Tick(float dt) override;
//private:
	//void MoveTo(Ogre::Vector3 position);
	//void Follow(Entity381 * followEnt);
};



#endif /* INC_ASPECTS_UNITAI_H_ */
