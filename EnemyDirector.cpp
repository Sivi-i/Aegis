#include "EnemyDirector.h"

EnemyDirector::EnemyDirector(EnemyBuilder* builder, Player* player){
	this->builder_ = builder;
	this->player_ = player;
}

EnemyDirector::~EnemyDirector() {
	delete builder_;
}

void EnemyDirector::createPugilist() {
	enemyLevel_ = (rand() % (player_->level + 4) + (player_->level));
	builder_->setLevel(enemyLevel_);
	builder_->setAttack(player_->level * 1.3);
	builder_->setDefense(player_->level * 5);
	builder_->setHP(player_->level * 60);
	builder_->setMagic(player_->level * .8);
	builder_->setSpeed(player_->level * 2.5);
	const char* type = "Pugilist";
	builder_->setType(type);
}

void EnemyDirector::createKnight() {
	builder_->setLevel(rand() % (4) + (player_->level));
	builder_->setAttack(player_->level * .8);
	builder_->setDefense(player_->level * 7);
	builder_->setHP(player_->level * 76);
	builder_->setMagic(player_->level * .8);
	builder_->setSpeed(player_->level * 2);
	const char* type = "Knight";
	builder_->setType(type);
}

void EnemyDirector::createWarrior() {
	builder_->setLevel(rand() % (4) + (player_->level));
	builder_->setAttack(player_->level * 2.5);
	builder_->setDefense(player_->level * 5);
	builder_->setHP(player_->level * 70);
	builder_->setMagic(player_->level * .8);
	builder_->setSpeed(player_->level * 2);
	const char* type = "Warrior";
	builder_->setType(type);
}

void EnemyDirector::createMage() {
	builder_->setLevel(rand() % (4) + (player_->level));
	builder_->setAttack(player_->level * 1.1);
	builder_->setDefense(player_->level * 2);
	builder_->setHP(player_->level * 50);
	builder_->setMagic(player_->level * 2.5);
	builder_->setSpeed(player_->level * 1.5);
	const char* type = "Mage";
	builder_->setType(type);
}

void EnemyDirector::createMPugilist() {
	builder_->setLevel(rand() % player_->level + (player_->level + 1));
	builder_->setAttack(player_->level * 1.8);
	builder_->setDefense(player_->level * 15);
	builder_->setHP(player_->level * 50);
	builder_->setMagic(player_->level * .8);
	builder_->setSpeed(player_->level * 4);
	const char* type = "Master Pugilist";
	builder_->setType(type);
}

void EnemyDirector::createHKnight() {
	builder_->setLevel(rand() % player_->level + (player_->level + 1));
	builder_->setAttack(player_->level * 1.4);
	builder_->setDefense(player_->level * 4);
	builder_->setHP(player_->level * 120);
	builder_->setMagic(player_->level * .8);
	builder_->setSpeed(player_->level * 2.5);
	const char* type = "Holy Knight";
	builder_->setType(type);
}

void EnemyDirector::createBerserker() {
	builder_->setLevel(rand() % player_->level + (player_->level + 1));
	builder_->setAttack(player_->level * 4.5);
	builder_->setDefense(player_->level * 10);
	builder_->setHP(player_->level * 110);
	builder_->setMagic(player_->level * .8);
	builder_->setSpeed(player_->level * 2.8);
	const char* type = "Berserker";
	builder_->setType(type);
}

void EnemyDirector::createArchmage() {
	builder_->setLevel(rand() % player_->level + (player_->level + 1));
	builder_->setAttack(player_->level * 1.3);
	builder_->setDefense(player_->level * 10);
	builder_->setHP(player_->level * 100);
	builder_->setMagic(player_->level * 25);
	builder_->setSpeed(player_->level * 4);
	const char* type = "Archmage";
	builder_->setType(type);
}

void EnemyDirector::createPsyfighter() {
	builder_->setLevel(rand() % player_->level + (player_->level + 1));
	builder_->setAttack(player_->level * 1.65);
	builder_->setDefense(player_->level * 10);
	builder_->setHP(player_->level * 125);
	builder_->setMagic(player_->level * .8);
	builder_->setSpeed(player_->level * 5);
	const char* type = "Psyfighter";
	builder_->setType(type);
}

void EnemyDirector::createTKnight() {
	builder_->setLevel(rand() % player_->level + (player_->level + 1));
	builder_->setAttack(player_->level * 1.4);
	builder_->setDefense(player_->level * 25);
	builder_->setHP(player_->level * 150);
	builder_->setMagic(player_->level * .7);
	builder_->setSpeed(player_->level * 2);
	const char* type = "Terror Knight";
	builder_->setType(type);
}

void EnemyDirector::createDragoon() {
	builder_->setLevel(rand() % player_->level + (player_->level + 1));
	builder_->setAttack(player_->level * 6);
	builder_->setDefense(player_->level * 12);
	builder_->setHP(player_->level * 105);
	builder_->setMagic(player_->level * .8);
	builder_->setSpeed(player_->level * 3);
	const char* type = "Dragoon";
	builder_->setType(type);
}

void EnemyDirector::createSoulReaver() {
	builder_->setLevel(rand() % player_->level + (player_->level + 1));
	builder_->setAttack(player_->level * 1.3);
	builder_->setDefense(player_->level * 10);
	builder_->setHP(player_->level * 110);
	builder_->setMagic(player_->level * 30);
	builder_->setSpeed(player_->level * 4);
	const char* type = "Archmage";
	builder_->setType(type);
}