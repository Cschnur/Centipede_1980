#include "Scorpion_Factory.h"
#include "Game Components\TEAL\CommonElements.h"
#include "Scorpion.h"
#include "MushroomManager.h"
#include "Critter_Manager.h"
#include "Score_Manager.h"

Scorpion_Factory* Scorpion_Factory::ptrInstance = NULL;

Scorpion_Factory::Scorpion_Factory()
{
	pDeath = Score_Manager::GetScoreCommand(Score_Manager::ScoreEvents::ScorpionKilled);

}

Scorpion* Scorpion_Factory::privCreateScorpion(int ispeed)
{
	Scorpion* s;

	if (recycledItems.empty())
	{

		s = new Scorpion();
		s->SetExternalManagement(RecycleScorpion);
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

void Scorpion_Factory::privRecycleScorpion(GameObject* s)
{
	recycledItems.push((Scorpion*)s);
}

void Scorpion_Factory::ReportScorpionDeath()
{
	ConsoleMsg::WriteLine("Scorpion Factory: Sending death score command");
	Score_Manager::SendScoreCmd(Instance().pDeath);
}

void Scorpion_Factory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}


Scorpion_Factory::~Scorpion_Factory()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
	ConsoleMsg::WriteLine("Scorpion delete");
}
