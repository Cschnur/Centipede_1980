#include "Scorpion.h"
#include "MushroomManager.h"
#include "Mushroom.h"
#include "Critter_Manager.h"
#include "Explosion_Factory.h"
#include "Scorpion_Factory.h"


Scorpion::Scorpion()
{

	bitmap = ResourceManager::GetTextureBitmap("scorpion");
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("scorpion"), 4, 1, 16);
	MainSprite.SetAnimation(0, 3, true, true);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / (float)2, MainSprite.getTextureRect().height / (float)2);
	SetDrawOrder(1000);

	SetCollider(MainSprite, bitmap, true);
}

void Scorpion::Initialize(int ispeed)
{
	speed = ispeed;
	count = conStep / speed;
	
	v2 = rand() % 15 + 4;
	side = rand() % 2;
	if (side == 1)
	{
		Pos = MushroomManager::PosConverter(v2, -1);
		Impulse = MoveRight();
		MainSprite.setScale(-1, 1);
	}
	else
	{
		Pos = MushroomManager::PosConverter(v2, 30);
		Impulse = MoveLeft();
		MainSprite.setScale(1, 1);
	}

	MainSprite.setPosition(sf::Vector2f(Pos));
	RegisterCollision<Scorpion>(*this);

}

void Scorpion::Update()
{
	if (count == 0)
	{
		gridPos = MushroomManager::GridConverter(Pos.x, Pos.y);
		temp = MushroomManager::CheckGrid(gridPos);
		if (temp == 0)
		{
			MushroomManager::PoisonMushroom(gridPos.x, gridPos.y);
		}
		else if (temp == 2)
		{
			MarkForDestroy();
		}
			count = conStep / speed;
	}
	else 
	{
		MainSprite.Update();
		Pos += Impulse;
		MainSprite.setPosition(sf::Vector2f(Pos));
		count--;
	}
}

void Scorpion::Death()
{
	Scorpion_Factory::ReportScorpionDeath();
	Explosion_Factory::CreateCritterExplosion(Pos);
	MarkForDestroy();
}

void Scorpion::Destroy()
{
	Critter_Manager::ScorpionUpdate();
	DeregisterCollision<Scorpion>(*this);
}

void Scorpion::Delete()
{
	DeregisterCollision<Scorpion>(*this);
	MarkForDestroy();
}
 
void Scorpion::Draw()
{
	WindowManager::MainWindow.draw(MainSprite);
} 

Scorpion::~Scorpion()
{
}
