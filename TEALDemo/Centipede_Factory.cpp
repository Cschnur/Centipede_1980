#include "Centipede_Factory.h"
#include "Game Components\TEAL\CommonElements.h"
#include "Centipede_Head.h"
#include "MushroomManager.h"
#include "Score_Manager.h"
#include "MoveState.h"
#include "Centipede_Body.h"

Centipede_Factory* Centipede_Factory::ptrInstance = NULL;

Centipede_Factory::Centipede_Factory()
{
	pHeadDeath = Score_Manager::GetScoreCommand(Score_Manager::ScoreEvents::CentipedeHeadKilled);
	pBodyDeath = Score_Manager::GetScoreCommand(Score_Manager::ScoreEvents::CentipedeBodyKilled);
}


Centipede_Head* Centipede_Factory::privCreateCentipede_Head(sf::Vector2i start, const MoveState* state, Centipede_Body *next, int length, float rot, int ispeed)
{
	Centipede_Head* c;

	if (recycledHeads.empty())
	{

		c = new Centipede_Head();
		c->SetExternalManagement(RecycleCentipede_Head);
	}
	else
	{
		c = recycledHeads.top();
		recycledHeads.pop();


		c->RegisterToCurrentScene();
	}

	c->Initialize(start, state, next, length, rot, ispeed);
	return c;
}

void Centipede_Factory::privRecycleCentipede_Head(GameObject* c)
{
	recycledHeads.push((Centipede_Head*)c);
}

Centipede_Body* Centipede_Factory::privCreateCentipede_Body(sf::Vector2i start, Centipede_Body* prevSeg, bool first, int ispeed)
{
	Centipede_Body* b;

	if (recycledBodies.empty())
	{

		b = new Centipede_Body();
		b->SetExternalManagement(RecycleCentipede_Body);
	}
	else
	{
		b = recycledBodies.top();
		recycledBodies.pop();


		b->RegisterToCurrentScene();
	}

	b->Initialize(start, prevSeg, first, ispeed);
	return b;
}

void Centipede_Factory::privRecycleCentipede_Body(GameObject* b)
{
	recycledBodies.push((Centipede_Body*)b);
}

void Centipede_Factory::ReportCentipedeHeadDeath()
{
	Score_Manager::SendScoreCmd(Instance().pHeadDeath);
}

void Centipede_Factory::ReportCentipedeBodyDeath()
{
	Score_Manager::SendScoreCmd(Instance().pBodyDeath);
}

void Centipede_Factory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}


Centipede_Factory::~Centipede_Factory()
{
	while (!recycledHeads.empty())
	{
		delete recycledHeads.top();
		recycledHeads.pop();
	}
	while (!recycledBodies.empty())
	{
		delete recycledBodies.top();
		recycledBodies.pop();
	}
	ConsoleMsg::WriteLine("Centipede delete");
}
