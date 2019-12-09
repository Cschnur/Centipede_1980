#include "MoveRightAndUpwards.h"
#include "MushroomManager.h"
#include "MovementCollection.h"
#include "Centipede_Head.h"
#include "Centipede_Body.h"
#include "Game Components\TEAL\CommonElements.h"
#include "MoveFSM.h"
#include "OffsetArray.h"

// MoveRightAndUpwards
MoveRightAndUpwards::MoveRightAndUpwards()
{

	MyMoveOffsets = &MovementCollection::OffsetsStraightRight;
}

const MoveState* MoveRightAndUpwards::GetNextState(Centipede_Head* chead) const
{
	const MoveState* pNextState;
	int row = chead->GetRow();
	int col = chead->GetCol() + 1; // looking ahead while right
	//MushroomField::Obstacle obst = MushroomField::Inspect(row, col);
	sf::Vector2i Pos = sf::Vector2i(row, col);
	int tempVal = MushroomManager::CheckGrid(Pos);

	if (tempVal == 4)
	{
		pNextState = &MoveFSM::StateMoveRightAndUpwards;
	}
	else if (tempVal == 0 || tempVal == 2) // Edge, shroom or letter?
	{
		if (row == MushroomManager::TOP_PLAYER_ROW)
			pNextState = &MoveFSM::StateTurnDownSwitchToLeft;
		else
			pNextState = &MoveFSM::StateTurnUpSwitchToLeft;
	}
	else if (tempVal == 1)
	{
		pNextState = &MoveFSM::StatePoisonDownRight;
	}

	return pNextState;
}

const MoveState* MoveRightAndUpwards::BreakState(Centipede_Body* b) const
{
	const MoveState* pNextState;
	int row = b->getRow();
	if (row == MushroomManager::TOP_PLAYER_ROW)
		pNextState = &MoveFSM::StateTurnDownSwitchToLeft;
	else
		pNextState = &MoveFSM::StateTurnUpSwitchToLeft;
	return pNextState;
}
