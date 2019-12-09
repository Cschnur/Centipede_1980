#include "Ship_Factory.h"
#include "Game Components\TEAL\CommonElements.h"
#include "PlayerShip.h"
#include "BlasterKB.h"
#include "BlasterAI.h"

Ship_Factory* Ship_Factory::ptrInstance = NULL;


BlasterKB* Ship_Factory::privCreateShipKB()
{
	BlasterKB *s;

	if (recycledShipsKB.empty())
	{

		s = new BlasterKB();
		s->SetExternalManagement(RecycleShipKB);
	}
	else
	{
		s = recycledShipsKB.top();
		recycledShipsKB.pop();


		s->RegisterToCurrentScene();
	}

	s->Initialize();
	return s;
}

void Ship_Factory::privRecycleShipKB(GameObject* s)
{
	recycledShipsKB.push((BlasterKB*)s);
}

BlasterAI* Ship_Factory::privCreateShipAI()
{
	BlasterAI *s;

	if (recycledShipsAI.empty())
	{

		s = new BlasterAI();
		s->SetExternalManagement(RecycleShipAI);
	}
	else
	{
		s = recycledShipsAI.top();
		recycledShipsAI.pop();


		s->RegisterToCurrentScene();
	}

	s->Initialize();
	return s;
}

void Ship_Factory::privRecycleShipAI(GameObject* s)
{
	recycledShipsAI.push((BlasterAI*)s);
}

void Ship_Factory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}


Ship_Factory::~Ship_Factory()
{
	while (!recycledShipsKB.empty())
	{
		delete recycledShipsKB.top();
		recycledShipsKB.pop();
	}
	while (!recycledShipsAI.empty())
	{
		delete recycledShipsAI.top();
		recycledShipsAI.pop();
	}
	ConsoleMsg::WriteLine("Ship delete");
}
