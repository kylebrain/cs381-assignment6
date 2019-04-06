/*
 * Entity3D.cpp
 *
 *  Created on: Mar 23, 2019
 *      Author: kylebrain
 */
//now includes functions for banshee class

#include <UnitAI.h>
#include "Entity3D.h"
#include "Physics.h"
#include "Renderable.h"
#include "Physics3D.h"

Entity3D::Entity3D() : Entity381(), altitude(0), desiredAltitude(0), climbRate(0) {

}
Entity3D::Entity3D(Engine * engine, string meshName, Ogre::Vector3 pos,
		float _heading, float _minSpeed, float _maxSpeed,
		float _acceleration, float _turningRate, float _altitude,
		float _climbRate, int id) : Entity381(engine, meshName, pos, _heading,
		_minSpeed, _maxSpeed, _acceleration, _turningRate, id), altitude(_altitude), desiredAltitude(_altitude), climbRate(_climbRate) {}
Entity3D::~Entity3D() {}

void Entity3D::InitAspects() {

}

Banshee::Banshee() {
	InitAspects();
}
Banshee::Banshee(Engine * engine, Ogre::Vector3 pos, float heading,
		float altitude, int id) :
		Entity3D(engine, "banshee.mesh", pos, heading, 0, 200, 100, 50, altitude, 1, id) {
	InitAspects();
}
Banshee::~Banshee() {

}

void Banshee::InitAspects() {
	aspects.reserve(3);
	aspects.push_back(new Physics(this));
	aspects.push_back(new Physics3D(this));
	aspects.push_back(new Renderable(this));
	aspects.push_back(new UnitAI(this));

}

