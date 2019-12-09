#include "AI_MoveLeftAndUp.h"

#include "AI_MoveFSM.h"
#include "AI_MovementCollection.h"
#include "AI_OffsetArray.h"

#include "BlasterAI.h"
#include "MushroomManager.h"


AI_MoveLeftAndUp::AI_MoveLeftAndUp()
{
	MyMoveOffsets = &AI_MovementCollection::LeftAndUp;
}

const AI_MoveState* AI_MoveLeftAndUp::GetNextState(BlasterAI *b) const
{
	int x = b->getX();
	int y = b->getY();
	const AI_MoveState* pNextState;
	if (y < BlasterAI::TOP)
		pNextState = &AI_MoveFSM::StateAI_MoveLeftAndDown;
	else if (x < BlasterAI::MAX_LEFT)
		pNextState = &AI_MoveFSM::StateAI_MoveRightAndUp;
	else pNextState = &AI_MoveFSM::StateAI_MoveLeftAndUp;
	return pNextState;
}
