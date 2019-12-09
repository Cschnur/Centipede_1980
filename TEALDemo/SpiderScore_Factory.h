#ifndef _SPIDERSCORE_FACTORY
#define _SPIDERSCORE_FACTORY

#include <stack>
#include "Game Components\TEAL\CommonElements.h"
#include "SpiderScore.h"

class SpiderScore_Factory
{
public:
	static void CreateSpiderScore(sf::Vector2i pos, int val) { return Instance().privCreateSpiderScore(pos, val); };
	static void RecycleSpiderScore(GameObject* s) { Instance().privRecycleSpiderScore(s); };

	static void Terminate();

private:
	static SpiderScore_Factory* ptrInstance;

	SpiderScore_Factory() = default;
	SpiderScore_Factory(const SpiderScore_Factory&) = delete;
	SpiderScore_Factory& operator=(const SpiderScore_Factory&) = delete;
	~SpiderScore_Factory();

	static SpiderScore_Factory& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new SpiderScore_Factory;
		return *ptrInstance;
	};

	std::stack<SpiderScore*> recycledItems;

	void privCreateSpiderScore(sf::Vector2i pos, int val);
	void privRecycleSpiderScore(GameObject* s);
};

#endif

