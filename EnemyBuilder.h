/*
*EnemyBuilder is an Interface used to define the methods for the following concrete classes will be using it as an interface: 
*FighterBuilder, KnightBuilder, WarriorBuilder, and MageBuilder. 
*/
#ifndef ENEMYBUILDER_H
#define ENEMYBUILDER_H

#include <string>
#include <vector>

class EnemyBuilder {

public:

	//Default Destructor
	virtual ~EnemyBuilder() {};

	//Setter for Enemy's Initial Level
	virtual void setLevel(int level) = 0; 

	//Setter for Enemy's Initial Health Points
	virtual void setHP(int hp) = 0;

	//Setter for Enemy's Initial Attack Level
	virtual void setAttack(int attack) = 0;

	//Setter for Enemy's Initial Defense Level
	virtual void setDefense(int defense) = 0;

	//Setter for Enemy's Initial Speed Level
	virtual void setSpeed(int speed) = 0;

	//Setter for Enemy's Initial Magic Level
	virtual void setMagic(int magic) = 0;

	//Setter for the Enemy's Type
	virtual void setType(const char* type)=0;

	//Resets the Current Enemy Builder & Enemy in order to create a new one
	virtual void reset() = 0;

	//Returns the current Stats of the Enemy being built
	//virtual std::vector<int> getStats();

};

#endif