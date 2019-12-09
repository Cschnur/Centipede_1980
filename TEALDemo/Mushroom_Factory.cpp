#include "Mushroom_Factory.h"
#include "Game Components\TEAL\CommonElements.h"
#include "Mushroom.h"
#include "MushroomManager.h"
#include "Score_Manager.h"

Mushroom_Factory* Mushroom_Factory::ptrInstance = NULL;

Mushroom_Factory::Mushroom_Factory()
{
	pRegularShroomDeath = Score_Manager::GetScoreCommand(Score_Manager::ScoreEvents::MushroomKilled);
	pPoisonShroomDeath = Score_Manager::GetScoreCommand(Score_Manager::ScoreEvents::MushroomPoisonKilled);
	pRegen = Score_Manager::GetScoreCommand(Score_Manager::ScoreEvents::MushroomRegen);
}

void Mushroom_Factory::ReportRegularDeath()
{
	Score_Manager::SendScoreCmd(Instance().pRegularShroomDeath);
}

void Mushroom_Factory::ReportPoisonDeath()
{
	Score_Manager::SendScoreCmd(Instance().pPoisonShroomDeath);
}

void Mushroom_Factory::ReportRegen()
{
	Score_Manager::SendScoreCmd(Instance().pRegen);
}

Mushroom* Mushroom_Factory::privCreateMushroom(sf::Vector2i start)
{
	Mushroom *m;

	if (recycledItems.empty())
	{

		m = new Mushroom();
		m->SetExternalManagement(RecycleMushroom);
	}
	else
	{
		m = recycledItems.top();
		recycledItems.pop();


		m->RegisterToCurrentScene();
	}

	m->Initialize(start);

	return m;
}

void Mushroom_Factory::privRecycleMushroom(GameObject* m)
{
	recycledItems.push((Mushroom*)m);
}

void Mushroom_Factory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}


Mushroom_Factory::~Mushroom_Factory()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

