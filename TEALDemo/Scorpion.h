#ifndef _SCORPION
#define _SCORPION

#include "Game Components\TEAL\CommonElements.h"
#include "Critter.h"

class MushroomManager;
class Mushroom;
class Bullet;
class Critter_Manager;

class Scorpion : public Critter
{
public:
	void Draw();
	void Death();
	void Destroy();
	void Update();
	void Initialize(int ispeed);
	Scorpion();
	virtual void Delete() override;
	~Scorpion();
private:
	int v2;
	int side;
	sf::Vector2i gridPos;
	int temp;

	AnimatedSprite MainSprite;
	CollisionTools::TextureBitmap bitmap;

};

#endif

