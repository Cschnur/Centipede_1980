#include "Score_Manager.h"

#include <iostream>
#include "CmdScore.h"
#include "CmdScoreByDistance.h"
#include "Game Components\TEAL\CommonElements.h"
#include "Player_Manager.h"
#include "PlayerData.h"
#include "HUD.h"

const std::string Score_Manager::PLAYER_INITIALS = "YOU"; //Initials for the players HighScore

int Score_Manager::LAST_SCORE = 0; //Player 1's previous score, shows in attractor mode

int Score_Manager::HIGH_SCORE = 16543; //This is the starting default high score
std::string Score_Manager::HIGH_INITIALS = "EJD"; // Default High Score Initials

int Score_Manager::SCORES[NUM_SCORES] = {15432, 14320, 13210, 13010, 12805, 12201, 12102}; //Default High Scores
std::string Score_Manager::initials[NUM_SCORES] = {"DFT", "CAD", "DCB", "EDD", "DEW", "DFW", "GJR"}; //Default Initials for High Scores

Score_Manager* Score_Manager::ptrInstance = NULL;

void Score_Manager::privInitialize()
{
	//nothing
}

CmdScore* Score_Manager::GetScoreCommand(ScoreEvents ev)
{
	CmdScore* pCmd = nullptr;
	//printf("Score Manager: Constructing score command for ");

	switch (ev)
	{
	case ScoreEvents::FleaKilled:
		pCmd = new CmdScore(FleaDeath);
		break;
	case ScoreEvents::ScorpionKilled:
		pCmd = new CmdScore(ScorpionDeath);
		break;
	case ScoreEvents::MushroomKilled:
		pCmd = new CmdScore(MushroomDeath);
		break;
	case ScoreEvents::MushroomPoisonKilled:
		pCmd = new CmdScore(MushroomPoisonDeath);
		break;
	case ScoreEvents::MushroomRegen:
		pCmd = new CmdScore(MushroomRegen);
		break;
	case ScoreEvents::CentipedeHeadKilled:
		pCmd = new CmdScore(CentipedeHeadDeath);
		break;
	case ScoreEvents::CentipedeBodyKilled:
		pCmd = new CmdScore(CentipedeBodyDeath);
		break;
	default:
		break;
	}

	return pCmd;
}

void Score_Manager::AddScore(int val)
{
	Player_Manager::CurrentPlayer()->AddScore(val);
}

void Score_Manager::SendScoreCmd(CmdScore* c)
{
	Instance().StackCmd.push(c);
}

void Score_Manager::SendScoreDistanceCmd(CmdScoreByDistance* c)
{
	Instance().StackCmd.push(c);
}

void Score_Manager::ProcessScores()
{
	Instance().privProcessScore();
}

void Score_Manager::privProcessScore()
{
	CmdScore* c;

	while (!StackCmd.empty())
	{
		c = StackCmd.top();
		c->Execute();

		StackCmd.pop();
	}
}

CmdScoreByDistance* Score_Manager::GetScoreCommand(ScoreDistanceEvents ev)
{
	CmdScoreByDistance* pCmd = nullptr;
	printf("Score Manager: Constructing score by distance command for ");

	switch (ev)
	{
	case ScoreDistanceEvents::SpiderKilledNear:
		printf("SpiderDeathNear\n");
		pCmd = new CmdScoreByDistance(SpiderDeathNear, SpiderDistNear);
		break;
	case ScoreDistanceEvents::SpiderKilledMed:
		printf("SpiderDeathMedium\n");
		pCmd = new CmdScoreByDistance(SpiderDeathMedium, SpiderDistMedium);
		break;
	case ScoreDistanceEvents::SpiderKilledFar:
		printf("SpiderDeathFar\n");
		pCmd = new CmdScoreByDistance(SpiderDeathFar, SpiderDistFar);
		break;
	default:
		printf("<nothing>\n");
		break;
	}

	return pCmd;
}

void Score_Manager::privHighScore(int score)
{
	if (score > HIGH_SCORE)
	{
		privHighScoreList(HIGH_SCORE, 1, 0);
		HIGH_SCORE = score;
		HIGH_INITIALS = PLAYER_INITIALS;
	}
	else
		privHighScoreList(score, 1,  0);
}

int Score_Manager::privGetHighScore()
{
	return HIGH_SCORE;
}
//Search down the list of scores and find where you fit
void Score_Manager::privHighScoreList(int score, int first, int start)
{
	int tmpS = 0;
	for (int i = start; i < NUM_SCORES; i++)
	{
		if (score > SCORES[i])
		{
			tmpS = SCORES[i]; //save score you replace
			SCORES[i] = score;

			if (first == 1)
				initials[i] = PLAYER_INITIALS;

			//move down the list again with score you replaced, starting where you stoppped
			privHighScoreList(tmpS, 0, i);
			break;
		}
	}
}

int Score_Manager::privGetHighScoreList(int index)
{
	return SCORES[index];
}

std::string Score_Manager::privGetHighScoreInitials()
{
	return HIGH_INITIALS;
}

std::string Score_Manager::privGetHighScoreListInitials(int index)
{
	return initials[index];
}

void Score_Manager::privSetLastScore(int score)
{
	LAST_SCORE = score;
}

int Score_Manager::privGetLastScore()
{
	return LAST_SCORE;
}

void Score_Manager::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}