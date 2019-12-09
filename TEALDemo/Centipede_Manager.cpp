#include "Centipede_Manager.h"
#include "Centipede_Factory.h"
#include "MushroomManager.h"
#include "MoveFSM.h"
#include "MoveState.h"
#include "Sound_Manager.h"
#include "Centipede.h"
#include "Wave_Manager.h"
#include "WaveData.h"
#include "Game_Manager.h"

Centipede_Manager* Centipede_Manager::ptrInstance = NULL;

void Centipede_Manager::privInitialize()
{
	cenLenV = 0;
	cenSpeedV = 0;
	numHeadsV = 0;

	mainSpawn = sf::Vector2i(216, 8);
	headSpawns[0] = sf::Vector2i(136, 8);
	headSpawns[1] = sf::Vector2i(296, 8);

	currCentipedes = 0;
	topState = &MoveFSM::StateTurnDownSwitchToRight;
}

void Centipede_Manager::privSetData(int num)
{
	currWave = Wave_Manager::getWaveData(num);
	for (int i = 0; i < CEN_DATA; i++)
	{
		waveData[i] = currWave->getValue(i);
	}
	cenLenV = waveData[cenLen];
	cenSpeedV = waveData[cenSpeed];
	numHeadsV = waveData[numHeads];

}

void Centipede_Manager::privStartSpawn()
{
	currCentipedes = 0;
	//ConsoleMsg::WriteLine("Wave Reset -- Current Centipedes: " + Tools::ToString(currCentipedes));
	Sound_Manager::playCentipede();
	Centipede_Head* ch = Centipede_Factory::CreateCentipede_Head(mainSpawn, topState, nullptr, cenLenV, 0, cenSpeedV);
	spawnedCentipedes.push((Centipede*)ch);
	currCentipedes++;

	if (numHeadsV > 0)
	{
		for (int i = 0; i < numHeadsV; i++)
		{
			Centipede_Head* ch = Centipede_Factory::CreateCentipede_Head(headSpawns[i], topState, nullptr, 0, 0, cenSpeedV);
			spawnedCentipedes.push((Centipede*)ch);
			currCentipedes++;
		}
	}
}

void Centipede_Manager::privReportDeath()
{
	currCentipedes--;
	if (currCentipedes == 0)
	{
		Sound_Manager::stopCentipede();
		Game_Manager::WaveClear();
	}
	//ConsoleMsg::WriteLine("Current Centipedes: " + Tools::ToString(currCentipedes));
}

void Centipede_Manager::privReportDelete()
{
	currCentipedes--;
	if (currCentipedes == 0)
	{
		Sound_Manager::stopCentipede();
	}
}

void Centipede_Manager::privReportSpawn()
{
	currCentipedes++;
}

void Centipede_Manager::privReportSplit(Centipede_Head* ch)
{
	spawnedCentipedes.push((Centipede*)ch);
}

void Centipede_Manager::privClearScreen()
{
	while (!spawnedCentipedes.empty())
	{
		spawnedCentipedes.top()->Delete();
		spawnedCentipedes.pop();
	}
}

void Centipede_Manager::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}

Centipede_Manager::~Centipede_Manager()
{
	while (!spawnedCentipedes.empty())
	{
		spawnedCentipedes.pop();
	}
}
