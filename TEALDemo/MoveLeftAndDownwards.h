#pragma once
#include "MoveState.h"
class MoveLeftAndDownwards : public  MoveState
{
public:
	MoveLeftAndDownwards();
	virtual const MoveState* GetNextState(Centipede_Head* chead) const override;
	virtual const MoveState* BreakState(Centipede_Body* b) const override;
};


