#ifndef _PLAYER_MANAGER
#define _PLAYER_MANAGER
#include "Game Components\TEAL\CommonElements.h"

struct PlayerData;
class BlasterKB;
class BlasterAI;

const int NUM_PLAYERS = 3;

class Player_Manager
{
public:
	static PlayerData* CurrentPlayer();

	//static functions
	static void setPlayer(int num);
	static void Initialize() { Instance().privInitialize(); };
	static void spawnPlayer() { Instance().privSpawnPlayer(); };
	static void reportDeath() { Instance().privReportDeath(); };
	static void playerDelete() { Instance().privPlayerDelete(); };
	static void playerAdvance() { Instance().privPlayerAdvance(); };

	static void Terminate();
private:
	Player_Manager() = default;
	static Player_Manager* ptrInstance;
	Player_Manager(const Player_Manager&) = delete;
	Player_Manager& operator=(const Player_Manager&) = delete;

	static Player_Manager& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new Player_Manager;
		return *ptrInstance;
	};


	BlasterKB *playerPtr;
	BlasterAI *AiPtr;

	static PlayerData Player1;
	static PlayerData Player2;
	static PlayerData PlayerAi;
	static PlayerData* players[NUM_PLAYERS];
	static PlayerData* currPlayer;

	void privInitialize();
	void privSpawnPlayer();
	void privReportDeath();
	void privPlayerDelete();
	void privPlayerAdvance();
};

#endif _PLAYER_MANAGER
