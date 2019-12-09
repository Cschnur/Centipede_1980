#include "Flea_Factory.h"
#include "Game Components\TEAL\CommonElements.h"
#include "Flea.h"
#include "MushroomManager.h"
#include "Critter_Manager.h"
#include "Score_Manager.h"

Flea_Factory* Flea_Factory::ptrInstance = NULL;

Flea_Factory::Flea_Factory()
{
	pDeath = Score_Manager::GetScoreCommand(Score_Manager::ScoreEvents::FleaKilled);
}

Flea* Flea_Factory::privCreateFlea(int ispeed)
{
	Flea* f;

	if (recycledItems.empty())
	{

		f = new Flea();
		f->SetExternalManagement(RecycleFlea);
	}
	else
	{
		f = recycledItems.top();
		recycledItems.pop();


		f->RegisterToCurrentScene();
	}

	f->Initialize(ispeed);
	return f;
}

void Flea_Factory::privRecycleFlea(GameObject* f)
{
	recycledItems.push((Flea*)f);
}

void Flea_Factory::ReportFleaDeath()
{
	ConsoleMsg::WriteLine("Flea Factory: Sending death score command");
	Score_Manager::SendScoreCmd(Instance().pDeath);
}

void Flea_Factory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}


Flea_Factory::~Flea_Factory()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
	ConsoleMsg::WriteLine("Flea delete");
}
