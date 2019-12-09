#ifndef _Bullet
#define _Bullet
#include "Game Components\TEAL\CommonElements.h"

class Mushroom;
class Block;
class Centipede_Head;
class Centipede_Body;
class Scorpion;
class Flea;
class PlayerShip;
class Spider;

class Bullet : public GameObject
{
public:
	virtual void Draw();
	virtual void Update();
	void Initialize(sf::Vector2i start, PlayerShip *player);
	Bullet();

	//Collision Functions//
	virtual void Collision(GameObject *other) {};
	void Collision(Mushroom *other);
	void Collision(Block *other);
	void Collision(Centipede_Head *other);
	void Collision(Centipede_Body *other);
	void Collision(Scorpion *other);
	void Collision(Flea *other);
	void Collision(Spider *other);

	virtual void Destroy();
private:
	sf::Vector2i Pos;
	sf::Vector2i Impulse;
	AnimatedSprite MainSprite;
	PlayerShip *blaster;
	CollisionTools::TextureBitmap bitmap;
};
#endif;

