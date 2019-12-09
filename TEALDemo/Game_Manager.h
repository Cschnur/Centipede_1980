#ifndef _GAME_MANAGER
#define _GAME_MANAGER

#include "Game Components\TEAL\CommonElements.h"

class HUD;
class MushroomManager;

const float OFF = 0.0f;
const float ON = 5.0f;

const int PLAYER_AI = 0;
const int PLAYER_ONE = 1;
const int PLAYER_TWO = 2;

const int LIFE_ONE = 10000; //Scores needed for extra lives
const int LIFE_TWO = 12000;
const int LIFE_THREE = 15000;
const int LIFE_FOUR = 20000;

class Game_Manager : public GameObject
{
public:
	static void Initialize(int scene) { Instance().privInitialize(scene); };
	static void PlayerDeath() { Instance().privPlayerDeath(); };
	static void RegenComplete() { Instance().privRegenComplete(); };
	static void WaveClear() { Instance().privWaveClear(); };
	static void ScoreUpdate(int val) { Instance().privScoreUpdate(val); };
	void OnePlayer();
	void TwoPlayer();
	void Menu();

	static void Terminate();

	void Update();

private:

	static Game_Manager* ptrInstance;

	Game_Manager() = default;
	Game_Manager(const Game_Manager&) = delete;
	Game_Manager& operator=(const Game_Manager&) = delete;


	static Game_Manager& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new Game_Manager;
		return *ptrInstance;
	};

	enum GameState
	{
		MenuState,
		OnePlayerState,
		TwoPlayerState
	};
	GameState myState;

	void privInitialize(int scene);
	void privPlayerDeath();
	void privRegenComplete();
	void ClearScreen();
	void privWaveClear();
	void privScoreUpdate(int val);

	bool active;
	
};

#endif _GAME_MANAGER

