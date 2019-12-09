
#ifndef _SHIP_FACTORY
#define _SHIP_FACTORY

#include <stack>
#include "Game Components\TEAL\CommonElements.h"
#include "PlayerShip.h"

class PlayerShip;
class BlasterKB;
class BlasterAI;

class Ship_Factory
{
public:
	static BlasterKB* CreateShipKB() { return Instance().privCreateShipKB(); };
	static void RecycleShipKB(GameObject* s) { Instance().privRecycleShipKB(s); };

	static BlasterAI* CreateShipAI() { return Instance().privCreateShipAI(); };
	static void RecycleShipAI(GameObject* s) { Instance().privRecycleShipAI(s); };

	static void Terminate();

private:
	static Ship_Factory* ptrInstance;

	Ship_Factory() = default;
	Ship_Factory(const Ship_Factory&) = delete;
	Ship_Factory& operator=(const Ship_Factory&) = delete;
	~Ship_Factory();

	static Ship_Factory& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new Ship_Factory;
		return *ptrInstance;
	};

	std::stack<BlasterKB*> recycledShipsKB;
	std::stack<BlasterAI*> recycledShipsAI;

	BlasterKB* privCreateShipKB();
	void privRecycleShipKB(GameObject* s);

	BlasterAI* privCreateShipAI();
	void privRecycleShipAI(GameObject* s);
};

#endif
