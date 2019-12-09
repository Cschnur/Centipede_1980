#ifndef _BLASTERAI
#define _BLASTERAI

#include "PlayerShip.h"

const int RESET = 16;

class AI_MoveState;

class BlasterAI : public PlayerShip
{
public:
	BlasterAI();
	void Update();
	void Initialize();

	void Delete();

	const AI_MoveState *pCurrentState;
	int getX();
	int getY();
	sf::Vector2i gridPos;
	static const int MAX_LEFT = 40;
	static const int MAX_RIGHT = 440;
	static const int BOTTOM = 504;
	static const int TOP = 408;
	sf::Vector2i moves;

	virtual void Collision(GameObject *other) {};
	void Collision(Mushroom *other);
	void Collision(Centipede *other);
	void Collision(Flea *other);
	void Collision(Spider *other);
	void Destroy();
	virtual void Alarm0();

	bool change;
	bool active;

	int moveCount;
};

#endif
