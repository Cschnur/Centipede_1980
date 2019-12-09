#include "PlayerShip.h"
#include"Bullet.h"
#include "Mushroom.h"
#include "Scorpion.h"
#include "Bullet_Factory.h"
#include "Ship_Explosion.h"
#include "Score_Manager.h"
#include "Sound_Manager.h"

PlayerShip::PlayerShip()
	:lockout(false), speed(3)
{
	bitmap = ResourceManager::GetTextureBitmap("playerShip");
	MainSprite.setTexture(ResourceManager::GetTexture("playerShip"));
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setScale(1, 1);

}

void PlayerShip::Initialize()
{
	Pos = PosConverter(29, 14);
	SetDrawOrder(1100);
	MainSprite.setPosition(sf::Vector2f(Pos));

	SetCollider(MainSprite, bitmap, true);
	RegisterCollision<PlayerShip>(*this);

	RegisterInput(InputFlags::KeyPressed);
}

void PlayerShip::Fire()
{
	b = Bullet_Factory::CreateBullet(Pos, this);
	lockout = true;
	Sound_Manager::playFire();
}

void PlayerShip::MoveUp()
{
	prevPos = Pos;
	Pos += sf::Vector2i(0, -speed);
}

void PlayerShip::MoveDown()
{
	prevPos = Pos;
	Pos += sf::Vector2i(0, speed);
}

void PlayerShip::MoveLeft()
{
	prevPos = Pos;
	Pos += sf::Vector2i(-speed, 0);
}

void PlayerShip::MoveRight()
{
	prevPos = Pos;
	Pos += sf::Vector2i(speed, 0);
}

void PlayerShip::Destroy()
{
	if (b) b->Destroy();
	DeregisterInput();
	DeregisterCollision<PlayerShip>(*this);
}

void PlayerShip::fireUpdate()
{
	lockout = false;
}

int PlayerShip::getY()
{
	return Pos.y;
}

sf::Vector2i PlayerShip::PosConverter(int r, int c)
{
	int x = (c * 16) + 8;
	int y = (r * 16) + 8;
	return sf::Vector2i(x, y);
}

void PlayerShip::Draw()
{
	WindowManager::MainWindow.draw(MainSprite);
}
