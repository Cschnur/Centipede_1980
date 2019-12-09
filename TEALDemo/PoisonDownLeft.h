#pragma once
#include "MoveState.h"

class PoisonDownLeft : public  MoveState
{
public:
	PoisonDownLeft();
	virtual const MoveState* GetNextState(Centipede_Head* chead) const override;
	virtual const MoveState* BreakState(Centipede_Body* b) const override;
};

