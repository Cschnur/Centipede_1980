#ifndef _SPIDERSCORE
#define _SPIDERSCORE

#include "Game Components\TEAL\CommonElements.h"

class SpiderScore : public GameObject
{
public:
	SpiderScore();
	void Initialize(sf::Vector2i pos, int val);
	~SpiderScore();
	void Draw();
	void Alarm0();
private:
	AnimatedSprite MainSprite;
};

#endif
