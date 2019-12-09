#include "Game_Manager.h"
#include "HUD.h"
#include "MushroomManager.h"
#include "Critter_Manager.h"
#include "Centipede_Manager.h"
#include "Player_Manager.h"
#include "Wave_Manager.h"
#include "PlayerData.h"
#include "Score_Manager.h"
#include "Sound_Manager.h"

#include "Color_Manager.h"

#include "Centipede_Menu.h"
#include "Centipede_1Player.h"
#include "Game Components\TEAL\ResourceManager.h"

Game_Manager* Game_Manager::ptrInstance = nullptr;

void Game_Manager::privInitialize(int scene)
{
	active = true;

	Color_Manager::Initialize();
	Critter_Manager::Initialize();
	Centipede_Manager::Initialize();
	Wave_Manager::Initialize();
	Player_Manager::Initialize();
	Score_Manager::Initialize();

	myState = (GameState)scene;
	if (myState == MenuState)
		Menu();
	else if (myState == OnePlayerState)
		OnePlayer();
}

void Game_Manager::Update()
{
	Score_Manager::ProcessScores();

	Color_Manager::Update();

	//Activate 1Player mode
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) && myState == MenuState)
	{
		active = false;
		ClearScreen();
		Player_Manager::CurrentPlayer()->PlayerReset();
		SceneManager::ChangeScene(new Centipede_1Player);
	}
	//force going back to attractor mode
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && myState == OnePlayerState)
	{
		active = false;
		ClearScreen();
		int score = Player_Manager::CurrentPlayer()->getScore();
		Score_Manager::HighScore(score);
		Score_Manager::setLastScore(score);
		Player_Manager::CurrentPlayer()->PlayerReset();
		SceneManager::ChangeScene(new Centipede_Menu);
	}
}

void Game_Manager::Menu()
{
	Sound_Manager::SetVolume(OFF);
	Player_Manager::setPlayer(PLAYER_AI);
	HUD::MenuIntialize();
	MushroomManager::Initialize();
	Player_Manager::spawnPlayer();
}

void Game_Manager::privScoreUpdate(int val)
{
	if (myState == MenuState) return;
	if (Player_Manager::CurrentPlayer()->playerNum() == PLAYER_ONE)
	{
		HUD::Player1UpdateScore(val);
		if (val > LIFE_FOUR)
		{
			if (Player_Manager::CurrentPlayer()->checkExtra(3))
			{
				Player_Manager::CurrentPlayer()->extraLife(3);
				Player_Manager::CurrentPlayer()->addLife();
				HUD::Player1LifeUpdate(Player_Manager::CurrentPlayer()->getLives());
			}
		}
		else if (val > LIFE_THREE)
		{
			if (Player_Manager::CurrentPlayer()->checkExtra(2))
			{
				Player_Manager::CurrentPlayer()->extraLife(2);
				Player_Manager::CurrentPlayer()->addLife();
				HUD::Player1LifeUpdate(Player_Manager::CurrentPlayer()->getLives());
			}
		}
		else if (val > LIFE_TWO)
		{
			if (Player_Manager::CurrentPlayer()->checkExtra(1))
			{
				Player_Manager::CurrentPlayer()->extraLife(1);
				Player_Manager::CurrentPlayer()->addLife();
				HUD::Player1LifeUpdate(Player_Manager::CurrentPlayer()->getLives());
			}
		}
		else if (val > LIFE_ONE)
		{
			if (Player_Manager::CurrentPlayer()->checkExtra(0))
			{
				Player_Manager::CurrentPlayer()->extraLife(0);
				Player_Manager::CurrentPlayer()->addLife();
				HUD::Player1LifeUpdate(Player_Manager::CurrentPlayer()->getLives());
			}
		}
	}
	if (Player_Manager::CurrentPlayer()->playerNum() == PLAYER_TWO)
	{
		//Fix this
		//Update score for player 2 here
		//HUD::Player2UpdateScore(val);
	}
}

void Game_Manager::OnePlayer()
{
	Sound_Manager::SetVolume(ON);

	MushroomManager::SwitchGrids(PLAYER_ONE);

	//Set the player and wavedata
	Player_Manager::setPlayer(PLAYER_ONE);
	Player_Manager::CurrentPlayer()->decLife();
	HUD::Player1Initialize();

	//Spawn the Player
	Player_Manager::spawnPlayer();
}

void Game_Manager::TwoPlayer()
{
	Player_Manager::setPlayer(PLAYER_ONE);
}

void Game_Manager::privPlayerDeath()
{
	ClearScreen();
	MushroomManager::FieldRegen(); //This comes back to privRegenComplete()
}

void Game_Manager::privRegenComplete()
{
	if (myState == MenuState)
	{
		Player_Manager::spawnPlayer();
		Wave_Manager::startWave();
	}
	else
	{
		bool gameover = Player_Manager::CurrentPlayer()->decLife();
		if (gameover)
		{
			int score = Player_Manager::CurrentPlayer()->getScore();
			Score_Manager::HighScore(score);
			Score_Manager::setLastScore(score);
			Player_Manager::CurrentPlayer()->PlayerReset();
			SceneManager::ChangeScene(new Centipede_Menu);
		}
		else
		{
			Player_Manager::spawnPlayer();
			Wave_Manager::startWave();
		}
	}
}

void Game_Manager::privWaveClear()
{
	ConsoleMsg::WriteLine("Wave Advance");
	Player_Manager::playerAdvance();
}

void Game_Manager::ClearScreen() //Just wraps the two calls into one call
{
	Centipede_Manager::clearScreen();
	Critter_Manager::clearScreen();
}

void Game_Manager::Terminate()
{
	Color_Manager::Terminate();

	ptrInstance->MarkForDestroy();
	ptrInstance = nullptr;
}
