#include "TurnUpSwitchToRight.h"
#include "MushroomManager.h"
#include "MovementCollection.h"
#include "Centipede_Head.h"
#include "Centipede_Body.h"
#include "Game Components\TEAL\CommonElements.h"
#include "MoveFSM.h"
#include "OffsetArray.h"

// TurnUpSwitchToRight
TurnUpSwitchToRight::TurnUpSwitchToRight()
{

	MyMoveOffsets = &MovementCollection::OffsetsTurnUpEndRight;
}

const MoveState* TurnUpSwitchToRight::GetNextState(Centipede_Head* chead) const
{
	const MoveState* pNextState;
	int row = chead->GetRow();
	int col = chead->GetCol() + 1; // looking ahead after turn -> Right
	//MushroomField::Obstacle obst = MushroomField::Inspect(row, col);
	sf::Vector2i Pos = sf::Vector2i(row, col);
	int tempVal = MushroomManager::CheckGrid(Pos);

	if (tempVal == 4)
	{
		pNextState = &MoveFSM::StateMoveRightAndUpwards;
	}
	else if (tempVal == 0 || tempVal == 2) // Edge, shroom or letter?
	{
		if (row != MushroomManager::TOP_PLAYER_ROW)
			pNextState = &MoveFSM::StateTurnUpSwitchToLeft;
		else
			pNextState = &MoveFSM::StateTurnDownSwitchToLeft;
	}
	else if(tempVal == 1)
	{
		pNextState = &MoveFSM::StatePoisonDownRight;
	}

	return pNextState;
}

const MoveState* TurnUpSwitchToRight::BreakState(Centipede_Body* b) const
{
	const MoveState* pNextState;
	pNextState = &MoveFSM::StateTurnDownSwitchToRight;
	return pNextState;
}
