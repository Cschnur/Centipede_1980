#ifndef _SCORPION_FACTORY
#define _SCORPION_FACTORY

#include <stack>
#include "Game Components\TEAL\CommonElements.h"
#include "Scorpion.h"

class MushroomManager;
class Critter_Manager;
class CmdScore;

class Scorpion_Factory
{
public:
	static Scorpion* CreateScorpion(int ispeed) { return Instance().privCreateScorpion(ispeed); };
	static void RecycleScorpion(GameObject* s) { Instance().privRecycleScorpion(s); };

	static void ReportScorpionDeath();

	static void Terminate();

private:
	CmdScore* pDeath;
	Scorpion_Factory();

	static Scorpion_Factory* ptrInstance;

	//Scorpion_Factory() = default;
	Scorpion_Factory(const Scorpion_Factory&) = delete;
	Scorpion_Factory& operator=(const Scorpion_Factory&) = delete;
	~Scorpion_Factory();

	static Scorpion_Factory& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new Scorpion_Factory;
		return *ptrInstance;
	};

	std::stack<Scorpion*> recycledItems;

	Scorpion* privCreateScorpion(int ispeed);
	void privRecycleScorpion(GameObject* s);
};

#endif

