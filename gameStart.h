#pragma once

#ifndef GAMESTART_H
#define GAMESTART_H

#include "FighterBuilder.h"
#include "EnemyBuilder.h"
#include "EnemyDirector.h"
#include "KnightBuilder.h"
#include "WarriorBuilder.h"
#include "MageBuilder.h"
#include <iostream>
#include <cstdlib>
//#include "Player.h"
//#include "Fighter.h"



class gameStart {

public:
	
	gameStart(void);
	
	//~gameStart(void);

 	void exec();

	void gameLogic();

	size_t battle(Player* player, Enemy* enemy);

	size_t playerAttributes();

};

#endif 