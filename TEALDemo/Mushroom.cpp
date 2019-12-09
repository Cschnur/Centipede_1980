#include "Mushroom.h"
#include "Bullet.h"
#include "PlayerShip.h"
#include "MushroomManager.h"
#include "Mushroom_Factory.h"
#include "Explosion_Factory.h"

Mushroom::Mushroom()
{
	//Setting Sprite Details
	bitmap = ResourceManager::GetTextureBitmap("mushroom");
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("mushroom"), 4, 2);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / (float)2, MainSprite.getTextureRect().height / (float)2);
	MainSprite.setScale(1, 1);

	
	SetDrawOrder(1000);
	SetCollider(MainSprite, bitmap, true);
	
}

void Mushroom::Initialize(sf::Vector2i start)
{
	health = 4;
	mState = Normal;
	/*if (start.y >= 408)
		mState = Poison;*/
	Pos = start;
	MainSprite.setPosition(sf::Vector2f(Pos));
	healthUpdate(2);
	RegisterCollision<Mushroom>(*this);
}

/*The int type tells the function what fin dof update to do
0 ----- decrease health by 1
1 ----- set health to zero, destroying mushroom
2 ----- set health to 4, restore health*/
void Mushroom::healthUpdate(int type)
{
	if (type == 0) {
		health--;
		if (mState == Normal) normalHealth();
		else poisonHealth();
	}
	else if (type == 1)
	{
		MushroomManager::GridDelete(Pos);
		MarkForDestroy();
	}
	else if (type == 2)
	{
		if (mState == Normal) normalHealth();
		else poisonHealth();
	}
}

void Mushroom::normalHealth()
{
	switch (health)
	{
	case 0:
		MushroomManager::GridDelete(Pos);
		Mushroom_Factory::ReportRegularDeath();
		MarkForDestroy();
		break;
	case 1:
		MainSprite.SetAnimation(3, 3);
		break;
	case 2:
		MainSprite.SetAnimation(2, 2);
		break;
	case 3:
		MainSprite.SetAnimation(1, 1);
		break;
	case 4:
		MainSprite.SetAnimation(0, 0);
		break;
	default:
		break;
	}
}

void Mushroom::poisonHealth()
{
	switch (health)
	{
	case 0:
		MushroomManager::GridDelete(Pos);
		Mushroom_Factory::ReportPoisonDeath();
		MarkForDestroy();
		break;
	case 1:
		MainSprite.SetAnimation(7, 7);
		break;
	case 2:
		MainSprite.SetAnimation(6, 6);
		break;
	case 3:
		MainSprite.SetAnimation(5, 5);
		break;
	case 4:
		MainSprite.SetAnimation(4, 4);
		break;
	default:
		break;
	}
}

void Mushroom::Regen()
{
	mState = Normal;
	health = 4;
	MainSprite.SetAnimation(0, 0);
	Explosion_Factory::CreateCritterExplosion(Pos);
	Mushroom_Factory::ReportRegen();
}

int Mushroom::ReturnStatus()
{
	return mState;
}

bool Mushroom::ReturnHealth()
{
	if (mState == Poison)
		return false;
	if (health == 4)
		return true;
	else return false;
}

void Mushroom::SetPoison()
{
	mState = Poison;
	poisonHealth();
}

void Mushroom::Delete()
{
	MarkForDestroy();
}

void Mushroom::Destroy()
{
	DeregisterCollision<Mushroom>(*this);
}

void Mushroom::Draw()
{
	WindowManager::MainWindow.draw(MainSprite);
}

Mushroom::~Mushroom()
{
}
