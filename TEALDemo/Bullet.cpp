#include "Bullet.h"
#include "PlayerShip.h"
#include "Mushroom.h"
#include "Centipede_Head.h"
#include "Centipede_Body.h"
#include "Scorpion.h"
#include "Flea.h"
#include "Spider.h"

Bullet::Bullet()
{
	bitmap = ResourceManager::GetTextureBitmap("bullet");
	MainSprite.setTexture(ResourceManager::GetTexture("bullet"));
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setScale(1, 1);
	SetDrawOrder(1000);
	Impulse = sf::Vector2i(0, -10);

	SetCollider(MainSprite, bitmap, true);
}

void Bullet::Initialize(sf::Vector2i start, PlayerShip *player)
{
	blaster = player;
	Pos = start;
	RegisterCollision<Bullet>(*this);
	MainSprite.setPosition(sf::Vector2f(Pos));
}

void Bullet::Collision(Mushroom *other)
{
	other->healthUpdate(0);
	MarkForDestroy();
}

void Bullet::Collision(Block *other)
{
	MarkForDestroy();
}

void Bullet::Collision(Centipede_Head *other)
{
	other->Death();
	MarkForDestroy();
}

void Bullet::Collision(Centipede_Body *other)
{
	other->Death();
	MarkForDestroy();
}

void Bullet::Collision(Scorpion *other)
{
	other->Death();
	MarkForDestroy();
}
void Bullet::Collision(Flea *other)
{
	other->healthUpdate();
	MarkForDestroy();
}
void Bullet::Collision(Spider *other)
{
	int tmp = blaster->getY();
	other->Death(tmp);
	MarkForDestroy();
}

void Bullet::Update()
{
	Pos += Impulse;
	MainSprite.setPosition(sf::Vector2f(Pos));
	if (Pos.y < 0)
	{
		MarkForDestroy();
	}
}

void Bullet::Destroy()
{
	blaster->fireUpdate();
	DeregisterCollision<Bullet>(*this);
}

void Bullet::Draw()
{
	WindowManager::MainWindow.draw(MainSprite);
}
