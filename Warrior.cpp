#include "Warrior.h"

void Warrior::tookDamage(int dmg) {
	this->hp = (hp - dmg);
}

int Warrior::attacking() {
	int damageDone = rand() % attack + (int)((attack+speed)*1.3);
	return damageDone;
};

char* Warrior::getType() {
	return (char*)this->type;
}
	
std::vector<int> Warrior::specialAttack() {
	std::vector<int> damage;
	int damageDone = rand() % attack + (attack*1.4);
	damage.push_back(damageDone);
	return damage;
}

std::vector<int> Warrior::getStats() {
	std::vector<int> stats;
	stats.push_back(level);
	stats.push_back(hp);
	stats.push_back(attack);
	stats.push_back(defense);
	stats.push_back(speed);
	stats.push_back(magic);

	return stats;
}

bool Warrior::isDefeated() {
	if (hp <= 0) {
		return true;
	}
	else {
		return false;
	}
	return false;
}

int Warrior::getHP() {
	return this->hp;
}

int Warrior::getLevel() {
	return this->level;
}