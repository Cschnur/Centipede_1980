#include "Flea.h"
#include "MushroomManager.h"
#include "Critter_Manager.h"
#include "Explosion_Factory.h"
#include "Flea_Factory.h"


Flea::Flea()
{
	bitmap = ResourceManager::GetTextureBitmap("flea");
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("flea"), 2, 2, 16);
	MainSprite.SetAnimation(0, 3);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / (float)4, MainSprite.getTextureRect().height / (float)2);
	MainSprite.setScale(1, 1);
	SetDrawOrder(1000);

	SetCollider(MainSprite, bitmap, true);
}

void Flea::Initialize(int ispeed)
{
	speed = ispeed;
	count = conStep;

	health = 2;
	active = true;

	Impulse = MoveDown();

	randVal = rand() % 29;
	Pos = MushroomManager::PosConverter(-1, randVal);
	MainSprite.setPosition(sf::Vector2f(Pos));

	RegisterCollision<Flea>(*this);
}

void Flea::Update()
{
	MainSprite.Update();
	Pos += Impulse;
	MainSprite.setPosition(sf::Vector2f(Pos));
	count--;
	if (count == 0)
	{
		gridPos = MushroomManager::GridConverter(Pos.x, Pos.y);
		temp = MushroomManager::CheckGrid(gridPos);
		if (gridPos.x == 31)
		{
			Critter_Manager::FleaUpdate(true);
			MarkForDestroy();
		}
		else if (temp == 4 && active)
		{
			if ((rand() % 100 + 1) < 25)
			{
				MushroomManager::MushroomSpawn(gridPos);
			}
		}
		count = conStep / speed;
	}
}

void Flea::healthUpdate()
{
	health--;
	switch (health)
	{
	case 0:
		Flea_Factory::ReportFleaDeath();
		Explosion_Factory::CreateCritterExplosion(Pos);
		Critter_Manager::FleaUpdate(true);
		MarkForDestroy();
		break;
	case 1:
		active = false;
		speed *= 2;
		Impulse = MoveDown();
		break;
	default:
		break;
	}
}

void Flea::Draw()
{
	WindowManager::MainWindow.draw(MainSprite);
}

void Flea::Delete()
{
	Critter_Manager::FleaUpdate(false);
	//DeregisterCollision<Flea>(*this);
	MarkForDestroy();
}

void Flea::Destroy()
{
	//Critter_Manager::FleaUpdate(true);
	DeregisterCollision<Flea>(*this);
}


Flea::~Flea()
{
}
