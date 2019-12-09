#include "Color_Manager.h"

Color_Manager* Color_Manager::ptrInstance = nullptr;

void Color_Manager::privInitialize()
{
	Centipede_Head_bmp = ResourceManager::GetTextureBitmap("Master");
	Centipede_Head = AnimatedSprite(ResourceManager::GetTexture("Master"), 28, 77, (16));

	Centipede_Head.SetAnimation(0, 3, true, false);
	Centipede_Head.setOrigin(Centipede_Head.getTextureRect().width / (float)2, Centipede_Head.getTextureRect().height / (float)2);
	Centipede_Head.setScale(2, 2);

	//Centipede_Body_bmp = ResourceManager::GetTextureBitmap("Master");
	Centipede_Body = AnimatedSprite(ResourceManager::GetTexture("Master"), 28, 77, (16));

	Centipede_Body.SetAnimation(56, 59, true, false);
	Centipede_Body.setOrigin(Centipede_Body.getTextureRect().width / (float)2, Centipede_Body.getTextureRect().height / (float)2);
	Centipede_Body.setScale(2, 2);
}

void Color_Manager::privTerminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}

void Color_Manager::privUpdate()
{
	Centipede_Head.Update();
	Centipede_Body.Update();

	if (Centipede_Head.IsLastAnimationFrame())
	{
		if (first_head)
		{
			first_head = false;
		Centipede_Head.SetAnimation(28, 31, true, false);
		}
		else
		{
			first_head = true;
		Centipede_Head.SetAnimation(0, 3, true, false);
		}
	}

	if (Centipede_Body.IsLastAnimationFrame())
	{
		if (first_body)
		{
			first_body = false;
			Centipede_Body.SetAnimation(84, 87, true, false);
		}
		else
		{
			first_body = true;
			Centipede_Body.SetAnimation(56, 59, true, false);
		}
	}
}

AnimatedSprite* Color_Manager::privReturnHead()
{
	return &Centipede_Head;
}

AnimatedSprite* Color_Manager::privReturnBody()
{
	return &Centipede_Body;
}

