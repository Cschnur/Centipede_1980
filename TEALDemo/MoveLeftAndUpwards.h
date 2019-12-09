#pragma once
#include "MoveState.h"

class MoveLeftAndUpwards : public  MoveState
{
public:
	MoveLeftAndUpwards();
	virtual const MoveState* GetNextState(Centipede_Head* chead) const override;
	virtual const MoveState* BreakState(Centipede_Body* b) const override;
};

