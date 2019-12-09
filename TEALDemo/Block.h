#ifndef _BLOCK_
#define _BLOCK_

#include "Mushroom.h"

class Block : public Mushroom
{
public:
	Block();
	void Initialize(sf::Vector2i start) override;
	void Draw() override;
	int ReturnStatus() override;
	bool ReturnHealth() override;
	void healthUpdate(int type) override;
	~Block();
};

#endif

