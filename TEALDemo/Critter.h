#ifndef _CRITTER
#define _CRITTER

#include "Game Components\TEAL\CommonElements.h"

class Critter : public GameObject
{
protected:
	static const sf::Vector2i left;
	static const sf::Vector2i right;
	static const sf::Vector2i down;
	static const sf::Vector2i up;
	sf::Vector2i Pos;
	sf::Vector2i Impulse;
	int speed;
	static const int conStep = 16;
	int count;
	//Critter MoveFunctions
	sf::Vector2i MoveDown();
	sf::Vector2i MoveUp();
	sf::Vector2i MoveLeft();
	sf::Vector2i MoveRight();
	sf::Vector2i MoveDownRight();
	sf::Vector2i MoveDownLeft();
	sf::Vector2i MoveUpRight();
	sf::Vector2i MoveUpLeft();

public:
	virtual void Delete() = 0;

};

#endif

