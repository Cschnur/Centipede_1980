#include "Centipede_Body.h"
#include "Centipede_Head.h"
#include "MushroomManager.h"
#include "MoveState.h"
#include "MoveFSM.h"
#include "MovementCollection.h"
#include "Centipede_Factory.h"
#include "Explosion_Factory.h"
#include "Centipede_Manager.h"
#include "OffsetArray.h"

#include "Color_Manager.h"


Centipede_Body::Centipede_Body()
	:active(false)
{
	bitmap = ResourceManager::GetTextureBitmap("Master");
	colliderSprite = AnimatedSprite(ResourceManager::GetTexture("Master"), 28, 77, (16));
	colliderSprite.SetAnimation(70, 73, true, false);
	colliderSprite.setOrigin(colliderSprite.getTextureRect().width / (float)2, colliderSprite.getTextureRect().height / (float)2);
	colliderSprite.setScale(2, 2);

	MainSprite = Color_Manager::ReturnBody();

	SetDrawOrder(1000);
	SetCollider(colliderSprite, bitmap, true);
}

void Centipede_Body::Initialize(sf::Vector2i start, void *prevSeg, bool hd, int ispeed)
{
	Pos = start;
	rot = 0;
	speed = ispeed;
	count = 0;

	gridPos = MushroomManager::GridConverter(Pos.x, Pos.y);
	RegisterCollision<Centipede_Body>(*this);
	active = false;
	headless = false;

	if (hd) // if you are the first body segment
	{
		head = (Centipede_Head *)prevSeg;
		prev = nullptr;
		first = true;
	}
	else //you are not the first body segment
	{
		first = false;
		head = nullptr;
		prev = (Centipede_Body *)prevSeg;
	}
	next = nullptr;
	Centipede_Manager::reportSpawn();
	pCurrentState = &MoveFSM::StateTurnDownSwitchToRight;
}
//Returns a pointer to the next segment
Centipede_Body* Centipede_Body::getNext()
{
	if (next) return next;
	return nullptr;
}
//Return a pointer to the previous segment...only bodies
Centipede_Body* Centipede_Body::getPrev()
{
	if (prev) return prev;
	return nullptr;
}

//Sets the pointer to the next segment
void Centipede_Body::SetNext(Centipede_Body *nextSeg)
{
	next = nextSeg;
}

//Sets the head pointer if you are the first body
void Centipede_Body::SetHead(Centipede_Head *hptr)
{
	prev = nullptr;
	head = hptr;
}

//Returns the current row position
int Centipede_Body::getRow()
{
	return gridPos.x;
}

void Centipede_Body::Update()
{
	//if (active) MainSprite.Update();
	if (count != 0)
	{
		//update x, y, and rotation values
		Pos.x += speed * (pCurrentState->GetMoveOffsets()->xMove);
		Pos.y += speed * (pCurrentState->GetMoveOffsets()->yMove);

		//--//
		rot += (speed * (pCurrentState->GetMoveOffsets()->rot));
		//--//

		count--;
	}
	else if (headless) //when a move is finished then transition into a head, if head is gone
	{
		if(next) next->MovementUpdate(pCurrentState);
		BecomeHead();
	}
}
//Pass your last movement to the next segment, then start your new movement
void Centipede_Body::MovementUpdate(const MoveState* state)
{
	//active bool keeps the segments from all startign at once
	if (next && active) next->MovementUpdate(pCurrentState); 
	pCurrentState = state;
	count = conCount / speed;
	active = true;
}
//Set the neccesary values to become a head, wait until current move is finished
void Centipede_Body::HeadDeath()
{
	headless = true;
	gridPos = MushroomManager::GridConverter(Pos.x, Pos.y);
}

void Centipede_Body::BecomeHead()
{
	//Sets the start rotation of a new head,  0 = left, 180 = right
	float tmp = 0.0f;
	if (pCurrentState->GetMoveOffsets()->xMove > 0) tmp = 180.0f;

	pCurrentState = pCurrentState->BreakState(this);
	Centipede_Head *h = Centipede_Factory::CreateCentipede_Head(Pos, pCurrentState, next, 0, tmp, speed);
	Centipede_Manager::reportSplit(h);
	if (next) 
	{
		next->SetHead(h);
		next->nowFirst();
	}
	MarkForDestroy();
}

//This will be called if the body in front of you becomes a head
void Centipede_Body::nowFirst()
{
	first = true;
}

void Centipede_Body::Death()
{
	if (first)
	{
		head->SetNext();
	}
	else prev->SetNext(nullptr);
	if (next) next->HeadDeath();
	Explosion_Factory::CreateCritterExplosion(Pos);
	gridPos = MushroomManager::GridConverter(Pos.x, Pos.y);
	gridPos.y += pCurrentState->GetMoveOffsets()->rowOffset;
	MushroomManager::MushroomSpawn(gridPos);
	Centipede_Manager::reportDeath();
	Centipede_Factory::ReportCentipedeBodyDeath(); //scoring
	MarkForDestroy();
}

void Centipede_Body::Draw()
{
	MainSprite->setRotation(rot);
	MainSprite->setPosition(sf::Vector2f(Pos));
	colliderSprite.setRotation(rot);
	colliderSprite.setPosition(sf::Vector2f(Pos));
	WindowManager::MainWindow.draw(*MainSprite);
}
void Centipede_Body::Destroy()
{
	DeregisterCollision<Centipede_Body>(*this);
}

void Centipede_Body::Delete()
{
	if (next) next->Delete();
	Centipede_Manager::reportDelete();
	DeregisterCollision<Centipede_Body>(*this);
	MarkForDestroy();
}

Centipede_Body::~Centipede_Body()
{
}
