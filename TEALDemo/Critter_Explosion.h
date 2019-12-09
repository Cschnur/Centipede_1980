#ifndef _CRITTER_EXPLOSION
#define _CRITTER_EXPLOSION

#include "Game Components\TEAL\CommonElements.h"

class Critter_Explosion : public GameObject
{
public:
	Critter_Explosion();
	void Initialize(sf::Vector2i pos);
	virtual void Update();
	virtual void Draw();
	~Critter_Explosion();

private:
	AnimatedSprite MainSprite;
};

#endif _CRITTER_EXPLOSION

