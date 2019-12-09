#include "Block.h"



Block::Block()
{
	bitmap = ResourceManager::GetTextureBitmap("Block");
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("Block"), 1, 1);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / (float)2, MainSprite.getTextureRect().height / (float)2);
	MainSprite.setScale(1, 1);


	SetDrawOrder(900);
	SetCollider(MainSprite, bitmap, true);
}

void Block::Initialize(sf::Vector2i pos)
{
	MainSprite.setPosition((sf::Vector2f)pos);
	RegisterCollision<Block>(*this);
}

void Block::Draw()
{
	//nothing
}

int Block::ReturnStatus()
{
	return 0; //always return as a normal mushroom
}

bool Block::ReturnHealth()
{
	return true; //always return that you are undamaged and unpoisoned
}

void Block::healthUpdate(int type)
{
	//nothing to see here
}

Block::~Block()
{
	DeregisterCollision <Block> (*this);
}
