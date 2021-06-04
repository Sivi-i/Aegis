#ifndef WARRIORBUILDER_H
#define WARRIORBUILDER_H

#include "EnemyBuilder.h"
#include "Warrior.h"

class WarriorBuilder : public EnemyBuilder {

public:
	WarriorBuilder();
	~WarriorBuilder();
	void setLevel(int level);
	void setHP(int hp);
	void setAttack(int attack);
	void setDefense(int defense);
	void setSpeed(int speed);
	void setMagic(int magic);
	void setType(const char* type);
	Warrior* getProduct();
	void reset();

protected:
	Warrior* warrior;

};

#endif