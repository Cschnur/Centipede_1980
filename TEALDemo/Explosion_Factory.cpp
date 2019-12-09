#include "Explosion_Factory.h"
#include "Critter_Explosion.h"
#include "Ship_Explosion.h"

Explosion_Factory* Explosion_Factory::ptrInstance = NULL;


void Explosion_Factory::privCreateCritterExplosion(sf::Vector2i pos)
{
	Critter_Explosion *e;

	if (recycledCritterExplosions.empty())
	{

		e = new Critter_Explosion();
		e->SetExternalManagement(RecycleCritterExplosion);
	}
	else
	{
		e = recycledCritterExplosions.top();
		recycledCritterExplosions.pop();


		e->RegisterToCurrentScene();
	}

	e->Initialize(pos);
}

void Explosion_Factory::privRecycleCritterExplosion(GameObject* e)
{
	recycledCritterExplosions.push((Critter_Explosion*)e);
}

void Explosion_Factory::privCreateShipExplosion(sf::Vector2i pos)
{
	Ship_Explosion *e;

	if (recycledShipExplosions.empty())
	{

		e = new Ship_Explosion();
		e->SetExternalManagement(RecycleShipExplosion);
	}
	else
	{
		e = recycledShipExplosions.top();
		recycledShipExplosions.pop();


		e->RegisterToCurrentScene();
	}

	e->Initialize(pos);
}

void Explosion_Factory::privRecycleShipExplosion(GameObject* e)
{
	recycledShipExplosions.push((Ship_Explosion*)e);
}

void Explosion_Factory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}


Explosion_Factory::~Explosion_Factory()
{
	while (!recycledCritterExplosions.empty())
	{
		delete recycledCritterExplosions.top();
		recycledCritterExplosions.pop();
	}
	while (!recycledShipExplosions.empty())
	{
		delete recycledShipExplosions.top();
		recycledShipExplosions.pop();
	}
}
