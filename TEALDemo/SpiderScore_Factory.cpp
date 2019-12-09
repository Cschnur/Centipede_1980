#include "SpiderScore_Factory.h"
#include "Game Components\TEAL\CommonElements.h"
#include "Spider.h"
#include "MushroomManager.h"
#include "Critter_Manager.h"
#include "Score_Manager.h"
#include "SpiderScore.h"

SpiderScore_Factory* SpiderScore_Factory::ptrInstance = NULL;

void SpiderScore_Factory::privCreateSpiderScore(sf::Vector2i pos, int val)
{
	SpiderScore* s;

	if (recycledItems.empty())
	{

		s = new SpiderScore();
		s->SetExternalManagement(RecycleSpiderScore);
	}
	else
	{
		s = recycledItems.top();
		recycledItems.pop();


		s->RegisterToCurrentScene();
	}

	s->Initialize(pos, val);
}

void SpiderScore_Factory::privRecycleSpiderScore(GameObject* s)
{
	recycledItems.push((SpiderScore*)s);
}

void SpiderScore_Factory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}


SpiderScore_Factory::~SpiderScore_Factory()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}
