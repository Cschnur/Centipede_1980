#ifndef _PlayerShip
#define _PlayerShip
#include "Game Components\TEAL\CommonElements.h"

class Mushroom;
class Centipede;
class Flea;
class Spider;
class Bullet;

class PlayerShip : public GameObject
{
public:
	PlayerShip();
	virtual void Draw();
	virtual void fireUpdate();
	void Destroy();
	void Initialize();
	sf::Vector2i PosConverter(int r, int c);
	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
	void Fire();
	int getY();
protected:
	sf::Vector2i Pos;
	sf::Vector2i prevPos;
	sf::Vector2i Impulse;
	AnimatedSprite MainSprite;
	Bullet* b;
	CollisionTools::TextureBitmap bitmap;
	bool keyPress;
	bool lockout;
	int speed;
};


#endif _PlayerShip

