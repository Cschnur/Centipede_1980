#ifndef _CENTIPEDE
#define _CENTIPEDE

#include "Game Components\TEAL\CommonElements.h"

class MushroomManager;

class Centipede : public GameObject
{
public:
	Centipede();
	virtual void Delete() = 0;
	~Centipede();

protected:
	sf::Vector2i gridOffset;
	float rot;
	int speed;
	int count;
	const int conCount = 16;
	sf::Vector2i Pos;
	sf::Vector2i gridPos;
	AnimatedSprite* MainSprite;
	AnimatedSprite colliderSprite;
	CollisionTools::TextureBitmap bitmap;

private:
	bool vert = true;
	bool bounded;
	sf::Vector2i Impulse;
	int tempVal;
};

#endif

