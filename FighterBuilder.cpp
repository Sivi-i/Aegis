#include "FighterBuilder.h"

FighterBuilder::FighterBuilder() {
	fighter = new Fighter();
}

FighterBuilder::~FighterBuilder() {
	delete this->fighter;
}

void FighterBuilder::setLevel(int level) {
	int fighterLevel = rand() % level + (level + 2);
	fighter->level = fighterLevel;
}

void FighterBuilder::setHP(int hp) {
	fighter->hp = hp;
}

void FighterBuilder::setAttack(int attack) {
	fighter->attack = attack;
}

void FighterBuilder::setDefense(int defense) {
	fighter->defense = defense;
}

void FighterBuilder::setSpeed(int speed) {
	fighter->speed = speed;
}

void FighterBuilder::setMagic(int magic) {
	fighter->magic = magic;
}

void FighterBuilder::setType(const char* type) {
	fighter->type = type;
}

Fighter* FighterBuilder::getProduct() {
	return this->fighter;
}

void FighterBuilder::reset() {
	this->fighter = new Fighter();
}