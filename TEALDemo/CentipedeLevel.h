#ifndef _CentipedeLevel
#define _CentipedeLevel

#include "Game Components\TEAL\CommonElements.h"
#include "PlayerShip.h"

class MushroomManager;

class CentipedeLevel : public Scene
{
public:
	virtual void Initialize();

	virtual void Terminate();
private:
	MushroomManager *test;
};

#endif _CentipedeLevel

