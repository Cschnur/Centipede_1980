#include "Player_Manager.h"
#include "PlayerData.h"
#include "Ship_Factory.h"
#include "BlasterKB.h"
#include "BlasterAI.h"
#include "Critter_Manager.h"
#include "Centipede_Manager.h"
#include "Wave_Manager.h"
#include "Game_Manager.h"
#include "HUD.h"

PlayerData Player_Manager::Player1 = PlayerData(1);
PlayerData Player_Manager::Player2 = PlayerData(2);
PlayerData Player_Manager::PlayerAi = PlayerData(0);
PlayerData* Player_Manager::players[NUM_PLAYERS] = { &PlayerAi, &Player1, &Player2 };
PlayerData* Player_Manager::currPlayer = players[0];

Player_Manager* Player_Manager::ptrInstance = NULL;

void Player_Manager::privInitialize()
{
}

PlayerData* Player_Manager::CurrentPlayer()
{
	return currPlayer;
}

void Player_Manager::setPlayer(int num)
{
	currPlayer = players[num];
	Wave_Manager::setWave(currPlayer->getWave());
}

void Player_Manager::privPlayerAdvance()
{
	currPlayer->nextWave();
	Wave_Manager::setWave(currPlayer->getWave());
}

void Player_Manager::privSpawnPlayer()
{
	if (currPlayer->playerNum() == 0) AiPtr = Ship_Factory::CreateShipAI();
	else if (currPlayer->playerNum() == 1)
	{
		Ship_Factory::CreateShipKB();
		HUD::Player1LifeUpdate(currPlayer->getLives());
	}
	else if (currPlayer->playerNum() == 2)
	{
		Ship_Factory::CreateShipKB();
		HUD::Player1LifeUpdate(currPlayer->getLives());
	}
	else return;
}

void Player_Manager::privPlayerDelete()
{
	if (currPlayer->playerNum() == 0) AiPtr->Delete();
}

void Player_Manager::privReportDeath()
{
	Game_Manager::PlayerDeath();
}

void Player_Manager::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}
