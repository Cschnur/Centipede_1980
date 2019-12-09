#include "MushroomManager.h"
#include "Mushroom_Factory.h"
#include "Block_Factory.h"
#include "Critter_Manager.h"
#include "Mushroom.h"
#include "Block.h"
#include "GridObject.h"
#include "Player_Manager.h"
#include "Game_Manager.h"
#include "PlayerData.h"
#include "GridData.h"

GridData MushroomManager::AiGrid = GridData();
GridData MushroomManager::Player1Grid = GridData();
GridData MushroomManager::Player2Grid = GridData();
GridData* MushroomManager::grids[NUM_GRIDS] = { &AiGrid, &Player1Grid, &Player2Grid };
GridData* MushroomManager::currGrid = grids[0];

MushroomManager* MushroomManager::ptrInstance = NULL;

void MushroomManager::privInitialize()
{
	GridStart();
}

void MushroomManager::privReportBlock(sf::Vector2i gridPos)
{
	sf::Vector2i tmpV = PosConverter(gridPos.x, gridPos.y);
	Block* tmp = Block_Factory::CreateBlock(tmpV);
	fieldArray[gridPos.x][gridPos.y] = (Mushroom*)(tmp);
}

//Fills the grid with mushrooms at random locations
void MushroomManager::GridStart()
{
	sf::Vector2i spawn1;
	sf::Vector2i spawn2;
	int rand1;
	int rand2;
	for (int r = 2; r <= ROW - 3; r++)
	{
		rand1 = rand() % 30;
		rand2 = rand() % 30;
		while (rand1 == rand2)
		{
			rand2 = rand() % 30;
		}
		spawn1 = sf::Vector2i(r, rand1);
		spawn2 = sf::Vector2i(r, rand2);
		privMushroomSpawn(spawn1);
		privMushroomSpawn(spawn2);

	}
	bool check = true;
}

void MushroomManager::privWaveStart()
{
	Critter_Manager::FleaTrigger(currGrid->getTrigger());
}

//Prints locations of all current mushrooms
void MushroomManager::GridPrint()
{
	for (int r = 0; r < ROW; r++)
	{
		for (int c = 0; c < COLUMN; c++)
		{
			if (fieldArray[r][c]) ConsoleMsg::WriteLine("Mushroom at Row:" + Tools::ToString(r) + " Column:" + Tools::ToString(c));
		}
	}
	ConsoleMsg::WriteLine("Print Finished");
}

//Stores the pointer to a spawned mushroom
void MushroomManager::GridUpdate(int r, int c, Mushroom* spawn)
{
	fieldArray[r][c] = spawn;
}

//Given a mushrooms position, it finds it within the array and removes the pointer, i.e. removes mushroom from grid
void MushroomManager::privGridDelete(sf::Vector2i pos)
{
	int x = pos.x;
	int y = pos.y;
	sf::Vector2i gridPos = GridConverter(x, y);

	int r = gridPos.x;
	int c = gridPos.y;

	fieldArray[r][c] = nullptr;

	currGrid->ClearData(r, c);
	Critter_Manager::FleaTrigger(currGrid->getTrigger());
}

//Destroys a mushroom from the grid
void MushroomManager::privDestroyMushroom(sf::Vector2i gridPos)
{
	if (!fieldArray[gridPos.x][gridPos.y]) return;
	fieldArray[gridPos.x][gridPos.y]->healthUpdate(1);


	//currGrid->ClearData(gridPos.x, gridPos.y);
	//Critter_Manager::FleaTrigger(currGrid->getTrigger());
}

//Converts from x,y window coordinates to relative row and column
sf::Vector2i MushroomManager::GridConverter(int x, int y)
{
	int c = (x-8) / 16;
	int r = (y-8) / 16;
	return sf::Vector2i(r, c);
}

//Converts a row column into the proper x,y coordinates in the window
sf::Vector2i MushroomManager::PosConverter(int r, int c)
{
	int x = (c * 16) + 8;
	int y = (r * 16) + 8;
	return sf::Vector2i(x, y);
}

//Spawns a mushroom at a given position and calls for it to be added to the array
void MushroomManager::privMushroomSpawn(sf::Vector2i gridPos)
{
	if (gridPos.x < TOP_MUSHROOM_ROW) return;

	sf::Vector2i pos = PosConverter(gridPos.x, gridPos.y);

	if (fieldArray[gridPos.x][gridPos.y]) return; //exit if mushroom is already present

	Mushroom* spawn = Mushroom_Factory::CreateMushroom(pos);
	GridUpdate(gridPos.x, gridPos.y, spawn);

	currGrid->SetData(gridPos.x, gridPos.y);
}


/*Checks Grid location and returns value based on that location's status
0 --- There is a normal mushroom here
1 --- There is a poison mushroom here
2 --- This column is off the screen
3 --- This row is below the screen
4 --- Nothing here
5 --- future use
*/
int MushroomManager::privCheckGrid(sf::Vector2i pos)
{
	int r = pos.x;
	int c = pos.y;
	if (c >= COLUMN || c < 0) return 2;
	else if (r < 0) return 3;
	else if (fieldArray[r][c])
	{
		return fieldArray[r][c]->ReturnStatus();
	}
	return 4;
}

void MushroomManager::privSwitchGrids(int grid)
{
	while (!regenShrooms.empty())
	{
		regenShrooms.pop();
	}
	ClearGrid();
	currGrid->WipeData();
	currGrid = grids[grid];
	GridStart();
}

void MushroomManager::ClearGrid()
{
	for (int r = 0; r < ROW; r++)
	{
		for (int c = 0; c < COLUMN; c++)
		{
			if (fieldArray[r][c])
			{
				fieldArray[r][c]->Delete();
				fieldArray[r][c] = nullptr;
			}
		}
	}
}

//Returns a pointer to the current grid data
GridData* MushroomManager::privGetGrid()
{
	return currGrid;
}

//Poisons a mushroom at the given row, column
void MushroomManager::privPoisonMushroom(int r, int c)
{
	fieldArray[r][c]->SetPoison();
}

//this function is currently not used
void MushroomManager::privMushroomDamaged(Mushroom *shroom)
{
	regenShrooms.push(shroom);
}

void MushroomManager::privFieldRegen()
{
	//cycles through in reverse order that we want to pop
	for (int c = COLUMN-1; c >= 0; c--)
	{
		for (int r = 0; r < ROW; r++)
		{
			if (fieldArray[r][c])
			{
				if (!fieldArray[r][c]->ReturnHealth()) //returns false if poisoned or damaged
					regenShrooms.push(fieldArray[r][c]);
			}
		}
	}
	if (!regenShrooms.empty())
	{
		SetAlarm(0, 0.25f);
	}
	else
		SetAlarm(0, 1.0f);
}

void MushroomManager::Alarm0()
{
	if (!regenShrooms.empty())
	{
		regenShrooms.top()->Regen();
		regenShrooms.pop();
		SetAlarm(0, 0.15f);
	}
	else
		Game_Manager::RegenComplete();
}

void MushroomManager::Terminate()
{
	ptrInstance->MarkForDestroy();
	ptrInstance = nullptr;
}
