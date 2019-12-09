#include "PoisonRight.h"
#include "MushroomManager.h"
#include "MovementCollection.h"
#include "Centipede_Head.h"
#include "Centipede_Body.h"
#include "Game Components\TEAL\CommonElements.h"
#include "MoveFSM.h"
#include "OffsetArray.h"

PoisonRight::PoisonRight()
{

	MyMoveOffsets = &MovementCollection::OffsetsStraightRight;
}

const MoveState* PoisonRight::GetNextState(Centipede_Head* chead) const
{
	const MoveState* pNextState;
	int row = chead->GetRow();
	int col = chead->GetCol() + 1; // looking ahead while right
								   //MushroomField::Obstacle obst = MushroomField::Inspect(row, col);
	pNextState = &MoveFSM::StatePoisonDownLeft;
	return pNextState;
}

const MoveState* PoisonRight::BreakState(Centipede_Body* b) const
{
	const MoveState* pNextState;
	int row = b->getRow();
	if (row == MushroomManager::BOTTOM_ROW)
		pNextState = &MoveFSM::StateTurnUpSwitchToLeft;
	else
		pNextState = &MoveFSM::StateTurnDownSwitchToLeft;
	return pNextState;
}
