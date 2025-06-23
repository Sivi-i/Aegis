#include "Player.h"

Player::Player() {
	this->level = 1;
	this->hp = (level*100 + defense*2);
	this->attack = 15;
	this->defense = 10;
	this->speed = 10;
	this->magic = 5;
	this->statPoints = 0;
	this->experience = 0;
}

Player::~Player() {
	std::cout << "Player has been deleted\n\n";
}

int Player::normAttack() {
	int damageDone = rand() % attack + ((attack) * 1.3);
	return damageDone;
}

int Player::specialAttack() {
	int damageDone = rand() % attack + ((attack + speed + magic)+(int)(speed*1.5));
	return damageDone;
}

void Player::guard(bool guarding) {
	if (guarding == true) {
		isGuarding = true;
	}
	else {
		isGuarding = false;
	}
}

void Player::speedUp() {

}

void Player::heal() {
	if(magic <= 50){
	std::cout << "===---------------------------------------------------------===\n";
	std::cout << "Healed " << (int)(magic * 2.5) << " HP!\n";
	std::cout << "===---------------------------------------------------------===\n";
	this->hp += (magic * 3.5);
	}
	else if (magic >= 50 && magic <= 100) {
		std::cout << "===---------------------------------------------------------===\n";
		std::cout << "Healed " << (int)(magic * 1.8) << " HP!\n";
		std::cout << "===---------------------------------------------------------===\n";
		this->hp += (magic * 2.5);
	}
	else if (magic >= 101 && magic <= 1000) {
		std::cout << "===---------------------------------------------------------===\n";
		std::cout << "Healed " << (int)(magic * 1.4) << " HP!\n";
		std::cout << "===---------------------------------------------------------===\n";
		this->hp += (magic * 2);
	}
}

void Player::tookDamage(int damage) {
	int tempHP = this->hp;
	int playerDmg = (damage - (this->defense)*1.3);


	switch (isGuarding)
	{
		case true:
			if (playerDmg <= 0) {
				std::cout << "===---------------------------------------------------------===\n";
				std::cout << "Player Took No Damage!\n";
				std::cout << "===---------------------------------------------------------===\n";
			}
			else {
				this->hp -= playerDmg;
				std::cout << "===---------------------------------------------------------===\n";
				std::cout << "Player Guarded " << (damage-playerDmg) << " Damage! Took " << playerDmg << " Damage!\n";
				std::cout << "===---------------------------------------------------------===\n";
			}
			break;

		case false:
			this->hp -= damage;
			break;
	}

	/*if (isGuarding == false) {
		this->hp -= damage;
	}

	/*if (isGuarding == true) {
		if (playerDmg < 0) {
			this->hp = tempHP;
			isGuarding = false;
			
			
		}
		else {
			this->hp -= playerDmg;
			isGuarding = false;
			std::cout << "===---------------------------------------------------------===\n";
			std::cout << "Player Took " << playerDmg << " Damage!\n";
			std::cout << "===---------------------------------------------------------===\n";
			
		}
	}*/
	
	

}




int Player::hasPoints() {
	char playerStat;
	int playerIncrease = statPoints;
	bool hasPoints = false;

	if (statPoints > 0) {
		hasPoints = true;
	}
	else if (statPoints == 0) {
		std::cout << "Player has No Points\n\n";
	}
	

	while (hasPoints) {
			std::cout << "Welcome! Available Points: " << statPoints << "\n";
			std::cout << "Choose Which Stat to Increase:\n\n";
			std::cout << "A.) Attack (More Damage)\n";
			std::cout << "S.) Speed (Quicker Attack)\n";
			std::cout << "D.) Defense (Less Dmg Taken & More HP)\n";
			std::cout << "E.) Magic (More HP Healed)\n";
			std::cout << "X.) Leave Store\n";

			std::cin >> playerStat;
			playerStat = toupper(playerStat);

			switch (playerStat) {
				case 'A':
					if (playerIncrease > statPoints) {
						std::cout << "You don't have this many Skill Points!\n\n";
						continue;
					}
					else {
						std::cout << "How many Stat Points to Add into Attack?\n";
						std::cin >> playerIncrease;
						attack += playerIncrease;
						statPoints -= playerIncrease;
						break;
					}
					break;
				case 'S':
					if (playerIncrease > statPoints) {
						std::cout << "You don't have this many Skill Points!\n\n";
						continue;
					}
					else {
						std::cout << "How many Stat Points to Add into Speed?\n";
						std::cin >> playerIncrease;
						speed += playerIncrease;
						statPoints -= playerIncrease;
						break;
					}
					break;
				case 'D':
					if (playerIncrease > statPoints) {
						std::cout << "You don't have this many Skill Points!\n\n";
						continue;
					}
					else {
						std::cout << "How many Stat Points to Add into Defense?\n";
						std::cin >> playerIncrease;
						defense += playerIncrease;
						statPoints -= playerIncrease;
						break;
					}
					break;
				case 'E':
					if (playerIncrease > statPoints) {
						std::cout << "You don't have this many Skill Points!\n\n";
						this->hp += ((level * 100) + defense * 4);
						continue;
					}
					else {
						std::cout << "How many Stat Points to Add into Magic?\n";
						std::cin >> playerIncrease;
						magic += playerIncrease;
						statPoints -= playerIncrease;
						break;
					}
					break;

				case 'X':
					return 0;
				default:
					std::cout << "Please Enter a valid Answer\n";
			}
	}
	if (!(hasPoints)) {
		return 0;
	}
	return 0;
}

void Player::expGained(int exp) {
	this->experience += exp;
	this->hp = ((level * 50) + defense * 5);
	int levels = 0;
		
	if (this->experience >= 100) {
		while (this->experience >= 100) {
			this->level += 1;
			this->statPoints += 5;
			this->experience -= 100;
			this->hp *= 1.03;
			this->defense *= 1.09;
			this->speed *= 1.05;
			this->magic *= 1.1;

			levels++;
		}
		
	}

	std::cout << "\nExperience Gained: " << exp << " \n";
	if (levels >= 1) {
		std::cout << "Leveled Up!  " << levels << " Gained!\n";
	}
}

std::vector<int> Player::getStats() {
	std::vector<int> stats;
	stats.push_back(level);
	stats.push_back(hp);
	stats.push_back(attack);
	stats.push_back(defense);
	stats.push_back(speed);
	stats.push_back(magic);
	return stats;
}

void Player::revivePlayer() {
	this->hp = ((level * 50) + defense * 1.2);
}

bool Player::isDefeated() {
	if(hp <= 0){
		return true;
	}
	else {
		return false;
	}
	return false;
}



int Player::getHP() {
	return this->hp;
}
