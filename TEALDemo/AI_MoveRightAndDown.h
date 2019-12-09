#ifndef _AI_MOVERIGHTANDDOWN
#define _AI_MOVERIGHTANDDOWN


#include "AI_MoveState.h"
class AI_MoveRightAndDown : public AI_MoveState
{
public:
	AI_MoveRightAndDown();
	virtual const AI_MoveState* GetNextState(BlasterAI *b) const override;
};

#endif
