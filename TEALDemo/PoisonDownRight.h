#pragma once
#include "MoveState.h"

class PoisonDownRight : public  MoveState
{
public:
	PoisonDownRight();
	virtual const MoveState* GetNextState(Centipede_Head* chead) const override;
	virtual const MoveState* BreakState(Centipede_Body* b) const override;
};

