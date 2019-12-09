#include "Spider.h"
#include "MushroomManager.h"
#include "Mushroom.h"
#include "Critter_Manager.h"
#include "Explosion_Factory.h"
#include "Spider_Factory.h"
#include "SpiderScore.h"

#include "Spider_MoveFSM.h"
#include "Spider_MovementCollection.h"
#include "Spider_OffsetArray.h"


Spider::Spider()
{
	bitmap = ResourceManager::GetTextureBitmap("spider");
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("spider"), 4, 2, 16);
	MainSprite.SetAnimation(0, 7, true, true);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / (float)2, MainSprite.getTextureRect().height / (float)2);
	SetDrawOrder(1000);
	MainSprite.setScale(2, 2);

	SetCollider(MainSprite, bitmap, true);
}

void Spider::Initialize(int ispeed)
{
	speed = ispeed;
	count = conStep / speed;
	spaces = rand() % 4 + 2;

	v2 = rand() % 1 + 26;
	side = rand() % 2;
	if (side == 1)
	{
		Pos = MushroomManager::PosConverter(v2, -1);
		pCurrentState = &Spider_MoveFSM::StateSpider_MoveRightAndDown;
	}
	else
	{
		Pos = MushroomManager::PosConverter(v2, 30);
		pCurrentState = &Spider_MoveFSM::StateSpider_MoveLeftAndDown;
	}
	MainSprite.setPosition(sf::Vector2f(Pos));
	RegisterCollision<Spider>(*this);
}

int Spider::getRow()
{
	return gridPos.x;
}

int Spider::getColumn()
{
	return gridPos.y;
}

int Spider::getSpaces()
{
	return spaces;
}

void Spider::spaceReset()
{
	spaces = rand() % 4 + 2;
}

void Spider::spaceDec()
{
	spaces--;
}

void Spider::Update()
{
	MainSprite.Update();
	Pos.x += speed * pCurrentState->GetMoveOffsets()->xMove;
	Pos.y += speed * pCurrentState->GetMoveOffsets()->yMove;
	MainSprite.setPosition(sf::Vector2f(Pos));
	count--;
	if (count == 0)
	{
		gridPos = MushroomManager::GridConverter(Pos.x, Pos.y);
		tempVal = MushroomManager::CheckGrid(gridPos);
		if (tempVal == 2) 
		{ 
			MarkForDestroy(); 
		}
		else {
			pCurrentState = pCurrentState->GetNextState(this);
			count = conStep / speed;
		}
	}
}

void Spider::Draw()
{
	WindowManager::MainWindow.draw(MainSprite);
}

void Spider::Death(int shipY)
{
	int tmp = shipY - Pos.y;
	Explosion_Factory::CreateCritterExplosion(Pos);
	Spider_Factory::ReportSpiderDeath(tmp, Pos);
	MarkForDestroy();
}

void Spider::Delete()
{
	DeregisterCollision<Spider>(*this);
	MarkForDestroy();
}

void Spider::Destroy()
{
	Critter_Manager::SpiderUpdate();
	DeregisterCollision<Spider>(*this);
}


Spider::~Spider()
{
}
