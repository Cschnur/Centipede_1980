#ifndef _SPIDER
#define _SPIDER

#include "Game Components\TEAL\CommonElements.h"
#include "Critter.h"

class MushroomManager;
class Mushroom;
class Bullet;
class Critter_Manager;

class Spider_MoveState;

class Spider : public Critter
{
public:
	Spider();
	void Update();
	void Initialize(int ispeed);
	void Draw();
	void Death(int shipY);
	void Destroy();
	int getRow();
	int getColumn();
	int getSpaces();
	void spaceReset();
	void spaceDec();
	virtual void Delete() override;
	~Spider();
private:
	const Spider_MoveState* pCurrentState;
	sf::Vector2i gridPos;
	int temp;
	int v2;
	int side;
	int spaces;
	int tempVal;
	AnimatedSprite MainSprite;
	CollisionTools::TextureBitmap bitmap;
};

#endif
