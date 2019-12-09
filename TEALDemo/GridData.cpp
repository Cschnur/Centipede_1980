#include "GridData.h"



GridData::GridData()
	:triggerShrooms(0)
{
}

void GridData::SetData(int r, int c)
{
	storedGrid[r][c] = 1;
	if (r >= MushroomManager::TOP_PLAYER_ROW)
	{
		triggerShrooms++;
		//ConsoleMsg::WriteLine("There are " + Tools::ToString(triggerShrooms) + " mushrooms in the player area");
	}
}

void GridData::ClearData(int r, int c)
{
	storedGrid[r][c] = 0;
	if (r >= MushroomManager::TOP_PLAYER_ROW)
	{
		triggerShrooms--;
		//ConsoleMsg::WriteLine("There are " + Tools::ToString(triggerShrooms) + " mushrooms in the player area");
	}
}

int GridData::GetData(int r, int c)
{
	return storedGrid[r][c];
}

int GridData::getTrigger()
{
	return triggerShrooms;
}

void GridData::WipeData()
{
	for (int r = 0; r < MushroomManager::ROW; r++)
	{
		for (int c = 0; c < MushroomManager::COLUMN; c++)
		{
			storedGrid[r][c] = 0;
		}
	}
	triggerShrooms = 0;
}