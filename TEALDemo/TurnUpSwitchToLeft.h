#pragma once
#include "MoveState.h"
class TurnUpSwitchToLeft : public MoveState
{
public:
	TurnUpSwitchToLeft();
	virtual const MoveState* GetNextState(Centipede_Head* chead) const override;
	virtual const MoveState* BreakState(Centipede_Body* b) const override;
};

