/*
 * Command.h
 *
 *  Created on: Mar 28, 2018
 *      Author: sushil
 */

#ifndef COMMAND_H_
#define COMMAND_H_

#include <Entity381.h>
#include <OgreVector3.h>

enum COMMAND_TYPE { MOVE_TO, INTERCEPT };

class Command {

public:
	Command(Entity381* ent, COMMAND_TYPE ct);
	virtual ~Command();

	virtual void init() = 0;
	virtual void tick(float dt) = 0;
	virtual bool done() = 0;

	Entity381* entity;
	COMMAND_TYPE commandType;

protected:
	void Goto(Ogre::Vector3 pos);

};

class MoveTo: public Command {

public:
	MoveTo(Entity381* ent, Ogre::Vector3 location);
	~MoveTo();

	void init();
	void tick(float dt);
	bool done();

	Ogre::Vector3 targetLocation;
	float MOVE_DISTANCE_THRESHOLD;

};

class Intercept: public Command {

public:
	Intercept(Entity381* ent, Entity381* target);
	~Intercept();

	void init();
	void tick(float dt);
	bool done();

	Entity381 * targetEntity;
	float MOVE_DISTANCE_THRESHOLD;

};




#endif /* COMMAND_H_ */
