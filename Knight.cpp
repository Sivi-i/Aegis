#include "Knight.h"

void Knight::tookDamage(int dmg) {
	this->hp = (hp - dmg);
}

int Knight::attacking() {
	int damageDone = rand() % attack * (1.1) + (defense * 1.2);
	return damageDone;
};

char* Knight::getType() {
	return (char*)this->type;
}

std::vector<int> Knight::specialAttack() {
	std::vector<int> damage;
	int damageDone = rand() % defense + (defense * 1.5);
	damage.push_back(damageDone);
	return damage;
}

std::vector<int> Knight::getStats() {
	std::vector<int> stats;
	stats.push_back(level);
	stats.push_back(hp);
	stats.push_back(attack);
	stats.push_back(defense);
	stats.push_back(speed);
	stats.push_back(magic);

	return stats;
}

bool Knight::isDefeated() {
	if (hp <= 0) {
		return true;
	}
	else {
		return false;
	}
	return false;
}

int Knight::getHP() {
	return this->hp;
}

int Knight::getLevel() {
	return this->level;
}