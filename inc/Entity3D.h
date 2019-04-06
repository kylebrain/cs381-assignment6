/*
 * Entity3D.h
 *
 *  Created on: Mar 23, 2019
 *      Author: kylebrain
 */
//now includes banshee class

#ifndef INC_ENTITY3D_H_
#define INC_ENTITY3D_H_

#include "Entity381.h"
#include "Entity3D.h"

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

class Banshee : public Entity3D {
public:
	Banshee();
	Banshee(Engine * engine, Ogre::Vector3 pos, float heading, float altitude, int id);
	virtual ~Banshee();

	virtual void InitAspects();
};

#endif /* INC_ENTITY3D_H_ */
