#include "Wave_Manager.h"
#include "WaveData.h"
#include "Critter_Manager.h"
#include "Centipede_Manager.h"
#include "MushroomManager.h"
#include "Game Components\TEAL\CommonElements.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

Wave_Manager* Wave_Manager::ptrInstance = nullptr;

void Wave_Manager::privInitialize()
{
	for (int i = 0; i < TOTAL_WAVES; i++)
	{
		waves[i] = new WaveData;
	}
	ReadWaveData();
}

WaveData* Wave_Manager::privGetWaveData(int num)
{
	return waves[num];
}

void Wave_Manager::privSetWave(int num)
{
	currWave = waves[num];
	Critter_Manager::setData(num);
	Centipede_Manager::setData(num);
	privStartWave();
}

void Wave_Manager::privStartWave()
{
	Centipede_Manager::startSpawn();
	Critter_Manager::startSpawn();
	MushroomManager::WaveStart();
}


//Reads Data from WaveData.txt and stores in the WaveData structs
void Wave_Manager::ReadWaveData()
{
	int count = -1;
	bool found = false;
	ifstream waveFile("WaveData.txt");
	char oneline[MAXLINE];
	char* ptr;
	char* ptr2;
	char* next_token = nullptr;
	if (!waveFile.good())
		return;
	while (waveFile)
	{
		if (!found)
		{
			waveFile.getline(oneline, MAXLINE);
			if (oneline[0] == key)
			{
				count++;
				found = true;
			}
		}
		else
		{
			waveFile.getline(oneline, MAXLINE);
			if (oneline[0] == key)
			{
				found = false;
			}
			else if (oneline[0] == skip)
			{
				//nothing
			}
			else {
				ptr = strtok_s(oneline, "=", &next_token);
				ptr2 = strtok_s(NULL, ";", &next_token);
				waves[count]->SetData(ptr, ptr2);
			}
		}
	}
	for (int i = 0; i < TOTAL_WAVES; i++)
	{
		waves[i]->SetValues();
	}
	waveFile.close();
}

void Wave_Manager::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}