#ifndef KNIGHT_H
#define KNIGHT_H

#include "Enemy.h"
#include <string>

class Knight : public Enemy {

	friend class KnightBuilder;

public:

	/*
	*Takes the Damage dealt by the player (As an Integer) and subtracts it from
	*Enemy's current Health Points.
	* @param[in]	dmg		Non-zero Integer
	*/
	void tookDamage(int dmg);

	/*
	*Calculates the amount of damage the enemy does when attacking.
	* @return		(int)			Damage of Attack
	*/
	int attacking();

	//@return		(char*)Enemy Type
	char* getType();


	std::vector<int> specialAttack();


	/*
	*Returns the Stats of the Enemy
	* @return	(std::vector<int>)		Enemy Stats
	*/
	std::vector<int> getStats();


	bool isDefeated();

	int getHP();

	int getLevel();

protected:
	int level;
	int hp;
	int attack;
	int defense;
	int speed;
	int magic;
	const char* type;

};

#endif