#ifndef _FLEA_FACTORY
#define _FLEA_FACTORY

#include <stack>
#include "Game Components\TEAL\CommonElements.h"

class MushroomManager;
class Flea;
class Critter_Manager;
class CmdScore;

class Flea_Factory
{
public:
	static Flea* CreateFlea(int ispeed) { return Instance().privCreateFlea(ispeed); };
	static void RecycleFlea(GameObject* f) { Instance().privRecycleFlea(f); };

	static void ReportFleaDeath();

	static void Terminate();

private:
	static Flea_Factory* ptrInstance;

	CmdScore* pDeath;
	Flea_Factory();

	//Flea_Factory() = default;
	Flea_Factory(const Flea_Factory&) = delete;
	Flea_Factory& operator=(const Flea_Factory&) = delete;
	~Flea_Factory();

	static Flea_Factory& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new Flea_Factory;
		return *ptrInstance;
	};

	std::stack<Flea*> recycledItems;

	Flea* privCreateFlea(int ispeed);
	void privRecycleFlea(GameObject* f);
};

#endif

