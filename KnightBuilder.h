#ifndef KNIGHTBUILDER_H
#define KNIGHTBUILDER_H

#include "EnemyBuilder.h"
#include "Knight.h"

class KnightBuilder : public EnemyBuilder {
public:
	KnightBuilder();
	~KnightBuilder();
	void setLevel(int level);
	void setHP(int hp);
	void setAttack(int attack);
	void setDefense(int defense);
	void setSpeed(int speed);
	void setMagic(int magic);
	void setType(const char* type);
	Knight* getProduct();
	void reset();

protected:
	Knight* knight;
};

#endif