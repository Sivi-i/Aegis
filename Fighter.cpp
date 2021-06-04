#include "Fighter.h"
void Fighter::tookDamage(int dmg) {
	this->hp = (hp - dmg);
}

int Fighter::attacking() {
	int damageDone = (rand() % attack + (attack * 1.2) + (speed*1.4));
	return damageDone;
}

std::vector<int> Fighter::specialAttack() {
	std::vector<int> comboDamage;

	int damageDone = rand() % attack + (attack+(speed+25));
	for (int i = 0; i < 2; i++) {
		comboDamage.push_back((damageDone * .2));
	}
	comboDamage.push_back((damageDone * 1));
	return comboDamage;
}

char* Fighter::getType() {
	return (char*)this->type;
}

std::vector<int> Fighter::getStats() {
	std::vector<int> stats;
	stats.push_back(level);
	stats.push_back(hp);
	stats.push_back(attack);
	stats.push_back(defense);
	stats.push_back(speed);
	stats.push_back(magic);

	return stats;
}

bool Fighter::isDefeated() {
	if (hp <= 0) {
		return true;
	}
	else {
		return false;
	}
	return false;
}

int Fighter::getHP() {
	return this->hp;
}

int Fighter::getLevel() {
	return this->level;
}