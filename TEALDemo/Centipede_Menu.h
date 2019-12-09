#ifndef _Centipede_Menu
#define _Centipede_Menu

#include "Game Components\TEAL\CommonElements.h"
#include "PlayerShip.h"

const int SCENE_MENU = 0;

class MushroomManager;

class Centipede_Menu : public Scene
{
public:
	virtual void Initialize();

	virtual void Terminate();
private:
	MushroomManager *test;
};

#endif

