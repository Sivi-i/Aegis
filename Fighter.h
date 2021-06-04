#ifndef FIGHTER_H
#define FIGHTER_H

#include "Enemy.h"
#include <string>
#include <iostream>

class Fighter : public Enemy {

	friend class FighterBuilder;

public:
	/*
	*Takes the Damage dealt by the player (As an Integer) and subtracts it from
	*Enemy's current Health Points.
	* @param[in]	damage		Non-zero Integer
	*/
	void tookDamage(int dmg);

	/*
	*Calculates the amount of damage the enemy does when attacking.
	* @return		(int)			Damage of Attack
	*/
	int attacking();

	
	/*
	*A 3 hit combo that does 60% of the enemy's attack damage on the first two hits and 110% on the last.
	* @return		(std::vector<int>)		Damage of Combo 3x
	*/
	std::vector<int> specialAttack();


	//@return		(char*)Enemy Type
	char* getType();


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
