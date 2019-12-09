#include "TurnDownSwitchToLeft.h"
#include "MushroomManager.h"
#include "MovementCollection.h"
#include "Centipede_Head.h"
#include "Centipede_Body.h"
#include "Game Components\TEAL\CommonElements.h"
#include "MoveFSM.h"
#include "OffsetArray.h"

// TurnDownSwitchToLeft
TurnDownSwitchToLeft::TurnDownSwitchToLeft()
{

	MyMoveOffsets = &MovementCollection::OffsetsTurnDownEndLeft;
}

const MoveState* TurnDownSwitchToLeft::GetNextState(Centipede_Head* chead) const
{
	const MoveState* pNextState;
	int row = chead->GetRow();
	int col = chead->GetCol() - 1; // looking ahead after turn ->left
	//MushroomField::Obstacle obst = MushroomField::Inspect(row, col);
	sf::Vector2i Pos = sf::Vector2i(row, col);
	int tempVal = MushroomManager::CheckGrid(Pos);

	if (tempVal == 4)
	{
		pNextState = &MoveFSM::StateMoveLeftAndDownwards;
	}
	else if (tempVal == 0 || tempVal == 2) // Edge, shroom or letter?
	{
		if (row != MushroomManager::BOTTOM_ROW)
			pNextState = &MoveFSM::StateTurnDownSwitchToRight;
		else
			pNextState = &MoveFSM::StateTurnUpSwitchToRight;
	}
	else if(tempVal == 1)
	{
		pNextState = &MoveFSM::StatePoisonRight;
	}

	return pNextState;
}

const MoveState* TurnDownSwitchToLeft::BreakState(Centipede_Body* b) const
{
	const MoveState* pNextState;
	pNextState = &MoveFSM::StateTurnDownSwitchToRight;
	return pNextState;
}
