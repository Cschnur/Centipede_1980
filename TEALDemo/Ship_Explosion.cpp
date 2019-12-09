#include "Ship_Explosion.h"
#include "Sound_Manager.h"
#include "Game Components\GameController.h"


Ship_Explosion::Ship_Explosion()
{
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("deathPNG"), 4, 2, 16);
	MainSprite.scale(1, 1);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
}

void Ship_Explosion::Initialize(sf::Vector2i pos)
{
	MainSprite.SetAnimation(0, 7, true, false);
	MainSprite.setPosition(sf::Vector2f(pos));
	Sound_Manager::playShipDeath();
}

void Ship_Explosion::Update()
{
	if (MainSprite.IsLastAnimationFrame())
	{
		MarkForDestroy();
	}

	MainSprite.Update();
}
void Ship_Explosion::Draw()
{
	WindowManager::MainWindow.draw(MainSprite);
}

Ship_Explosion::~Ship_Explosion()
{
}
