#ifndef _CENTIPEDE_MANAGER
#define _CENTIPEDE_MANAGER

#include "Game Components\TEAL\CommonElements.h"
#include <stack>

class MushroomManager;
class Centipede_Head;
class Centipede;
class MoveState;
struct WaveData;

const int CEN_DATA = 3; //Amount of data for the centipede
const int MAX_HEADS = 2; //Max amount of single heads to start with

class Centipede_Manager
{
public:
	static void Initialize() { Instance().privInitialize(); };
	static void reportDeath() { Instance().privReportDeath(); };
	static void reportDelete() { Instance().privReportDelete(); };
	static void reportSpawn() { Instance().privReportSpawn(); };
	static void reportSplit(Centipede_Head* ch) { Instance().privReportSplit(ch); };
	static void clearScreen() { Instance().privClearScreen(); };
	static void setData(int num) { Instance().privSetData(num); };

	static void startSpawn() { Instance().privStartSpawn(); };

	static void Terminate();

private:

	static Centipede_Manager* ptrInstance;

	Centipede_Manager() = default;
	Centipede_Manager(const Centipede_Manager&) = delete;
	Centipede_Manager& operator=(const Centipede_Manager&) = delete;
	~Centipede_Manager();

	static Centipede_Manager& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new Centipede_Manager;
		return *ptrInstance;
	};

	std::stack<Centipede*> spawnedCentipedes;

	const MoveState* topState;
	int currCentipedes;

	void privInitialize();
	void privReportDeath();
	void privReportDelete();
	void privReportSpawn();
	void privReportSplit(Centipede_Head* ch);
	void privClearScreen();
	void privSetData(int num);
	void privStartSpawn();

	int cenLenV;
	int cenSpeedV;
	int numHeadsV;

	WaveData* currWave;
	int waveData[CEN_DATA];

	sf::Vector2i mainSpawn;
	sf::Vector2i headSpawns[MAX_HEADS];

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
