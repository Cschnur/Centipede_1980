#ifndef _WAVEDATA
#define _WAVEDATA

const int DATA = 12;

struct WaveData
{
public:
	WaveData();
	//Layout of WavaData.txt
	int cenLenD;
	int cenSpeedD;
	int numHeadsD;

	int spiderD;
	int spiderSpawnD;
	int spiderSpeedD;

	int fleaD;
	int fleaTriggerD;
	int fleaSpeedD;

	int scorpionD;
	int scorpionSpawnD;
	int scorpionSpeedD;

	int data[DATA];
	int count;
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

	void SetData(char* key, char* value);
	void SetValues();
	int getValue(int num);

};

#endif // !_WAVEDATA

