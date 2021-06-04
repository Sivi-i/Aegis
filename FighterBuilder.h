#ifndef FIGHTERBUILDER_H
#define FIGHTERBUILDER_H

#include "EnemyBuilder.h"
#include "Fighter.h"

class FighterBuilder : public EnemyBuilder {
public:
	FighterBuilder();
	~FighterBuilder();
	void setLevel(int level);
	void setHP(int hp);
	void setAttack(int attack);
	void setDefense(int defense);
	void setSpeed(int speed);
	void setMagic(int magic);
	void setType(const char* type);
	Fighter* getProduct();
	void reset();

protected:
	Fighter* fighter;
};

#endif