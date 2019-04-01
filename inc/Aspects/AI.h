/*
 * AI.h
 *
 *  Created on: Mar 25, 2019
 *      Author: kylebrain
 */

#ifndef INC_ASPECTS_AI_H_
#define INC_ASPECTS_AI_H_

#include "Aspect.h"
#include "OgreVector3.h"

class AI : public Aspect {

public:
	AI(Entity381 * _entity);
	~AI();

	void Tick(float dt) override;
private:
	void MoveTo(Ogre::Vector3 position);
	void Follow(Entity381 * followEnt);
};



#endif /* INC_ASPECTS_AI_H_ */
