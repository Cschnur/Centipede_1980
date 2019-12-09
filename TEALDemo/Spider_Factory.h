#ifndef _SPIDER_FACTORY
#define _SPIDER_FACTORY

#include <stack>
#include "Game Components\TEAL\CommonElements.h"
#include "Spider.h"

class MushroomManager;
class Critter_Manager;
class CmdScoreByDistance;

class Spider_Factory
{
public:
	static Spider* CreateSpider(int ispeed) { return Instance().privCreateSpider(ispeed); };
	static void RecycleSpider(GameObject* s) { Instance().privRecycleSpider(s); };

	static void ReportSpiderDeath(int dist, sf::Vector2i pos);

	static void Terminate();

private:
	static Spider_Factory* ptrInstance;

	static const int THREE_HUNDRED = 0;
	static const int SIX_HUNDRED = 1;
	static const int NINE_HUNDRED = 2;

	CmdScoreByDistance* pDeathNear;
	CmdScoreByDistance* pDeathMedium;
	CmdScoreByDistance* pDeathFar;

	Spider_Factory();

	//Spider_Factory() = default;
	Spider_Factory(const Spider_Factory&) = delete;
	Spider_Factory& operator=(const Spider_Factory&) = delete;
	~Spider_Factory();

	static Spider_Factory& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new Spider_Factory;
		return *ptrInstance;
	};

	std::stack<Spider*> recycledItems;

	Spider* privCreateSpider(int ispeed);
	void privRecycleSpider(GameObject* s);
};

#endif

