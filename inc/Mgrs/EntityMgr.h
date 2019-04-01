/*
 * EntityMgr.h
 *
 *  Created on: Feb 24, 2019
 *      Author: kylebrain
 */

#ifndef INC_ENTITYMGR_H_
#define INC_ENTITYMGR_H_

#include <OgreSceneManager.h>
#include <vector>

#include "Mgr.h"
#include "Entity381.h"

using namespace std;

class Entity381;

class EntityMgr: public Mgr {
public:

	enum EntityType {
		DestroyerType, CarrierType, SpeedboatType, FrigateType, AlienType, BansheeType
	};

	EntityMgr(Engine * engine);
	virtual ~EntityMgr();
	vector<Entity381*> entities;
	int idCount;

	Entity381* CreateEntityOfTypeAtPositionAndHeading(EntityType type,
			Ogre::Vector3 pos, float heading);

	void CycleSelectEntity();
	int GetClosestEntityIndex(Ogre::Vector3 clickedPos);
	void SelectEntity(int entityIndex);

	void SetSelectedDesiredSpeed(float speed);
	float GetSelectedDesiredSpeed() const;

	void SetSelectedDesiredHeading(float heading);
	float GetSelectedDesiredHeading() const;

	void SetSelectedDesiredAltitude(float altitude);
	float GetSelectedDesiredAltitude() const;

	virtual void Init();
	virtual void Tick(float dt);
	virtual void LoadLevel();
	virtual void Stop();

//private:
	Entity381* selectedEntity;
	int selectedIndex;

};

#endif /* INC_ENTITYMGR_H_ */
