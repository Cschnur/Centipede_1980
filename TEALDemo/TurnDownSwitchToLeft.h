#pragma once
#include "MoveState.h"
class TurnDownSwitchToLeft : public MoveState
{
public:
	TurnDownSwitchToLeft();
	virtual const MoveState* GetNextState(Centipede_Head* chead) const override;
	virtual const MoveState* BreakState(Centipede_Body* b) const override;
};

