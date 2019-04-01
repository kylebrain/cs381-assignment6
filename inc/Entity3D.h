/*
 * Entity3D.h
 *
 *  Created on: Mar 23, 2019
 *      Author: kylebrain
 */

#ifndef INC_ENTITY3D_H_
#define INC_ENTITY3D_H_

#include "Entity381.h"

class Entity3D: public Entity381 {
public:
	Entity3D();
	Entity3D(Engine * engine, string meshName, Ogre::Vector3 pos,
			float _heading, float _minSpeed, float _maxSpeed,
			float _acceleration, float _turningRate, float _altitude,
			float _climbRate, int id);
	virtual ~Entity3D();

	float altitude;
	float desiredAltitude;
	float climbRate;

	virtual void InitAspects();
};

#endif /* INC_ENTITY3D_H_ */
