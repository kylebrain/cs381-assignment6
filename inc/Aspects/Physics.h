/*
 * Physics.h
 *
 *  Created on: Feb 24, 2019
 *      Author: kylebrain
 */

#ifndef INC_PHYSICS_H_
#define INC_PHYSICS_H_

#include "Aspect.h"

class Physics : public Aspect {

public:
	Physics(Entity381 * _entity);
	~Physics();

	void Tick(float dt) override;

private:
	float NormalizeAngle(float angle);
};



#endif /* INC_PHYSICS_H_ */
