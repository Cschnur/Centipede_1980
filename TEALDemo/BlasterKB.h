#ifndef _BLASTERKB
#define _BLASTERKB

#include "PlayerShip.h"
class BlasterKB : public PlayerShip
{
public:
	BlasterKB();
	void Update();
	void Initialize();
	virtual void Collision(GameObject *other) {};
	void Collision(Mushroom *other);
	void Collision(Centipede *other);
	void Collision(Flea *other);
	void Collision(Spider *other);
	void Destroy();
	~BlasterKB();
};

#endif

