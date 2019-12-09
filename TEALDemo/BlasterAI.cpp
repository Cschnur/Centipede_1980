#include "BlasterAI.h"
#include "Score_Manager.h"
#include "Player_Manager.h"
#include "AI_MoveState.h"
#include "AI_MoveFSM.h"
#include "AI_MovementCollection.h"
#include "AI_OffsetArray.h"
#include "MushroomManager.h"
#include "Bullet.h"
#include "Explosion_Factory.h"

BlasterAI::BlasterAI()
{
}

void BlasterAI::Initialize()
{
	pCurrentState = &AI_MoveFSM::StateAI_MoveLeftAndDown;

	speed = 2;

	Pos = PosConverter(29, 14);
	SetDrawOrder(1000);
	MainSprite.setPosition(sf::Vector2f(Pos));

	SetCollider(MainSprite, bitmap, true);
	RegisterCollision<BlasterAI>(*this);

	SetAlarm(0, 3);
	moveCount = RESET/speed;
	change = false;
	active = true;
}

void BlasterAI::Update()
{
	if (!lockout) Fire();
	if (active) 
	{
		prevPos = Pos;
		Pos.x += speed * pCurrentState->GetMoveOffsets()->xMove;
		Pos.y += speed * pCurrentState->GetMoveOffsets()->yMove;
		MainSprite.setPosition(sf::Vector2f(Pos));
		if(Pos.x < MAX_LEFT || Pos.x > MAX_RIGHT || Pos.y > BOTTOM || Pos.y < TOP)
		{
			pCurrentState = pCurrentState->GetNextState(this);
		}
	}
}

int BlasterAI::getX()
{
	return Pos.x;
}

int BlasterAI::getY()
{
	return Pos.y;
}

void BlasterAI::Alarm0()
{
	active = !active;
	SetAlarm(0, 3);
}

void BlasterAI::Collision(Mushroom *other)
{
	Pos.y = prevPos.y;
	MainSprite.setPosition(sf::Vector2f(Pos));
}

void BlasterAI::Collision(Centipede *other)
{
	Explosion_Factory::CreateShipExplosion(Pos);
	Player_Manager::reportDeath();
	MarkForDestroy();
}

void BlasterAI::Collision(Flea *other)
{
	Explosion_Factory::CreateShipExplosion(Pos);
	Player_Manager::reportDeath();
	MarkForDestroy();
}

void BlasterAI::Collision(Spider *other)
{
	Explosion_Factory::CreateShipExplosion(Pos);
	Player_Manager::reportDeath();
	MarkForDestroy();
}

void BlasterAI::Delete()
{
	if (b) b->MarkForDestroy();
	MarkForDestroy();
}

void BlasterAI::Destroy()
{
	DeregisterInput();
	DeregisterCollision<BlasterAI>(*this);
}
