#include "AI_MoveLeftAndDown.h"

#include "AI_MoveFSM.h"
#include "AI_MovementCollection.h"
#include "AI_OffsetArray.h"

#include "BlasterAI.h"
#include "MushroomManager.h"


AI_MoveLeftAndDown::AI_MoveLeftAndDown()
{
	MyMoveOffsets = &AI_MovementCollection::LeftAndDown;
}

const AI_MoveState* AI_MoveLeftAndDown::GetNextState(BlasterAI *b) const
{
	int x = b->getX();
	int y = b->getY();
	const AI_MoveState* pNextState;
	if(y > BlasterAI::BOTTOM)
		pNextState = &AI_MoveFSM::StateAI_MoveLeftAndUp;
	else if(x < BlasterAI::MAX_LEFT)
		pNextState = &AI_MoveFSM::StateAI_MoveRightAndDown;
	else pNextState = &AI_MoveFSM::StateAI_MoveLeftAndDown;
	return pNextState;
}

