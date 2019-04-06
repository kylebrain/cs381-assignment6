/*
 * AI.cpp
 *
 *  Created on: Mar 25, 2019
 *      Author: kylebrain
 */

#include <UnitAI.h>
#include "Entity381.h"
#include "OgreMath.h"

UnitAI::UnitAI(Entity381 * _entity) :
		Aspect(_entity) {
}
UnitAI::~UnitAI() {

}

void UnitAI::Tick(float dt) {
	if(!commands.empty()){
		temp->tick(dt);
		if(temp->done()){
			commands.pop_front();
		}
	}

	/*
	if (entity->followEnt != NULL) {
		Follow(entity->followEnt);
	}
	*/
}


/*
void UnitAI::MoveTo(Ogre::Vector3 position) {
	Ogre::Vector3 distanceVector =  position - entity->position;
	entity->desiredHeading = Ogre::Math::ATan2(distanceVector.z, distanceVector.x).valueDegrees();
	entity->desiredSpeed = entity->maxSpeed;
}

void UnitAI::Follow(Entity381 * followEnt) {
	MoveTo(followEnt->position);
}
*/

void UnitAI::SetCommand(Command *c){
	if(!commands.empty()){
		commands.clear();
		commands.push_back(c);
	}
}

void UnitAI::AddCommand(Command *c){
		commands.push_back(c);
}

