#pragma once
#include "MoveState.h"
class TurnDownSwitchToRight : public  MoveState
{
public:
	TurnDownSwitchToRight();
	virtual const MoveState* GetNextState(Centipede_Head* chead) const override;
	virtual const MoveState* BreakState(Centipede_Body* b) const override;
};

