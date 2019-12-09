#ifndef _AI_MOVERIGHTANDUP
#define _AI_MOVERIGHTANDUP


#include "AI_MoveState.h"
class AI_MoveRightAndUp : public AI_MoveState
{
public:
	AI_MoveRightAndUp();
	virtual const AI_MoveState* GetNextState(BlasterAI *b) const override;
};

#endif

