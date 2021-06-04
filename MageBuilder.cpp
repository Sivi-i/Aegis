#include "MageBuilder.h"

MageBuilder::MageBuilder() {
	this->mage = new Mage();
}

MageBuilder::~MageBuilder() {
	delete this->mage;
}

void MageBuilder::setLevel(int level) {
	mage->level = level;
}

void MageBuilder::setHP(int hp) {
	mage->hp = hp;
}

void MageBuilder::setAttack(int attack) {
	mage->attack = attack;
}

void MageBuilder::setDefense(int defense) {
	mage->defense = defense;
}

void MageBuilder::setSpeed(int speed) {
	mage->speed = speed;
}

void MageBuilder::setMagic(int magic) {
	mage->magic = magic;
}

void MageBuilder::setType(const char* type) {
	mage->type = type;
}

Mage* MageBuilder::getProduct() {
	return this->mage;
}

void MageBuilder::reset() {
	this->mage = new Mage();
}