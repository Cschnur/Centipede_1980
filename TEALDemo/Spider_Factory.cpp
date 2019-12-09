#include "Spider_Factory.h"
#include "Game Components\TEAL\CommonElements.h"
#include "Spider.h"
#include "MushroomManager.h"
#include "Critter_Manager.h"
#include "Score_Manager.h"
#include "SpiderScore_Factory.h"

Spider_Factory* Spider_Factory::ptrInstance = NULL;

Spider_Factory::Spider_Factory()
{
	pDeathNear = Score_Manager::GetScoreCommand(Score_Manager::ScoreDistanceEvents::SpiderKilledNear);
	pDeathMedium = Score_Manager::GetScoreCommand(Score_Manager::ScoreDistanceEvents::SpiderKilledMed);
	pDeathFar = Score_Manager::GetScoreCommand(Score_Manager::ScoreDistanceEvents::SpiderKilledFar);
}

Spider* Spider_Factory::privCreateSpider(int ispeed)
{
	Spider* s;

	if (recycledItems.empty())
	{

		s = new Spider();
		s->SetExternalManagement(RecycleSpider);
	}
	else
	{
		s = recycledItems.top();
		recycledItems.pop();


		s->RegisterToCurrentScene();
	}

	s->Initialize(ispeed);
	return s;
}

void Spider_Factory::privRecycleSpider(GameObject* s)
{
	recycledItems.push((Spider*)s);
}

void Spider_Factory::ReportSpiderDeath(int dist, sf::Vector2i pos)
{
	if (dist > 99)
	{
		Score_Manager::SendScoreDistanceCmd(Instance().pDeathFar);
		ConsoleMsg::WriteLine("Spider Death: 300");
		SpiderScore_Factory::CreateSpiderScore(pos, THREE_HUNDRED);
	}
	else if (dist > 48)
	{
		Score_Manager::SendScoreDistanceCmd(Instance().pDeathMedium);
		ConsoleMsg::WriteLine("Spider Death: 600");
		SpiderScore_Factory::CreateSpiderScore(pos, SIX_HUNDRED);
	}
	else
	{
		Score_Manager::SendScoreDistanceCmd(Instance().pDeathNear);
		ConsoleMsg::WriteLine("Spider Death: 900");
		SpiderScore_Factory::CreateSpiderScore(pos, NINE_HUNDRED);
	}
}

void Spider_Factory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}


Spider_Factory::~Spider_Factory()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
	ConsoleMsg::WriteLine("Spider delete");
}
