#include "BlasterKB.h"
#include "Score_Manager.h"
#include "Player_Manager.h"
#include "Bullet.h"
#include "Explosion_Factory.h"

BlasterKB::BlasterKB()
{
}

void BlasterKB::Initialize()
{
	Pos = PosConverter(29, 14);
	SetDrawOrder(1000);
	MainSprite.setPosition(sf::Vector2f(Pos));

	SetCollider(MainSprite, bitmap, true);
	RegisterCollision<BlasterKB>(*this);

	b = nullptr;
}

void BlasterKB::Update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) MoveLeft();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) MoveRight();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) MoveUp();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) MoveDown();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !lockout)
	{
		Fire();
	}
	Tools::Clamp<int>(Pos.x, MainSprite.getTextureRect().width / 2, (int)WindowManager::MainWindow.getView().getSize().x - (MainSprite.getTextureRect().width / 2));
	Tools::Clamp<int>(Pos.y, 408, (int)WindowManager::MainWindow.getView().getSize().y - (MainSprite.getTextureRect().height / 2) - 16);
	MainSprite.setPosition(sf::Vector2f(Pos));
}

void BlasterKB::Collision(Mushroom *other)
{
	Pos = prevPos;
	MainSprite.setPosition(sf::Vector2f(Pos));
}

void BlasterKB::Collision(Centipede *other)
{
	Explosion_Factory::CreateShipExplosion(Pos);
	Player_Manager::reportDeath();
	MarkForDestroy();
}

void BlasterKB::Collision(Flea *other)
{
	Explosion_Factory::CreateShipExplosion(Pos);
	Player_Manager::reportDeath();
	MarkForDestroy();
}

void BlasterKB::Collision(Spider *other)
{
	Explosion_Factory::CreateShipExplosion(Pos);
	Player_Manager::reportDeath();
	MarkForDestroy();
}

void BlasterKB::Destroy()
{
	if (b) b->MarkForDestroy();
}

BlasterKB::~BlasterKB()
{
	DeregisterCollision<BlasterKB>(*this);
}

