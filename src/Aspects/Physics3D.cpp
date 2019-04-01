/*
 * Physics3D.cpp
 *
 *  Created on: Mar 23, 2019
 *      Author: kylebrain
 */

#include "Physics3D.h"
#include <OgreMath.h>
#include "Entity381.h"
#include "Entity3D.h"

Physics3D::Physics3D(Entity381 * _entity) :
		Aspect(_entity) {
}
Physics3D::~Physics3D() {

}

void Physics3D::Tick(float dt) {
	Entity3D * entAlt = dynamic_cast<Entity3D*>(entity);
	if(entAlt != NULL) {
		if(entAlt->desiredAltitude > entAlt->altitude) {
			entAlt->altitude += entAlt->climbRate;
		} else if (entAlt->desiredAltitude < entAlt->altitude) {
			entAlt->altitude -= entAlt->climbRate;
		}
		entAlt->position = Ogre::Vector3(entAlt->position.x, entAlt->altitude, entAlt->position.z);
	}
}
