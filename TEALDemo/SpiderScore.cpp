#include "SpiderScore.h"



SpiderScore::SpiderScore()
{
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("SpiderScore"), 1, 3, 16);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / (float)2, MainSprite.getTextureRect().height / (float)2);
	SetDrawOrder(1010);
	MainSprite.setScale(2, 2);
}

void SpiderScore::Initialize(sf::Vector2i pos, int val)
{
	MainSprite.SetAnimation(val, val);
	MainSprite.setPosition((sf::Vector2f)pos);
	SetAlarm(0, 2);
}

void SpiderScore::Alarm0()
{
	MarkForDestroy();
}

void SpiderScore::Draw()
{
	WindowManager::MainWindow.draw(MainSprite);
}


SpiderScore::~SpiderScore()
{
}
