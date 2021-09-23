#include "gameStart.h"

gameStart::gameStart(void) {
	std::cout << "Game Starter Active\n";
}
/*
gameStart::~gameStart() {
	std::cout << "Game Starter Inactive\n";
}*/

void gameStart::exec() {
	gameLogic();
}

void gameStart::gameLogic() {
	Player* player = new Player();
	size_t basicEnemy = 0;
	size_t miniBoss = 0;
	size_t bossEnemy = 0;
	size_t round = 0;
	size_t winner;
	char playerInput; 
	bool isMiniBoss, isBoss, isEnemy;	//For Determining if the Player is facing a Mini Boss, an actual Boss, or a Basic Enemy. 
	isEnemy = true;
	isMiniBoss = false;
	isBoss = false;

	while (1) {

		//Create a Boss Type enemy. Only happens if two Mini Bosses have been defeated within the cycle.
		if (isBoss == true) {
			if (bossEnemy == 1) {
				isMiniBoss = false;
				isBoss = false;
				isEnemy = true;
				basicEnemy = 0;
				miniBoss = 0;
				bossEnemy = 0;
				continue;
			}
			int bossPicker = rand() % 4 + 1;
			//Starting PsyFighter
			if (bossPicker == 1) {
				FighterBuilder* fighterBuilder = new FighterBuilder();
				EnemyDirector* director = new EnemyDirector(fighterBuilder, player);
				Fighter* enemyFighter = new Fighter();
				director->createPsyfighter();
				enemyFighter = fighterBuilder->getProduct();
				if (battle(player, enemyFighter) == 0) {
					std::cout << "Continue? Y/N: ";
					std::cin >> playerInput;
					playerInput = toupper(playerInput);
					switch (playerInput) {
					case 'Y'://TODO: Get Player Name when Game Starts & Replace "Player" here w/ the Player's Name
						std::cout << "\nGood Luck Player\n";
						isEnemy = true;
						isMiniBoss = false;
						isBoss = false;
						basicEnemy = 0;
						miniBoss = 0;
						bossEnemy = 0;
						player->revivePlayer();
						break;
					case 'N':
						std::cout << "\nSayonara.\n\n";
						exit(0);
					default:
						std::cout << "\n-Please Enter a Valid Response-\n";
					}
				}
				else {
					std::cout << "\nCongrats! Want to visit the Stat Store? Y/N: \n";
					std::cin >> playerInput;
					playerInput = toupper(playerInput);
					switch (playerInput) {
					case 'Y':
						player->hasPoints();
						bossEnemy++;
						isEnemy = true;
						isBoss = false;
						isMiniBoss = false;
						basicEnemy = 0;
						break;
					case 'N':
						bossEnemy++;
						isEnemy = true;
						isBoss = false;
						isMiniBoss = false;
						basicEnemy = 0;
						std::cout << "Good Luck!\n\n";
						break;
					default:
						std::cout << "\n-Please Enter a Valid Response-\n";
					}
				}//Ending Psyfighter

				//Starting Dragoon
				if (bossPicker == 2) {
					WarriorBuilder* warriorBuilder = new WarriorBuilder();
					EnemyDirector* director = new EnemyDirector(warriorBuilder, player);
					Warrior* enemyWarrior = new Warrior();
					director->createDragoon();
					enemyWarrior = warriorBuilder->getProduct();
					if (battle(player, enemyWarrior) == 0) {
						std::cout << "Continue? Y/N: \n";
						std::cin >> playerInput;
						playerInput = toupper(playerInput);
						switch (playerInput) {
						case 'Y'://TODO: Get Player Name when Game Starts & Replace "Player" here w/ the Player's Name
							std::cout << "Good Luck Player\n";
							basicEnemy = 0;
							miniBoss = 0;
							bossEnemy = 0;
							isEnemy = true;
							isMiniBoss = false;
							isBoss = false;
							player->revivePlayer();
							break;
						case 'N':
							std::cout << "Sayonara.\n\n";
							exit(0);

						default:
							std::cout << "\n-Please Enter a Valid Response-\n";
						}
					}
					else {
						std::cout << "\nCongrats! Want to visit the Stat Store? Y/N: \n";
						std::cin >> playerInput;
						playerInput = toupper(playerInput);
						switch (playerInput) {
						case 'Y':
							player->hasPoints();
							bossEnemy++;
							isEnemy = true;
							isBoss = false;
							isMiniBoss = false;
							basicEnemy = 0;
							break;
						case 'N':
							std::cout << "Good Luck!\n\n";
							bossEnemy++;
							isEnemy = true;
							isBoss = false;
							isMiniBoss = false;
							basicEnemy = 0;
							break;

						default:
							std::cout << "\n-Please Enter a Valid Response-\n";
						}
					}//Ending Dragoon

					if (bossPicker == 3) {//Starting Soul Reaver
						MageBuilder* mageBuilder = new MageBuilder();
						EnemyDirector* director = new EnemyDirector(mageBuilder, player);
						Mage* enemyMage = new Mage();
						director->createSoulReaver();
						enemyMage = mageBuilder->getProduct();
						if (battle(player, enemyMage) == 0) {
							std::cout << "Continue? Y/N: \n";
							std::cin >> playerInput;
							playerInput = toupper(playerInput);
							switch (playerInput) {
							case 'Y'://TODO: Get Player Name when Game Starts & Replace "Player" here w/ the Player's Name
								std::cout << "Good Luck Player\n";
								basicEnemy = 0;
								isEnemy = true;
								isMiniBoss = false;
								isBoss = false;
								player->revivePlayer();
								break;
							case 'N':
								std::cout << "Sayonara.\n\n";
								exit(0);

							default:
								std::cout << "\n-Please Enter a Valid Response-\n";
							}
						}
						else {
							std::cout << "\nCongrats! Want to visit the Stat Store? Y/N: \n";
							std::cin >> playerInput;
							playerInput = toupper(playerInput);
							switch (playerInput) {
							case 'Y':
								player->hasPoints();
								bossEnemy++;
								isEnemy = true;
								isBoss = false;
								isMiniBoss = false;
								basicEnemy = 0;
								break;
							case 'N':
								bossEnemy++;
								isEnemy = true;
								isBoss = false;
								isMiniBoss = false;
								basicEnemy = 0;
								std::cout << "Good Luck!\n\n";
								break;
							default:
								std::cout << "\n-Please Enter a Valid Response-\n";
							}
						}//Ending Soul Reaver

						//Starting Terror Knight
						if (bossPicker == 4) {
							bossEnemy++;
							KnightBuilder* knightBuilder = new KnightBuilder();
							EnemyDirector* director = new EnemyDirector(knightBuilder, player);
							Knight* enemyKnight = new Knight();
							director->createTKnight();
							enemyKnight = knightBuilder->getProduct();
							if (battle(player, enemyKnight) == 0) {
								std::cout << "Continue? Y/N: \n";
								std::cin >> playerInput;
								playerInput = toupper(playerInput);
								switch (playerInput) {
								case 'Y'://TODO: Get Player Name when Game Starts & Replace "Player" here w/ the Player's Name
									std::cout << "Good Luck Player\n";
									basicEnemy = 0;
									isEnemy = true;
									isMiniBoss = false;
									isBoss = false;
									player->revivePlayer();
									break;
								case 'N':
									std::cout << "Sayonara.\n\n";
									exit(0);

								default:
									std::cout << "\n-Please Enter a Valid Response-\n";
								}
							}
							else {
								std::cout << "\nCongrats! Want to visit the Stat Store? Y/N: ";
								std::cin >> playerInput;
								playerInput = toupper(playerInput);
								switch (playerInput) {
								case 'Y':
									player->hasPoints();
									bossEnemy++;
									isEnemy = true;
									isBoss = false;
									isMiniBoss = false;
									basicEnemy = 0;
									break;
								case 'N':
									bossEnemy++;
									isEnemy = true;
									isBoss = false;
									isMiniBoss = false;
									basicEnemy = 0;
									std::cout << "Good Luck!\n\n";
									break;

								default:
									std::cout << "\n-Please Enter a Valid Response-\n";
								}
							}
						}
					}
				}
			}
		}

		/*
		* Creates a Mini Boss which the Player will fight. If the Player defeats 2 Mini Bosses, they'll face a Boss type next.
		*/
		if (isMiniBoss == true) {
			if (miniBoss == 2) {
				isEnemy = false;
				isMiniBoss = false;
				isBoss = true;
				continue;
			}
			int miniPicker = rand() % 4 + 1;
			//Starting Master Pugilist
			if (miniPicker == 1) {
				FighterBuilder* fighterBuilder = new FighterBuilder();
				EnemyDirector* director = new EnemyDirector(fighterBuilder, player);
				Fighter* enemyFighter = new Fighter();
				director->createMPugilist();
				enemyFighter = fighterBuilder->getProduct();
				if (battle(player, enemyFighter) == 0) {
					std::cout << "Continue? Y/N: ";
					std::cin >> playerInput;
					playerInput = toupper(playerInput);
					switch (playerInput) {
					case 'Y'://TODO: Get Player Name when Game Starts & Replace "Player" here w/ the Player's Name
						std::cout << "\nGood Luck Player\n";
						isEnemy = true;
						isMiniBoss = false;
						isBoss = false;
						basicEnemy = 0;
						miniBoss = 0;
						bossEnemy = 0;
						player->revivePlayer();
						break;
					case 'N':
						std::cout << "\nSayonara.\n\n";
						exit(0);

					default:
						std::cout << "\n-Please Enter a Valid Response-\n";
					}
				}
				else {
					std::cout << "\nCongrats! Want to visit the Stat Store? Y/N: \n";
					std::cin >> playerInput;
					playerInput = toupper(playerInput);
					switch (playerInput) {
					case 'Y':
						basicEnemy = 0;
						miniBoss++;
						isMiniBoss = false;
						isEnemy = true;
						player->hasPoints();
						break;
					case 'N':
						std::cout << "Good Luck!\n\n";
						miniBoss++;
						basicEnemy = 0;
						isMiniBoss = false;
						isEnemy = true;
						break;
					default:
						std::cout << "\n-Please Enter a Valid Response-\n";
					}
				}//Ending Master Pugilist

				//Starting Berserker
				if (miniPicker == 2) {
					WarriorBuilder* warriorBuilder = new WarriorBuilder();
					EnemyDirector* director = new EnemyDirector(warriorBuilder, player);
					Warrior* enemyWarrior = new Warrior();
					director->createBerserker();
					enemyWarrior = warriorBuilder->getProduct();
					if (battle(player, enemyWarrior) == 0) {
						std::cout << "Continue? Y/N: \n";
						std::cin >> playerInput;
						playerInput = toupper(playerInput);
						switch (playerInput) {
						case 'Y'://TODO: Get Player Name when Game Starts & Replace "Player" here w/ the Player's Name
							std::cout << "Good Luck Player\n";
							isEnemy = true;
							isMiniBoss = false;
							isBoss = false;
							basicEnemy = 0;
							miniBoss = 0;
							bossEnemy = 0;
							player->revivePlayer();
							break;
						case 'N':
							std::cout << "Sayonara.\n\n";
							exit(0);
						default:
							std::cout << "\n-Please Enter a Valid Response-\n";
						}
					}
					else {
						std::cout << "\nCongrats! Want to visit the Stat Store? Y/N: \n";
						std::cin >> playerInput;
						playerInput = toupper(playerInput);
						switch (playerInput) {
						case 'Y':
							player->hasPoints();
							miniBoss++;
							basicEnemy = 0;
							isMiniBoss = false;
							isEnemy = true;
							break;
						case 'N':
							miniBoss++;
							basicEnemy = 0;
							isMiniBoss = false;
							isEnemy = true;
							std::cout << "Good Luck!\n\n";
							break;
						default:
							std::cout << "Please Enter a Valid Response\n";
						}
					}//Ending Berserker

					if (miniPicker == 3) {//Starting Archmage
						MageBuilder* mageBuilder = new MageBuilder();
						EnemyDirector* director = new EnemyDirector(mageBuilder, player);
						Mage* enemyMage = new Mage();
						director->createArchmage();
						enemyMage = mageBuilder->getProduct();
						if (battle(player, enemyMage) == 0) {
							std::cout << "Continue? Y/N: \n";
							std::cin >> playerInput;
							playerInput = toupper(playerInput);
							switch (playerInput) {
							case 'Y'://TODO: Get Player Name when Game Starts & Replace "Player" here w/ the Player's Name
								std::cout << "Good Luck Player\n";
								isEnemy = true;
								isMiniBoss = false;
								isBoss = false;
								basicEnemy = 0;
								miniBoss = 0;
								bossEnemy = 0;
								player->revivePlayer();
								break;
							case 'N':
								std::cout << "Sayonara.\n\n";
								exit(0);
							default:
								std::cout << "\n-Please Enter a Valid Response-\n";
							}
						}
						else {
							std::cout << "\nCongrats! Want to visit the Stat Store? Y/N: \n";
							std::cin >> playerInput;
							playerInput = toupper(playerInput);
							switch (playerInput) {
							case 'Y':
								player->hasPoints();
								miniBoss++;
								basicEnemy = 0;
								isMiniBoss = false;
								isEnemy = true;
								break;
							case 'N':
								miniBoss++;
								basicEnemy = 0;
								isMiniBoss = false;
								isEnemy = true;
								std::cout << "Good Luck!\n\n";
								break;
							default:
								std::cout << "\n-Please Enter a Valid Response-\n";
							}
						}//Ending Archmage
					}

					//Beginning Holy Knight
					if (miniPicker == 4) {
						KnightBuilder* knightBuilder = new KnightBuilder();
						EnemyDirector* director = new EnemyDirector(knightBuilder, player);
						Knight* enemyKnight = new Knight();
						director->createHKnight();
						enemyKnight = knightBuilder->getProduct();
						if (battle(player, enemyKnight) == 0) {
							std::cout << "Continue? Y/N: \n";
							std::cin >> playerInput;
							playerInput = toupper(playerInput);
							switch (playerInput) {
							case 'Y'://TODO: Get Player Name when Game Starts & Replace "Player" here w/ the Player's Name
								std::cout << "Good Luck Player\n";
								isEnemy = true;
								isMiniBoss = false;
								isBoss = false;
								basicEnemy = 0;
								miniBoss = 0;
								bossEnemy = 0;
								player->revivePlayer();
								break;
							case 'N':
								std::cout << "Sayonara.\n\n";
								exit(0);
							default:
								std::cout << "\n-Please Enter a Valid Response-\n";
							}
						}
						else {
							std::cout << "\nCongrats! Want to visit the Stat Store? Y/N: ";
							std::cin >> playerInput;
							playerInput = toupper(playerInput);
							switch (playerInput) {
							case 'Y':
								player->hasPoints();
								miniBoss++;
								basicEnemy = 0;
								isMiniBoss = false;
								isEnemy = true;
								break;
							case 'N':
								miniBoss++;
								basicEnemy = 0;
								isMiniBoss = false;
								isEnemy = true;
								std::cout << "Good Luck!\n\n";
								break;
							default:
								std::cout << "\n-Please Enter a Valid Response-\n";
							}
						}
					}
				}
			}
		}

		/*
		*Creates a Basic Enemy of a Random type which the Player battles. If the Player defeats 4 enemies in a row, they will face a Mini Boss.
		*/
		if (isEnemy == true) {
			if (basicEnemy == 4) {
				isEnemy = false;
				isMiniBoss = true;
				continue;
			}
			int enemyPicker = rand() % 4 + 1;

			if (enemyPicker == 1) {
				FighterBuilder* fighterBuilder = new FighterBuilder();
				EnemyDirector* director = new EnemyDirector(fighterBuilder, player);
				Fighter* enemyFighter = new Fighter();
				director->createPugilist();
				enemyFighter = fighterBuilder->getProduct();
				if (battle(player, enemyFighter) == 0) {
					std::cout << "Continue? Y/N: ";
					std::cin >> playerInput;
					playerInput = toupper(playerInput);
					switch (playerInput) {
					case 'Y'://TODO: Get Player Name when Game Starts & Replace "Player" here w/ the Player's Name
						std::cout << "\nGood Luck Player\n";
						basicEnemy = 0;
						isEnemy = true;
						isMiniBoss = false;
						isBoss = false;
						player->revivePlayer();
						break;
					case 'N':
						std::cout << "\nSayonara.\n\n";
						exit(0);
					default:
						std::cout << "\n-Please Enter a Valid Response-\n";
					}
				}
				else {
					std::cout << "\nCongrats! Want to visit the Stat Store? Y/N: \n";
					std::cin >> playerInput;
					playerInput = toupper(playerInput);
					switch (playerInput) {
					case 'Y':
						player->hasPoints();
						basicEnemy++;
						break;
					case 'N':
						std::cout << "Good Luck!\n\n";
						basicEnemy++;
						break;
					default:
						std::cout << "\n-Please Enter a Valid Response-\n";
					}
				}
			}
			if (enemyPicker == 2) {
				WarriorBuilder* warriorBuilder = new WarriorBuilder();
				EnemyDirector* director = new EnemyDirector(warriorBuilder, player);
				Warrior* enemyWarrior = new Warrior();
				director->createWarrior();
				enemyWarrior = warriorBuilder->getProduct();
				if (battle(player, enemyWarrior) == 0) {
					std::cout << "Continue? Y/N: \n";
					std::cin >> playerInput;
					playerInput = toupper(playerInput);
					switch (playerInput) {
					case 'Y'://TODO: Get Player Name when Game Starts & Replace "Player" here w/ the Player's Name
						std::cout << "Good Luck Player\n";
						basicEnemy = 0;
						isEnemy = true;
						isMiniBoss = false;
						isBoss = false;
						player->revivePlayer();
						break;
					case 'N':
						std::cout << "Sayonara.\n\n";
						exit(0);

					default:
						std::cout << "\n-Please Enter a Valid Response-\n";

					}
				}
				else {
					std::cout << "\nCongrats! Want to visit the Stat Store? Y/N: \n";
					std::cin >> playerInput;
					playerInput = toupper(playerInput);
					switch (playerInput) {
					case 'Y':
						player->hasPoints();
						basicEnemy++;
						break;
					case 'N':
						basicEnemy++;
						std::cout << "Good Luck!\n\n";
						break;
					default:
						std::cout << "\n-Please Enter a Valid Response-\n";

					}


				}
			}
			if (enemyPicker == 3) {
				MageBuilder* mageBuilder = new MageBuilder();
				EnemyDirector* director = new EnemyDirector(mageBuilder, player);
				Mage* enemyMage = new Mage();
				director->createMage();
				enemyMage = mageBuilder->getProduct();
				if (battle(player, enemyMage) == 0) {
					std::cout << "Continue? Y/N: \n";
					std::cin >> playerInput;
					playerInput = toupper(playerInput);
					switch (playerInput) {
					case 'Y'://TODO: Get Player Name when Game Starts & Replace "Player" here w/ the Player's Name
						std::cout << "Good Luck Player\n";
						basicEnemy = 0;
						isEnemy = true;
						isMiniBoss = false;
						isBoss = false;
						player->revivePlayer();
						break;
					case 'N':
						std::cout << "Sayonara.\n\n";
						exit(0);

					default:
						std::cout << "\n-Please Enter a Valid Response-\n";
					}
				}
				else {
					std::cout << "\nCongrats! Want to visit the Stat Store? Y/N: \n";
					std::cin >> playerInput;
					playerInput = toupper(playerInput);
					switch (playerInput) {
					case 'Y':
						player->hasPoints();
						basicEnemy++;
						break;
					case 'N':
						basicEnemy++;
						std::cout << "Good Luck!\n\n";
						break;
					default:
						std::cout << "\n-Please Enter a Valid Response-\n";
					}
				}
			}
			if (enemyPicker == 4) {
				KnightBuilder* knightBuilder = new KnightBuilder();
				EnemyDirector* director = new EnemyDirector(knightBuilder, player);
				Knight* enemyKnight = new Knight();
				director->createKnight();
				enemyKnight = knightBuilder->getProduct();
				if (battle(player, enemyKnight) == 0) {
					std::cout << "Continue? Y/N: \n";
					std::cin >> playerInput;
					playerInput = toupper(playerInput);
					switch (playerInput) {
					case 'Y'://TODO: Get Player Name when Game Starts & Replace "Player" here w/ the Player's Name
						std::cout << "Good Luck Player\n";
						basicEnemy = 0;
						isEnemy = true;
						isMiniBoss = false;
						isBoss = false;
						player->revivePlayer();
						break;
					case 'N':
						std::cout << "Sayonara.\n\n";
						exit(0);

					default:
						std::cout << "\n-Please Enter a Valid Response-\n";
					}
				}
				else {
					std::cout << "\n! Want to visit the Stat Store? Y/N: \n";
					std::cin >> playerInput;
					playerInput = toupper(playerInput);
					switch (playerInput) {
					case 'Y':
						player->hasPoints();
						basicEnemy++;
						break;
					case 'N':
						basicEnemy++;
						std::cout << "Good Luck!\n\n";
						break;
					default:
						std::cout << "\n-Please Enter a Valid Response-\n";
					}
				}
			}
		}
	}
}











