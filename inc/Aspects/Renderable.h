/*
 * Renderable.h
 *
 *  Created on: Feb 24, 2019
 *      Author: kylebrain
 */

#ifndef INC_RENDERABLE_H_
#define INC_RENDERABLE_H_

#include "Aspect.h"

class Renderable : public Aspect {

public:
	Renderable(Entity381 * _entity);
	~Renderable();

	void Tick(float dt) override;
};


#endif /* INC_RENDERABLE_H_ */
