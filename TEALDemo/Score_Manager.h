#ifndef _SCORE_MANAGER
#define _SCORE_MANAGER

#include <stack>

class CmdScore;
class CmdScoreByDistance;

const int NUM_SCORES = 7;

class Score_Manager
{
private:
	static const int FleaDeath = 200;
	static const int ScorpionDeath = 1000;

	static const int MushroomDeath = 1;
	static const int MushroomPoisonDeath = 5;
	static const int MushroomRegen = 5;

	static const int CentipedeHeadDeath = 100;
	static const int CentipedeBodyDeath = 10;

	static const int SpiderDeathFar = 300;
	static const int SpiderDistFar = 9999;

	static const int SpiderDeathMedium = 600;
	static const int SpiderDistMedium = 99;

	static const int SpiderDeathNear = 900;
	static const int SpiderDistNear = 9;

	std::stack<CmdScore*> StackCmd;

	static Score_Manager* ptrInstance;

	static Score_Manager& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new Score_Manager;
		return *ptrInstance;
	};

	static int HIGH_SCORE;
	static std::string HIGH_INITIALS;
	static const std::string PLAYER_INITIALS;

	static int LAST_SCORE;


	static int SCORES[NUM_SCORES];
	static std::string initials[NUM_SCORES];

	void privProcessScore();

	void privHighScore(int score);
	int privGetHighScore();

	void privHighScoreList(int score, int first, int start);
	int privGetHighScoreList(int index);
	std::string privGetHighScoreInitials();
	std::string privGetHighScoreListInitials(int index);

	void privInitialize();

	void privSetLastScore(int score);
	int privGetLastScore();


public:
	enum class ScoreEvents { FleaKilled, ScorpionKilled, MushroomKilled, MushroomPoisonKilled, MushroomRegen, CentipedeHeadKilled, CentipedeBodyKilled};
	enum class ScoreDistanceEvents { SpiderKilledNear, SpiderKilledMed, SpiderKilledFar };

	static void AddScore(int val);

	static CmdScore* GetScoreCommand(ScoreEvents ev);
	static CmdScoreByDistance* GetScoreCommand(ScoreDistanceEvents ev);

	static void SendScoreCmd(CmdScore* c);
	static void SendScoreDistanceCmd(CmdScoreByDistance* c);
	static void ProcessScores();

	static void HighScore(int score) { Instance().privHighScore(score); };
	static int getHighScore() { return Instance().privGetHighScore(); };

	static void HighScoreList(int score, int first, int start) { Instance().privHighScoreList(score, first, start); };
	static int getHighScoreList(int index) { return Instance().privGetHighScoreList(index); };

	static std::string getHighScoreInitials() { return Instance().privGetHighScoreInitials(); };
	static std::string getHighScoreListInitials(int index) { return Instance().privGetHighScoreListInitials(index); };

	static void setLastScore(int score) { Instance().privSetLastScore(score); };
	static int getLastScore() {return Instance().privGetLastScore(); };

	static void Initialize() { Instance().privInitialize(); };

	static void Terminate();
};

#endif _SCORE_MANAGER
