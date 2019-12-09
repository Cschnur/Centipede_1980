#ifndef _CRITTER_MANAGER
#define _CRITTER_MANAGER

#include "Game Components\TEAL\CommonElements.h"
#include <stack>

class MushroomManager;
class Critter;
struct WaveData;

const int CR_DATA = 12; //Amount of data for the critters

class Critter_Manager : public GameObject
{
public:
	static void Initialize() { Instance().privInitialize(); };
	static void clearScreen() { Instance().privClearScreen(); };
	static void setData(int num) { Instance().privSetData(num); };
	static void startSpawn() { Instance().privStartSpawn(); };


	static void FleaUpdate(bool respawn) { Instance().privFleaUpdate(respawn); };
	static void FleaTrigger(int val) { Instance().privFleaTrigger(val); };

	static void ScorpionUpdate() { Instance().privScorpionUpdate(); };
	static void SpiderUpdate() { Instance().privSpiderUpdate(); };

	void SpawnFlea();
	virtual void Alarm1();
	virtual void Alarm2();

	static void Terminate();

private:
	static Critter_Manager* ptrInstance;

	Critter_Manager() = default;
	Critter_Manager(const Critter_Manager&) = delete;
	Critter_Manager& operator=(const Critter_Manager&) = delete;
	~Critter_Manager();

	static Critter_Manager& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new Critter_Manager;
		return *ptrInstance;
	};

	std::stack<Critter*> spawnedCritters;
	WaveData* currWave;

	void privFleaUpdate(bool respawn);
	void privFleaTrigger(int val);
	bool fleaSpawned;

	void privScorpionUpdate();
	void privSpiderUpdate();


	int currScorpion;
	int currSpider;

	int waveData[CR_DATA];

	//Spider Values
	bool spiderV;
	int spiderSpawnRateV;
	int spiderSpeedV;

	//Flea Values
	bool fleaV;
	int fleaTriggerV;
	int fleaSpeedV;

	//Scorpion Values
	bool scorpionV;
	int scorpionSpawnRateV;
	int scorpionSpeedV;

	void privInitialize();
	void privClearScreen();
	void privSetData(int num);
	void privStartSpawn();

	enum Keys
	{
		cenLen = 0,
		cenSpeed,
		numHeads,
		spider,
		spiderSpawn,
		spiderSpeed,
		flea,
		fleaTrigger,
		fleaSpeed,
		scorpion,
		scorpionSpawn,
		scorpionSpeed
	};
};

#endif

