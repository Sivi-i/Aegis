#ifndef ENEMY_H
#define ENEMY_H

#include <vector>

class Enemy {
public:
	/*
	*Takes the Damage dealt by the player (As an Integer) and subtracts it from
	*Enemy's current Health Points.
	* @param[in]	damage		Non-zero Integer
	*/
		virtual void tookDamage(int dmg) = 0;

	/*
	*Calculates the amount of damage the enemy does when attacking.
	* @return		(int)			Damage of Attack
	*/
	virtual int attacking() = 0;

	
	//Returns the (char)Type of Enemy the Player is facing
	virtual char* getType() = 0;


	virtual std::vector<int> specialAttack() = 0;

	/*
	*Returns the Stats of the Enemy
	* @return	(std::vector<int>)		Enemy Stats
	*/
	virtual std::vector<int> getStats() = 0;

	/*
	* Checks to see if the Enemy has 0 HP and the battle should end
	* @return		(bool)		Enemy's Life State
	*/
	virtual bool isDefeated() = 0;


	virtual int getHP() = 0;

	virtual int getLevel() = 0;
};

#endif 