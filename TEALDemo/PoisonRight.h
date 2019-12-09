#pragma once
#include "MoveState.h"

class PoisonRight : public  MoveState
{
public:
	PoisonRight();
	virtual const MoveState* GetNextState(Centipede_Head* chead) const override;
	virtual const MoveState* BreakState(Centipede_Body* b) const override;
};
