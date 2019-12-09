
#ifndef _BULLET_FACTORY
#define _BULLET_FACTORY

#include <stack>
#include "Game Components\TEAL\CommonElements.h"
#include "Bullet.h"

class PlayerShip;

class Bullet_Factory
{
public:
	static Bullet* CreateBullet(sf::Vector2i pos, PlayerShip *player) { return Instance().privCreateBullet(pos, player); };
	static void RecycleBullet(GameObject* b) { Instance().privRecycleBullet(b); };

	static void Terminate();

private:
	static Bullet_Factory* ptrInstance;	

	Bullet_Factory() = default;												
	Bullet_Factory(const Bullet_Factory&) = delete;				
	Bullet_Factory& operator=(const Bullet_Factory&) = delete;	
	~Bullet_Factory();													

	static Bullet_Factory& Instance()	  
	{
		if (!ptrInstance)
			ptrInstance = new Bullet_Factory;
		return *ptrInstance;
	};

	std::stack<Bullet*> recycledItems; 

	Bullet* privCreateBullet(sf::Vector2i pos, PlayerShip *player);
	void privRecycleBullet(GameObject* b);
};

#endif
