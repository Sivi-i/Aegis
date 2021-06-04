#ifndef MAGEBUILDER_H
#define MAGEBUILDER_H

#include "EnemyBuilder.h"
#include "Mage.h"

class MageBuilder : public EnemyBuilder {
public:

	MageBuilder();
	~MageBuilder();
	void setLevel(int level);
	void setHP(int hp);
	void setAttack(int attack);
	void setDefense(int defense);
	void setSpeed(int speed);
	void setMagic(int magic);
	void setType(const char* type);
	Mage* getProduct();
	void reset();

protected:
	Mage* mage;
};



#endif