#ifndef _SPIDER_MOVELEFTANDUP
#define _SPIDER_MOVELEFTANDUP


#include "Spider_MoveState.h"

class Spider_MoveLeftAndUp : public Spider_MoveState
{
public:
	Spider_MoveLeftAndUp();
	virtual const Spider_MoveState* GetNextState(Spider *s) const override;
};

#endif
