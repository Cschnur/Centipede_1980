#ifndef _MUSHROOM_FACTORY
#define _MUSHROOM_FACTORY

#include <stack>
#include "Game Components\TEAL\CommonElements.h"
#include "Mushroom.h"

class MushroomManager;
class CmdScore;

class Mushroom_Factory
{
public:
	static Mushroom* CreateMushroom(sf::Vector2i start) {return Instance().privCreateMushroom(start); };
	static void RecycleMushroom(GameObject* m) { Instance().privRecycleMushroom(m); };

	static void ReportRegularDeath();
	static void ReportPoisonDeath();
	static void ReportRegen();

	static void Terminate();

private:
	static Mushroom_Factory* ptrInstance;

	Mushroom_Factory();
	Mushroom_Factory(const Mushroom_Factory&) = delete;
	Mushroom_Factory& operator=(const Mushroom_Factory&) = delete;
	~Mushroom_Factory();

	static Mushroom_Factory& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new Mushroom_Factory;
		return *ptrInstance;
	};

	CmdScore* pRegularShroomDeath;
	CmdScore* pPoisonShroomDeath;
	CmdScore* pRegen;

	std::stack<Mushroom*> recycledItems;

	Mushroom* privCreateMushroom(sf::Vector2i start);
	void privRecycleMushroom(GameObject* m);
};

#endif

