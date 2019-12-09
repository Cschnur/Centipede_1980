#ifndef COLOR_MANAGER
#define COLOR_MANAGER

#include "Game Components\TEAL\CommonElements.h"


class Color_Manager
{
public:
	static void Initialize() { Instance().privInitialize(); };
	static void Terminate() { Instance().privTerminate(); };
	static void Update() { Instance().privUpdate(); };

	static AnimatedSprite* ReturnHead() { return Instance().privReturnHead(); };
	static AnimatedSprite* ReturnBody() { return Instance().privReturnBody(); };

protected:
	AnimatedSprite Centipede_Head;
	CollisionTools::TextureBitmap Centipede_Head_bmp;

	AnimatedSprite Centipede_Body;
	CollisionTools::TextureBitmap Centipede_Body_bmp;

private:
	static Color_Manager* ptrInstance;

	Color_Manager() = default;
	Color_Manager(const Color_Manager&) = delete;
	Color_Manager& operator=(const Color_Manager&) = delete;


	static Color_Manager& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new Color_Manager;
		return *ptrInstance;
	};

	bool first_head = true;
	bool first_body = true;

	void privInitialize();
	void privTerminate();
	void privUpdate();
	AnimatedSprite* privReturnHead();
	AnimatedSprite* privReturnBody();
};

#endif COLOR_MANAGER

