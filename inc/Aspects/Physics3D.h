/*
 * Physics3D.h
 *
 *  Created on: Mar 23, 2019
 *      Author: kylebrain
 */

#ifndef INC_ASPECTS_PHYSICS3D_H_
#define INC_ASPECTS_PHYSICS3D_H_

#include "Aspect.h"

class Physics3D : public Aspect {
public:
	Physics3D(Entity381 * _entity);
	~Physics3D();

	void Tick(float dt) override;
};



#endif /* INC_ASPECTS_PHYSICS3D_H_ */
