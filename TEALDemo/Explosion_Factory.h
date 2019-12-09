#ifndef _EXPLOSION_FACTORY
#define _EXPLOSION_FACTORY

class Critter_Explosion;
class Ship_Explosion;

#include "Game Components\TEAL\CommonElements.h"
#include <stack>

class Explosion_Factory
{
	public:
		static void CreateCritterExplosion(sf::Vector2i pos) { Instance().privCreateCritterExplosion(pos); };
		static void RecycleCritterExplosion(GameObject* e) { Instance().privRecycleCritterExplosion(e); };

		static void CreateShipExplosion(sf::Vector2i pos) { Instance().privCreateShipExplosion(pos); };
		static void RecycleShipExplosion(GameObject* e) { Instance().privRecycleShipExplosion(e); };

		static void Terminate();

	private:
		static Explosion_Factory* ptrInstance;

		Explosion_Factory() = default;
		Explosion_Factory(const Explosion_Factory&) = delete;
		Explosion_Factory& operator=(const Explosion_Factory&) = delete;
		~Explosion_Factory();

		static Explosion_Factory& Instance()
		{
			if (!ptrInstance)
				ptrInstance = new Explosion_Factory;
			return *ptrInstance;
		};

		std::stack<Critter_Explosion*> recycledCritterExplosions;
		std::stack<Ship_Explosion*> recycledShipExplosions;

		void privCreateCritterExplosion(sf::Vector2i pos);
		void privRecycleCritterExplosion(GameObject* e);

		void privCreateShipExplosion(sf::Vector2i pos);
		void privRecycleShipExplosion(GameObject* e);
	};

#endif

