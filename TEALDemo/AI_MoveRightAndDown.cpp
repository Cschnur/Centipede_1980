#include "AI_MoveRightAndDown.h"

#include "AI_MoveFSM.h"
#include "AI_MovementCollection.h"
#include "AI_OffsetArray.h"

#include "BlasterAI.h"
#include "MushroomManager.h"


AI_MoveRightAndDown::AI_MoveRightAndDown()
{
	MyMoveOffsets = &AI_MovementCollection::RightAndDown;
}

const AI_MoveState* AI_MoveRightAndDown::GetNextState(BlasterAI *b) const
{
	int x = b->getX();
	int y = b->getY();
	const AI_MoveState* pNextState;
	if (y > BlasterAI::BOTTOM)
		pNextState = &AI_MoveFSM::StateAI_MoveRightAndUp;
	else if (x > BlasterAI::MAX_RIGHT)
		pNextState = &AI_MoveFSM::StateAI_MoveLeftAndDown;
	else pNextState = &AI_MoveFSM::StateAI_MoveRightAndDown;
	return pNextState;
}

