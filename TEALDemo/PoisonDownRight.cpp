#include "PoisonDownRight.h"
#include "MushroomManager.h"
#include "MovementCollection.h"
#include "Centipede_Head.h"
#include "Centipede_Body.h"
#include "Game Components\TEAL\CommonElements.h"
#include "MoveFSM.h"
#include "OffsetArray.h"

PoisonDownRight::PoisonDownRight()
{

	MyMoveOffsets = &MovementCollection::OffsetsTurnDownEndRight;
}

const MoveState* PoisonDownRight::GetNextState(Centipede_Head* chead) const
{
	const MoveState* pNextState;
	int row = chead->GetRow();
	int col = chead->GetCol() + 1; // looking ahead while right
								   //MushroomField::Obstacle obst = MushroomField::Inspect(row, col);
	if (row == MushroomManager::BOTTOM_ROW)
		pNextState = &MoveFSM::StateMoveRightAndDownwards;
	else
		pNextState = &MoveFSM::StatePoisonDownLeft;
	return pNextState;
}

const MoveState* PoisonDownRight::BreakState(Centipede_Body* b) const
{
	const MoveState* pNextState;
	int row = b->getRow();
	if (row == MushroomManager::BOTTOM_ROW)
		pNextState = &MoveFSM::StateTurnUpSwitchToLeft;
	else
		pNextState = &MoveFSM::StateTurnDownSwitchToLeft;
	return pNextState;
}
