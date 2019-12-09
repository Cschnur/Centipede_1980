#ifndef _FLEA
#define _FLEA

#include "Game Components\TEAL\CommonElements.h"
#include "Critter.h"

class MushroomManager;
class Critter_Manager;

class Flea : public Critter
{
public:
	Flea();
	void Update();
	void Initialize(int ispeed);
	void healthUpdate();
	void Draw();
	void Destroy();
	virtual void Delete() override;
	~Flea();
private:
	sf::Vector2i gridPos;
	bool active = true;
	int temp;
	int health = 2;
	int randVal;

	AnimatedSprite MainSprite;
	CollisionTools::TextureBitmap bitmap;
};

#endif

