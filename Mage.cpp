#include "Mage.h"

void Mage::tookDamage(int dmg) {
	this->hp = (hp - dmg);
}

int Mage::attacking() {
	int damageDone = rand() % magic + (magic * 1.3);
	return damageDone;
};

char* Mage::getType() {
	return (char*)this->type;
}

std::vector<int> Mage::specialAttack() {
	std::vector<int> damage;
	int damageDone = rand() % magic + (magic+(magic*1.5));
	damage.push_back(damageDone);
	return damage;
}

std::vector<int> Mage::getStats() {
	std::vector<int> stats;
	stats.push_back(level);
	stats.push_back(hp);
	stats.push_back(attack);
	stats.push_back(defense);
	stats.push_back(speed);
	stats.push_back(magic);

	return stats;
}

bool Mage::isDefeated() {
	if (hp <= 0) {
		return true;
	}
	else {
		return false;
	}
	return false;
}

int Mage::getHP() {
	return this->hp;
}

int Mage::getLevel() {
	return this->level;
}