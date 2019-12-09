#ifndef _Mushroom
#define _Mushroom
#include "Game Components\TEAL\CommonElements.h"
#include "GridObject.h"

class PlayerShip;
class Bullet;
class MushroomManager;

class Mushroom : public GameObject
{
public:
	Mushroom();
	virtual void Initialize(sf::Vector2i start);
	virtual void Draw();
	virtual void Destroy();
	virtual void healthUpdate(int type);
	void normalHealth();
	void poisonHealth();
	virtual int ReturnStatus();
	virtual bool ReturnHealth();
	void SetPoison();
	void Regen();
	void Delete();
	~Mushroom();
private:
	int health;
	sf::Vector2i Pos;
	enum mushroomState
	{
		Normal = 0,
		Poison = 1
	};
	mushroomState mState;
protected:
	AnimatedSprite MainSprite;
	CollisionTools::TextureBitmap bitmap;

};
#endif
