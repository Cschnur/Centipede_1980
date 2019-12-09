#ifndef _CENTIPEDE_1PLAYER
#define _CENTIPEDE_1PLAYER

#include "Game Components\TEAL\CommonElements.h"
#include "PlayerShip.h"

const int SCENE_1PLAYER = 1;

class MushroomManager;

class Centipede_1Player : public Scene
{
public:
	virtual void Initialize();

	virtual void Terminate();
private:
	MushroomManager *test;
};

#endif

