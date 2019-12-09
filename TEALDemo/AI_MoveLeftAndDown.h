#ifndef _AI_MOVELEFTANDDOWN
#define _AI_MOVELEFTANDDOWN


#include "AI_MoveState.h"
class AI_MoveLeftAndDown : public AI_MoveState
{
public:
	AI_MoveLeftAndDown();
	virtual const AI_MoveState* GetNextState(BlasterAI *b) const override;
};

#endif

