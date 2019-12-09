#ifndef _PLAYERDATA
#define _PLAYERDATA

const int MAX_WAVE = 2; //This is Wave_Manager::TOTAL_WAVES - 1
const int MAX_LIVES = 6;
const int NUM_EXTRAS = 4;

struct PlayerData
{
	PlayerData(int n);
	void AddScore(int value);
	int playerNum();
	int getWave();
	int getScore();
	void nextWave();
	bool decLife();
	void addLife();
	int getLives();
	void PlayerReset();
	void extraLife(int life);
	bool checkExtra(int life);
	PlayerData() = default;

private:
	int lives;
	int score;
	int wave;
	int num;
	bool extras[NUM_EXTRAS];
};

#endif
