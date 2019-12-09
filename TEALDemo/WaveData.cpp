#include "WaveData.h"
#include "Game Components\TEAL\CommonElements.h"
#include <stdlib.h>


WaveData::WaveData()
	:count(0)
{
}

void WaveData::SetData(char* key, char* value)
{
	int a = atoi(value);
	data[count] = a;
	count++;
}

void WaveData::SetValues()
{
	cenLenD = data[cenLen];
	cenSpeedD = data[cenSpeed];
	numHeadsD = data[numHeads];

	spiderD = data[spider];
	spiderSpawnD = data[spiderSpawn];
	spiderSpeedD = data[spiderSpeed];

	fleaD = data[flea];
	fleaTriggerD = data[fleaTrigger];
	fleaSpeedD = data[fleaSpeed];

	scorpionD = data[scorpion];
	scorpionSpawnD = data[scorpionSpawn];
	scorpionSpeedD = data[scorpionSpeed];
}

int WaveData::getValue(int num)
{
	return data[num];
}