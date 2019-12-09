#pragma once
const int MAXLINE = 100;

struct WaveData;

const int TOTAL_WAVES = 3;

class Wave_Manager
{
public:
	static void Initialize() { Instance().privInitialize(); };
	static WaveData* getWaveData(int num) { return Instance().privGetWaveData(num); };
	static void setWave(int num) { Instance().privSetWave(num); };
	static void startWave() { Instance().privStartWave(); };
	void ReadWaveData();

	static void Terminate();

private:
	static Wave_Manager* ptrInstance;

	Wave_Manager() = default;
	Wave_Manager(const Wave_Manager&) = delete;
	Wave_Manager& operator=(const Wave_Manager&) = delete;


	static Wave_Manager& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new Wave_Manager;
		return *ptrInstance;
	};

	char key = '-';
	char skip = '~';
	WaveData* waves[TOTAL_WAVES];
	WaveData* currWave;

	void privInitialize();
	WaveData* privGetWaveData(int num);
	void privSetWave(int num);
	void privStartWave();
};

