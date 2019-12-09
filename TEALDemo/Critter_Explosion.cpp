#include "Critter_Explosion.h"
#include "Sound_Manager.h"
#include "Game Components\GameController.h"


Critter_Explosion::Critter_Explosion()
{
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("spawn"), 3, 2, 16);
	MainSprite.scale(2, 2);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	SetDrawOrder(1005);
}

void Critter_Explosion::Initialize(sf::Vector2i pos)
{
	MainSprite.setPosition(sf::Vector2f(pos));
	MainSprite.SetAnimation(0, 5, true, false);
	Sound_Manager::playCritterDeath();
}

void Critter_Explosion::Update()
{
	if (MainSprite.IsLastAnimationFrame())
	{
		MarkForDestroy();
	}

	MainSprite.Update();
}
void Critter_Explosion::Draw()
{
	WindowManager::MainWindow.draw(MainSprite);
}

Critter_Explosion::~Critter_Explosion()
{
}
