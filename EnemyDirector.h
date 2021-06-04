#ifndef ENEMYDIRECTOR_H	
#define ENEMYDIRECTOR_H

#include "EnemyBuilder.h"
#include "Player.h"
#include <string>

class EnemyDirector {

public:
	EnemyDirector(EnemyBuilder* builder, Player* player);
	
	~EnemyDirector();

	void createPugilist();

	void createKnight();

	void createWarrior();

	void createMage();

	void createMPugilist();

	void createHKnight();

	void createBerserker();

	void createArchmage();

	void createPsyfighter();

	void createTKnight();

	void createDragoon();

	void createSoulReaver();

	



private:
	EnemyBuilder* builder_;

	Player* player_;

	friend class gameStart;
};

#endif 