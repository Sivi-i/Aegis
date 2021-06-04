#include "WarriorBuilder.h"

WarriorBuilder::WarriorBuilder() {
	warrior = new Warrior();
}

WarriorBuilder::~WarriorBuilder() {
	delete this->warrior;
}

void WarriorBuilder::setLevel(int level) {
	warrior->level = level;
}

void WarriorBuilder::setHP(int hp) {
	warrior->hp = hp;
}

void WarriorBuilder::setAttack(int attack) {
	warrior->attack = attack;
}

void WarriorBuilder::setDefense(int defense) {
	warrior->defense = defense;
}

void WarriorBuilder::setSpeed(int speed) {
	warrior->speed = speed;
}

void WarriorBuilder::setMagic(int magic) {
	warrior->magic = magic;
}

void WarriorBuilder::setType(const char* type) {
	warrior->type = type;
}

Warrior* WarriorBuilder::getProduct() {
	return this->warrior;
}

void WarriorBuilder::reset() {
	this->warrior = new Warrior();
}