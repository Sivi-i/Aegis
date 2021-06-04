#include "KnightBuilder.h"

KnightBuilder::KnightBuilder() {
	knight = new Knight();
}

KnightBuilder::~KnightBuilder() {
	delete this->knight;
}

void KnightBuilder::setLevel(int level){
	int knightLevel = level;
	knight->level = knightLevel;
}

void KnightBuilder::setHP(int hp) {
	knight->hp = hp;
}

void KnightBuilder::setAttack(int attack) {
	knight->attack = attack; 
}

void KnightBuilder::setDefense(int defense) {
	knight->defense = defense;
}

void KnightBuilder::setSpeed(int speed) {
	knight->speed = speed;
}

void KnightBuilder::setMagic(int magic) {
	knight->magic = magic;
}

void KnightBuilder::setType(const char* type) {
	knight->type = type;
}

Knight* KnightBuilder::getProduct() {
	return this->knight;
}

void KnightBuilder::reset() {
	this->knight = new Knight();
}