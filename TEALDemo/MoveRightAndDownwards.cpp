#include "MoveRightAndDownwards.h"
#include "MushroomManager.h"
#include "MovementCollection.h"
#include "Centipede_Head.h"
#include "Centipede_Body.h"
#include "Game Components\TEAL\CommonElements.h"
#include "MoveFSM.h"
#include "OffsetArray.h"

MoveRightAndDownwards::MoveRightAndDownwards()
{

	MyMoveOffsets = &MovementCollection::OffsetsStraightRight;
}

const MoveState* MoveRightAndDownwards::GetNextState(Centipede_Head* chead) const
{
	const MoveState* pNextState;
	int row = chead->GetRow();
	int col = chead->GetCol() + 1; // looking ahead while right
	//MushroomField::Obstacle obst = MushroomField::Inspect(row, col);
	sf::Vector2i Pos = sf::Vector2i(row, col);
	int tempVal = MushroomManager::CheckGrid(Pos);

	if (tempVal == 4)
	{
		pNextState = &MoveFSM::StateMoveRightAndDownwards;
	}
	else if (tempVal == 0 || tempVal == 2) // Edge, shroom or letter?
	{
		if (row == MushroomManager::BOTTOM_ROW)
			pNextState = &MoveFSM::StateTurnUpSwitchToLeft;
		else
			pNextState = &MoveFSM::StateTurnDownSwitchToLeft;
	}
	else if(tempVal == 1)
	{
		pNextState = &MoveFSM::StatePoisonDownLeft;
	}

	return pNextState;
}

const MoveState* MoveRightAndDownwards::BreakState(Centipede_Body* b) const
{
	const MoveState* pNextState;
	int row = b->getRow();
	if (row == MushroomManager::BOTTOM_ROW)
		pNextState = &MoveFSM::StateTurnUpSwitchToLeft;
	else
		pNextState = &MoveFSM::StateTurnDownSwitchToLeft;
	return pNextState;
}
