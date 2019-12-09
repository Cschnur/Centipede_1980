#ifndef _GRIDDATA
#define _GRIDDATA

#include "MushroomManager.h"

class MushroomManager;

struct GridData
{
public:
	GridData();
	void SetData(int r, int c);
	void ClearData(int r, int c);
	int GetData(int r, int c);
	int getTrigger();
	void WipeData();

private:
	int storedGrid[MushroomManager::ROW][MushroomManager::COLUMN] = {};
	int triggerShrooms;
};

#endif