#include "PlayerData.h"
#include "Game Components\TEAL\CommonElements.h"
#include "Game_Manager.h"
#include "HUD.h"
#include "Score_Manager.h"

PlayerData::PlayerData(int n)
	:lives(3), score(0), wave(0), num(n)
{
	for (int i = 0; i < NUM_EXTRAS; i++)
	{
		extras[i] = true;
	}
}

void PlayerData::AddScore(int value)
{
	score += value;
	Game_Manager::ScoreUpdate(score);
}

int PlayerData::getScore()
{
	return score;
}

void PlayerData::extraLife(int life)
{
	extras[life] = false;
}

bool PlayerData::checkExtra(int life)
{
	return extras[life];
}

int PlayerData::playerNum()
{
	return num;
}

int PlayerData::getWave()
{
	return wave;
}

void PlayerData::nextWave()
{
	if(wave != MAX_WAVE) wave++;
}

bool PlayerData::decLife()
{
	if (lives == 0) return true;
	lives--;
	return false;
}

void PlayerData::addLife()
{
	if (lives == MAX_LIVES) return;
	lives++;
}

int PlayerData::getLives()
{
	return lives;
}

void PlayerData::PlayerReset()
{
	lives = 3;
	wave = 0;
	score = 0;
	for (int i = 0; i < NUM_EXTRAS; i++)
	{
		extras[i] = true;
	}
}