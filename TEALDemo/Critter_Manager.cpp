
#include "Critter_Manager.h"
#include "Flea_Factory.h"
#include "Scorpion.h"
#include "MushroomManager.h"
#include "Scorpion_Factory.h"
#include "Spider_Factory.h"
#include "Sound_Manager.h"
#include "Critter.h"
#include "Wave_Manager.h"
#include "WaveData.h"
#include "GridData.h"

Critter_Manager* Critter_Manager::ptrInstance = nullptr;

void Critter_Manager::privInitialize()
{
	currScorpion = 0;
	currSpider = 0;
	RegisterInput(InputFlags::KeyPressed);
}

void Critter_Manager::privSetData(int num)
{
	currWave = Wave_Manager::getWaveData(num);
	for (int i = 3; i < CR_DATA; i++)
	{
		waveData[i] = currWave->getValue(i);
	}

	spiderV = waveData[spider];
	spiderSpawnRateV = waveData[spiderSpawn];
	spiderSpeedV = waveData[spiderSpeed];

	fleaV = waveData[flea];
	fleaSpeedV = waveData[fleaSpeed];
	fleaTriggerV = waveData[fleaTrigger];
	fleaSpawned = false;

	scorpionV = waveData[scorpion];
	scorpionSpawnRateV = waveData[scorpionSpawn];
	scorpionSpeedV = waveData[scorpionSpeed];

}

void Critter_Manager::privStartSpawn()
{
	float tmp = float(rand() % spiderSpawnRateV + 2);
	if(spiderV) SetAlarm(2, tmp);
	tmp = float(rand() % scorpionSpawnRateV + 2);
	if(scorpionV) SetAlarm(1, tmp);
}

void Critter_Manager::SpawnFlea()
{
	Sound_Manager::playFlea();
	Flea *f = Flea_Factory::CreateFlea(fleaSpeedV);
	spawnedCritters.push((Critter*)f);
}

void Critter_Manager::Alarm1()
{
	Scorpion *s = Scorpion_Factory::CreateScorpion(scorpionSpeedV);
	spawnedCritters.push((Critter*)s);
	if (currScorpion == 0)
	{
		Sound_Manager::playScorpion();
	}
	currScorpion++;
}
void Critter_Manager::Alarm2()
{
	Spider *sp = Spider_Factory::CreateSpider(spiderSpeedV);
	spawnedCritters.push((Critter*)sp);
	if (currSpider == 0)
	{
		Sound_Manager::playSpider();
	}
	currSpider++;
}

void Critter_Manager::privFleaTrigger(int val)
{
	if (fleaV == true)
	{
		if (val <= fleaTriggerV && !fleaSpawned)
		{
 			SpawnFlea();
			fleaSpawned = true;
		}
	}
}

void Critter_Manager::privFleaUpdate(bool respawn)
{
	Sound_Manager::stopFlea();
	if (respawn)
	{
		int tmp = MushroomManager::GetGrid()->getTrigger();
		if (tmp <= fleaTriggerV)
			SpawnFlea();
		else
			fleaSpawned = false;
	}
	else
		fleaSpawned = false;
}

void Critter_Manager::privSpiderUpdate()
{
	currSpider--;
	float tmp = float(rand() % spiderSpawnRateV + 2);
	SetAlarm(2, tmp);
	if (currSpider == 0)
	{
		Sound_Manager::stopSpider();
	}
}

void Critter_Manager::privScorpionUpdate()
{
	currScorpion--;
	float tmp = float(rand() % scorpionSpawnRateV + 2);
	SetAlarm(1, tmp);
	if (currScorpion == 0)
	{
		Sound_Manager::stopScorpion();
	}
}

void Critter_Manager::privClearScreen()
{
	while (!spawnedCritters.empty())
	{
		spawnedCritters.top()->Delete();
		spawnedCritters.pop();
	}
	AlarmCancel(1);
	AlarmCancel(2);
}

void Critter_Manager::Terminate()
{
	// This may no longer be nessecary
	//ptrInstance->MarkForDestroy();
}

Critter_Manager::~Critter_Manager()
{
	ptrInstance = nullptr;
	DeregisterInput();
	spawnedCritters.empty();
	ConsoleMsg::WriteLine("Critters delete");
}
