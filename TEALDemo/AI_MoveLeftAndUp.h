#ifndef _AI_MOVELEFTANDUP
#define _AI_MOVELEFTANDUP


#include "AI_MoveState.h"
class AI_MoveLeftAndUp : public AI_MoveState
{
public:
	AI_MoveLeftAndUp();
	virtual const AI_MoveState* GetNextState(BlasterAI *b) const override;
};

#endif

