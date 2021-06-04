#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>

class Player {

	friend class EnemyDirector;

public:

	Player();

	~Player();

	int normAttack();

	int specialAttack();

	void guard(bool guarding);

	void speedUp();

	void heal();

	void tookDamage(int damage);

	int hasPoints();

	void expGained(int exp);

	std::vector<int> getStats();

	void revivePlayer();

	bool isDefeated();

	int getHP();

protected:
	int level;
	int hp;
	int attack;
	int defense;
	int speed;
	int magic;

	bool isGuarding;
	int experience;
	size_t statPoints;
};

#endif 