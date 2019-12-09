#ifndef _CENTIPEDE_FACTORY
#define _CENTIPEDE_FACTORY
#include "Game Components\TEAL\CommonElements.h"

#include <stack>

class MushroomManager;
class Centipede_Head;
class Centipede_Manager;
class CmdScore;
class MoveState;
class Centipede_Body;

class Centipede_Factory
{
public:
	static Centipede_Head* CreateCentipede_Head(sf::Vector2i start, const MoveState* state, Centipede_Body *next, int length, float rot, int ispeed) { return Instance().privCreateCentipede_Head(start, state, next, length, rot, ispeed); };
	static void RecycleCentipede_Head(GameObject* c) { Instance().privRecycleCentipede_Head(c); };

	static Centipede_Body* CreateCentipede_Body(sf::Vector2i start, Centipede_Body* prevSeg, bool first, int ispeed) {return Instance().privCreateCentipede_Body(start, prevSeg, first, ispeed); };
	static void RecycleCentipede_Body(GameObject* b) { Instance().privRecycleCentipede_Body(b); };

	static void ReportCentipedeHeadDeath();
	static void ReportCentipedeBodyDeath();

	static void Terminate();

private:
	static Centipede_Factory* ptrInstance;

	CmdScore* pHeadDeath;
	CmdScore* pBodyDeath;
	Centipede_Factory();

	//Centipede_Factory() = default;
	Centipede_Factory(const Centipede_Factory&) = delete;
	Centipede_Factory& operator=(const Centipede_Factory&) = delete;
	~Centipede_Factory();

	static Centipede_Factory& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new Centipede_Factory;
		return *ptrInstance;
	};

	std::stack<Centipede_Head*> recycledHeads;
	std::stack<Centipede_Body*> recycledBodies;

	Centipede_Head* privCreateCentipede_Head(sf::Vector2i start, const MoveState* state, Centipede_Body *next, int length, float rot, int ispeed);
	void privRecycleCentipede_Head(GameObject* c);

	Centipede_Body* privCreateCentipede_Body(sf::Vector2i start, Centipede_Body* prevSeg, bool first, int ispeed);
	void privRecycleCentipede_Body(GameObject* b);
};

#endif

