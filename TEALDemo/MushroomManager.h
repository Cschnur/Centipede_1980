#ifndef _MUSHROOMMANAGER
#define _MUSHROOMMANAGER

#include "Game Components\TEAL\CommonElements.h"
#include <stack>

class Mushroom;
class GridObject;
struct GridData;

const int NUM_GRIDS = 3;

class MushroomManager : public GameObject
{
public:
	static void Initialize() { Instance().privInitialize(); };
	static void SwitchGrids(int grid) { Instance().privSwitchGrids(grid); };
	static GridData* GetGrid() { return Instance().privGetGrid(); };
	static void ReportBlock(sf::Vector2i gridPos) { Instance().privReportBlock(gridPos); }

	virtual void GridUpdate(int r, int c, Mushroom* spawn);
	static void MushroomSpawn(sf::Vector2i pos) { Instance().privMushroomSpawn(pos); };
	static void PoisonMushroom(int r, int c) { Instance().privPoisonMushroom(r, c); };
	static void DestroyMushroom(sf::Vector2i gridpos) { Instance().privDestroyMushroom(gridpos); };

	virtual void GridStart();
	static void WaveStart() { Instance().privWaveStart(); };

	virtual void GridPrint();
	static sf::Vector2i GridConverter(int x, int y);
	static sf::Vector2i PosConverter(int r, int c);
	static void GridDelete(sf::Vector2i gridpos) { Instance().privGridDelete(gridpos); };
	static int CheckGrid(sf::Vector2i pos) { return Instance().privCheckGrid(pos); };
	static void MushroomDamaged(Mushroom* shroom) { Instance().privMushroomDamaged(shroom); };

	static void FieldRegen() { Instance().privFieldRegen(); };

	static const int BOTTOM_ROW = 31;
	static const int TOP_PLAYER_ROW = 25;
	static const int TOP_MUSHROOM_ROW = 2;

	static const int ROW = 32;
	static const int COLUMN = 30;

	static void Terminate();

	void Alarm0();

private:

	MushroomManager() = default;
	static MushroomManager* ptrInstance;
	MushroomManager(const MushroomManager&) = delete;
	MushroomManager& operator=(const MushroomManager&) = delete;

	static MushroomManager& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new MushroomManager;
		return *ptrInstance;
	};

	void privInitialize();
	void privSwitchGrids(int grid);
	void privReportBlock(sf::Vector2i gridPos);
	GridData* privGetGrid();
	void privMushroomSpawn(sf::Vector2i pos);
	void privPoisonMushroom(int r, int c);
	void privDestroyMushroom(sf::Vector2i gridpos);
	int privCheckGrid(sf::Vector2i pos);
	void privMushroomDamaged(Mushroom* shroom);
	void privGridDelete(sf::Vector2i gridpos);
	void privFieldRegen();
	void privWaveStart();

	void ClearGrid();

	//Mushrooms exist within row 4 and 29
	Mushroom *fieldArray[ROW][COLUMN] = {};
	static GridData AiGrid;
	static GridData Player1Grid;
	static GridData Player2Grid;
	static GridData* currGrid;
	static GridData* grids[NUM_GRIDS];

	//mushrooms that are damaged or poisoned
	std::stack<Mushroom*> regenShrooms;
};

#endif

