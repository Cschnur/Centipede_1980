#ifndef _SHIP_EXPLOSION
#define _SHIP_EXPLOSION

#include "Game Components\TEAL\CommonElements.h"

class Ship_Explosion : public GameObject
{
public:
	Ship_Explosion();
	void Initialize(sf::Vector2i pos);
	virtual void Update();
	virtual void Draw();
	~Ship_Explosion();

private:
	AnimatedSprite MainSprite;
};

#endif _SHIP_EXPLOSION

