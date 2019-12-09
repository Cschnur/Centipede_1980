#include "Critter.h"


const sf::Vector2i Critter::left = sf::Vector2i(-1, 0);
const sf::Vector2i Critter::right = sf::Vector2i(1, 0);
const sf::Vector2i Critter::down = sf::Vector2i(0, 1);
const sf::Vector2i Critter::up = sf::Vector2i(0, -1);

void Critter::Delete()
{
	MarkForDestroy();
}

sf::Vector2i Critter::MoveUp()
{
	return speed * up;
}

sf::Vector2i Critter::MoveDown()
{
	return speed * down;
}

sf::Vector2i Critter::MoveLeft()
{
	return speed * left;
}

sf::Vector2i Critter::MoveRight()
{
	return speed * right;
}

sf::Vector2i Critter::MoveDownRight()
{
	return MoveDown() + MoveRight();
}
sf::Vector2i Critter::MoveDownLeft()
{
	return MoveDown() + MoveLeft();
}
sf::Vector2i Critter::MoveUpRight()
{
	return MoveUp() + MoveRight();
}
sf::Vector2i Critter::MoveUpLeft()
{
	return MoveUp() + MoveLeft();
}