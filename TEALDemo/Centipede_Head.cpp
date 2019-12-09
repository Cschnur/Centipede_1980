#include "Centipede_Head.h"
#include "MushroomManager.h"
#include "Centipede_Body.h"
#include "Centipede_Manager.h"
#include "Explosion_Factory.h"
#include "Centipede_Factory.h"
#include "MoveState.h"
#include "MoveFSM.h"
#include "MovementCollection.h"
#include "OffsetArray.h"

#include "Color_Manager.h"

Centipede_Head::Centipede_Head()
	:poisoned(false), next(nullptr)
{
	bitmap = ResourceManager::GetTextureBitmap("Master_bmp");
	colliderSprite = AnimatedSprite(ResourceManager::GetTexture("Master"), 28, 77, (16));
	colliderSprite.SetAnimation(70, 73, true, false);
	colliderSprite.setOrigin(colliderSprite.getTextureRect().width / (float)2, colliderSprite.getTextureRect().height / (float)2);
	colliderSprite.setScale(2, 2);

	MainSprite = Color_Manager::ReturnHead();


	SetDrawOrder(1000);
	SetCollider(colliderSprite, bitmap, true);
}

void Centipede_Head::Initialize(sf::Vector2i istart, const MoveState* state, Centipede_Body *inext, int ilength, float Rot, int ispeed)
{
	Pos = istart;
	speed = ispeed;
	rot = Rot;

	//MainSprite->setRotation(rot);
	gridPos = MushroomManager::GridConverter(Pos.x, Pos.y);
	//MainSprite->setPosition(sf::Vector2f(Pos));

	next = inext;
	if (ilength > 0) SpawnSegments(ilength);

	RegisterCollision<Centipede_Head>(*this);

	pCurrentState = state;
	count = 16 / speed;

}
/*Spawns length amount of body segments and links them together with pointers*/
void Centipede_Head::SpawnSegments(int length)
{
	int temp = length;
	Centipede_Body *prevSeg = nullptr;
	Centipede_Body *nextSeg = nullptr;
	Centipede_Body *currSeg = nullptr;
	currSeg = new Centipede_Body();
	currSeg->Initialize(Pos, this, true, speed);
	next = currSeg;
	temp--;
	while (temp != 0)
	{
		prevSeg = currSeg;
		currSeg = Centipede_Factory::CreateCentipede_Body(Pos, prevSeg, false, speed);
		temp--;
	}
	while (temp != length)
	{
		if (!prevSeg) temp++;
		else {
			prevSeg->SetNext(currSeg);
			currSeg = prevSeg;
			prevSeg = prevSeg->getPrev();
			temp++;
		}
	}
}

void Centipede_Head::SetNext()
{
	next = nullptr;
}

void Centipede_Head::Update()
{
	if (count != 0)
	{
		//MainSprite.Update();
		Pos.x += speed * (pCurrentState->GetMoveOffsets()->xMove);
		Pos.y += speed * (pCurrentState->GetMoveOffsets()->yMove);

		//--//
		rot += (speed * (pCurrentState->GetMoveOffsets()->rot));
		//--//

		//MainSprite->rotate(speed * (pCurrentState->GetMoveOffsets()->rot));
		//MainSprite.setPosition(sf::Vector2f(Pos));
		count--;
	}
	else
	{
		if (next) next->MovementUpdate(pCurrentState);
		gridPos = MushroomManager::GridConverter(Pos.x, Pos.y);
		pCurrentState = pCurrentState->GetNextState(this);
		count = 16 / speed;
	}
}

sf::Vector2i Centipede_Head::GetPos()
{
	return Pos;
}
int Centipede_Head::GetRow()
{
	return gridPos.x;
}
int Centipede_Head::GetCol()
{
	return gridPos.y;
}

void Centipede_Head::Draw()
{
	MainSprite->setRotation(rot);
	MainSprite->setPosition(sf::Vector2f(Pos));
	colliderSprite.setRotation(rot);
	colliderSprite.setPosition(sf::Vector2f(Pos));
	WindowManager::MainWindow.draw(*MainSprite);
}

void Centipede_Head::Death()
{
	Centipede_Factory::ReportCentipedeHeadDeath();
	Explosion_Factory::CreateCritterExplosion(Pos);
	if (next) next->HeadDeath();
	Centipede_Manager::reportDeath();
	gridPos.y += pCurrentState->GetMoveOffsets()->rowOffset;
	MushroomManager::MushroomSpawn(gridPos);
	MarkForDestroy();
}

void Centipede_Head::Destroy()
{
	DeregisterCollision<Centipede_Head>(*this);
}

void Centipede_Head::Delete()
{
	if (next) next->Delete();
	Centipede_Manager::reportDelete();
	DeregisterCollision<Centipede_Head>(*this);
	MarkForDestroy();
}


Centipede_Head::~Centipede_Head()
{
}
