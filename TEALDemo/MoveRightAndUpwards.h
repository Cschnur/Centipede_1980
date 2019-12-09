#pragma once
#include "MoveState.h"

class MoveRightAndUpwards : public  MoveState
{
public:
	MoveRightAndUpwards();
	virtual const MoveState* GetNextState(Centipede_Head* chead) const override;
	virtual const MoveState* BreakState(Centipede_Body* b) const override;
};


