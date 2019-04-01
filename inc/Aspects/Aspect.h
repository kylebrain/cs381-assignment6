/*
 * Aspect.h
 *
 *  Created on: Feb 24, 2019
 *      Author: kylebrain
 */

#ifndef INC_ASPECT_H_
#define INC_ASPECT_H_

class Entity381;

class Aspect {

public:

	Aspect(Entity381 * _entity);
	virtual ~Aspect();


	Entity381 * entity;
	virtual void Tick(float dt) = 0;


};


#endif /* INC_ASPECT_H_ */