size_t gameStart::battle(Player* player, Enemy* enemy) {
	const char* enemyType = enemy->getType();
	std::vector<int> playerStats = player->getStats();
	std::vector<int> enemyStats = enemy->getStats();
	char playerInput;
	bool inBattle = true;
	int battleRound, enemyAttack; //battleRound keeps track of whose turn it is. enemyAttack determines the enemy's type of attack used.
	double enemySpecial = 0, playerSpecial = 0; //Determines the amount of Special Attacks the Player and Enemy have at a particular moment
	bool enemyReady, playerReady; //Determines if the User or Enemy can use their Special Attacks

	std::cout << "\nNew Combatant! " << enemyType << "\n";
	if (playerStats.at(4) > enemyStats.at(4)) {
		std::cout << "Player Attacks First!\n";
		std::cout << "Player Lvl: " << playerStats.at(0) << "\n\n";
		std::cout << "Enemy Lvl: " << enemyStats.at(0) << "\n\n";

		battleRound = 0;
	}
	else {
		std::cout << "Enemy Attacks First!\n";
		std::cout << "Player Lvl: " << playerStats.at(0) << "\n\n";
		std::cout << "Enemy Lvl: " << enemyStats.at(0) << "\n\n";
		battleRound = 1;
	}

	while (inBattle) {
		if (player->isDefeated()) {
			std::cout << "You've Been Defeated\n\n";
			inBattle = false;
			return 0;
		}
		else if (enemy->isDefeated()) {
			std::cout << "Enemy Defeated!\n\n";
			if (enemyType == (std::string)"Mage" || enemyType == (std::string)"Warrior" || enemyType == (std::string)"Pugilist" || enemyType == (std::string)"Knight") {
				int expGained = ((enemy->getLevel()) * 25);
				player->expGained(expGained);
				inBattle = false;
			}
			else if (enemyType == (std::string)"Berserker" || enemyType == (std::string)"Archmage" || enemyType == (std::string)"Master Pugilist" || enemyType == (std::string)"Holy Knight") {
				int expGained = (enemy->getLevel() * 60);
				player->expGained(expGained);
				inBattle = false;
			}
			else if (enemyType == (std::string)"Dragoon" || enemyType == (std::string)"Psyfighter" || enemyType == (std::string)"Terror Knight" || enemyType == (std::string)"Soul Reaver") {
				int expGained = (enemy->getLevel() * 100);
				player->expGained(expGained);
				inBattle = false;
			}


			return 1;
		}
		else {
			if (battleRound == 0) {
				std::cout << "\nChoose Your Move:\n";
				std::cout << "A.) Attack\n";
				std::cout << "S.) Speed Up\n";
				std::cout << "D.) Defend\n";
				std::cout << "F.) Special Attack\n";
				std::cout << "E.) Heal\n";
				std::cout << "Current HP: " << player->getHP() << "\n";
				std::cout << "Enemy HP: " << enemy->getHP() << "\n\n";
				std::cin.clear();
				std::cin >> playerInput;
				playerInput = toupper(playerInput);

				if (enemySpecial >= 1) {
					enemyReady = true;
				}
				else {
					enemyReady = false;
				}

				if (playerSpecial >= 1) {
					playerReady = true;
					std::cout << "Special Attack Ready~\n\n";
				}
				else {
					playerReady = false;
				}

				switch (playerInput) {
				case 'A':
				{
					int normDamage = player->normAttack();
					std::cout << "===---------------------------------------------------------===\n";
					std::cout << "Attacked " << enemyType << " for " << normDamage << " Damage!\n";
					std::cout << "===---------------------------------------------------------===\n";
					enemy->tookDamage(normDamage);
					playerSpecial += .5;
					battleRound = 1;
					break;
				}
				case 'S':

				case 'D':
				{
					player->guard(true);
					std::cout << "===---------------------------------------------------------===\n";
					std::cout << "Bracing for the next Attack!\n";
					std::cout << "===---------------------------------------------------------===\n";
					playerSpecial += .5;
					battleRound = 1;
					break;
				}
				case 'F':
				{
					if (playerReady) {
						int damageDone = player->specialAttack();
						std::cout << "===---------------------------------------------------------===\n";
						std::cout << "Blitz hit " << enemyType << " for " << damageDone << " Damage!\n";
						std::cout << "===---------------------------------------------------------===\n";
						enemy->tookDamage(damageDone);
						playerSpecial -= 1;
						battleRound = 1;
						break;
					}
					else {
						std::cout << "Player Special Not Ready! \n";
						break;
					}
				}
				case 'E':
				{
					player->heal();
					battleRound = 1;
					break;
				}
				default:
					std::cout << "\n-Please Enter a Valid Response-\n";
					break;
				}
			}
			else {
				enemyAttack = rand() % 2 + 1;
				if (enemyAttack == 1) {

					int enemyDamage = enemy->attacking();
					std::cout << "===---------------------------------------------------------===\n";
					std::cout << enemyType << " uses Normal Attack! Deals " << enemyDamage << " Damage!\n";
					std::cout << "===---------------------------------------------------------===\n";
					player->tookDamage(enemyDamage);
					enemySpecial += .5;
					player->guard(false);
					battleRound = 0;

				}
				if (enemyAttack == 2) {
					std::vector<int> enemyDamage = enemy->specialAttack();
					std::cout << "===---------------------------------------------------------===\n";
					std::cout << enemyType << " Uses Special Attack!\n";
					for (int i = 0; i < enemyDamage.size(); i++) {
						std::cout << "Dealt " << enemyDamage.at(i) << " Damage!\n";
						player->tookDamage(enemyDamage.at(i));
					}
					enemySpecial -= 1;
					player->guard(false);
					battleRound = 0;
					std::cout << "===---------------------------------------------------------===\n";

				}

			}
		}
	}
	return 0;
}

size_t gameStart::playerAttributes() {
	return 0;
}

