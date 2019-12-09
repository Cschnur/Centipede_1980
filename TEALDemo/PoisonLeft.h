#pragma once
#include "MoveState.h"

class PoisonLeft : public  MoveState
{
public:
	PoisonLeft();
	virtual const MoveState* GetNextState(Centipede_Head* chead) const override;
	virtual const MoveState* BreakState(Centipede_Body* b) const override;
};

