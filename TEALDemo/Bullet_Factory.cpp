#include "Bullet_Factory.h"
#include "Game Components\TEAL\CommonElements.h"
#include "Bullet.h"
#include "PlayerShip.h"

Bullet_Factory* Bullet_Factory::ptrInstance = NULL;


Bullet* Bullet_Factory::privCreateBullet(sf::Vector2i pos, PlayerShip *player)
{
	Bullet* b;

	if (recycledItems.empty())
	{

		b = new Bullet();
		b->SetExternalManagement(RecycleBullet);
	}
	else
	{
		b = recycledItems.top();
		recycledItems.pop();

								
		b->RegisterToCurrentScene();
	}

	b->Initialize(pos, player);
	return b;
}

void Bullet_Factory::privRecycleBullet(GameObject* b)
{
	recycledItems.push((Bullet*)b);
}

void Bullet_Factory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}


Bullet_Factory::~Bullet_Factory()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}
