#include "MoveLeftAndUpwards.h"
#include "MushroomManager.h"
#include "MovementCollection.h"
#include "Centipede_Head.h"
#include "Centipede_Body.h"
#include "Game Components\TEAL\CommonElements.h"
#include "MoveFSM.h"
#include "OffsetArray.h"

// MoveLeftAndUpwards
MoveLeftAndUpwards::MoveLeftAndUpwards()
{

	MyMoveOffsets = &MovementCollection::OffsetsStraightLeft;
}

const MoveState* MoveLeftAndUpwards::GetNextState(Centipede_Head* chead) const
{
	const MoveState* pNextState;
	int row = chead->GetRow();
	int col = chead->GetCol() - 1; // looking ahead while left
	//MushroomField::Obstacle obst = MushroomField::Inspect(row, col);
	sf::Vector2i Pos = sf::Vector2i(row, col);
	int tempVal = MushroomManager::CheckGrid(Pos);

	if (tempVal == 4)
	{
		pNextState = &MoveFSM::StateMoveLeftAndUpwards;
	}
	else if (tempVal == 0 || tempVal == 2) // Edge, shroom or letter?
	{
		if (row == MushroomManager::TOP_PLAYER_ROW)
			pNextState = &MoveFSM::StateTurnDownSwitchToRight;
		else
			pNextState = &MoveFSM::StateTurnUpSwitchToRight;
	}
	else if (tempVal == 1)// poison
	{
		pNextState = &MoveFSM::StatePoisonDownRight;
	}

	return pNextState;
}

const MoveState* MoveLeftAndUpwards::BreakState(Centipede_Body* b) const
{
	const MoveState* pNextState;
	int row = b->getRow();
	if (row == MushroomManager::TOP_PLAYER_ROW)
		pNextState = &MoveFSM::StateTurnDownSwitchToRight;
	else
		pNextState = &MoveFSM::StateTurnUpSwitchToRight;
	return pNextState;
}
