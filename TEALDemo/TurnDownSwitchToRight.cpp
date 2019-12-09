#include "TurnDownSwitchToRight.h"
#include "MushroomManager.h"
#include "MovementCollection.h"
#include "Centipede_Head.h"
#include "Centipede_Body.h"
#include "Game Components\TEAL\CommonElements.h"
#include "MoveFSM.h"
#include "OffsetArray.h"


// TurnDownSwitchToRight
TurnDownSwitchToRight::TurnDownSwitchToRight()
{

	MyMoveOffsets = &MovementCollection::OffsetsTurnDownEndRight;
}

const MoveState* TurnDownSwitchToRight::GetNextState(Centipede_Head* chead) const
{
	const MoveState* pNextState;
	int row = chead->GetRow();
	int col = chead->GetCol() + 1; // looking ahead after turn -> right
	sf::Vector2i Pos = sf::Vector2i(row, col);
	int tempVal = MushroomManager::CheckGrid(Pos);

	if (tempVal == 4)
	{
		pNextState = &MoveFSM::StateMoveRightAndDownwards;
	}
	else if (tempVal == 0 || tempVal == 2) // Edge, shroom or letter?
	{
		if (row != MushroomManager::BOTTOM_ROW)
			pNextState = &MoveFSM::StateTurnDownSwitchToLeft;
		else
			pNextState = &MoveFSM::StateTurnUpSwitchToLeft;
	}
	else if(tempVal == 1)
	{
		pNextState = &MoveFSM::StatePoisonLeft;
	}

	return pNextState;
}

const MoveState* TurnDownSwitchToRight::BreakState(Centipede_Body* b) const
{
	const MoveState* pNextState;
	pNextState = &MoveFSM::StateTurnDownSwitchToRight;
	return pNextState;
}
