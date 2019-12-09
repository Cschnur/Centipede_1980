#include "AI_MoveRightAndUp.h"

#include "AI_MoveFSM.h"
#include "AI_MovementCollection.h"
#include "AI_OffsetArray.h"

#include "BlasterAI.h"
#include "MushroomManager.h"

AI_MoveRightAndUp::AI_MoveRightAndUp()
{
	MyMoveOffsets = &AI_MovementCollection::RightAndUp;
}

const AI_MoveState* AI_MoveRightAndUp::GetNextState(BlasterAI *b) const
{
	int x = b->getX();
	int y = b->getY();
	const AI_MoveState* pNextState;
	if (y < BlasterAI::TOP)
		pNextState = &AI_MoveFSM::StateAI_MoveRightAndDown;
	else if (x > BlasterAI::MAX_RIGHT)
		pNextState = &AI_MoveFSM::StateAI_MoveLeftAndUp;
	else pNextState = &AI_MoveFSM::StateAI_MoveRightAndUp;
	return pNextState;
}


