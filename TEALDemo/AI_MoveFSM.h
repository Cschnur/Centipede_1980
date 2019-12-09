#ifndef _AI_MOVEFSM
#define _AI_MOVEFSM

#include "AI_MoveLeftAndDown.h"
#include "AI_MoveLeftAndUp.h"
#include "AI_MoveRightAndDown.h"
#include "AI_MoveRightAndUp.h"

class AI_MoveFSM
{
public:
	static const AI_MoveLeftAndDown StateAI_MoveLeftAndDown;
	static const AI_MoveLeftAndUp StateAI_MoveLeftAndUp;
	static const AI_MoveRightAndDown StateAI_MoveRightAndDown;
	static const AI_MoveRightAndUp StateAI_MoveRightAndUp;
};

#endif
