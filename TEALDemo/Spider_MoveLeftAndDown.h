#ifndef _SPIDER_MOVELEFTANDDOWN
#define _SPIDER_MOVELEFTANDDOWN


#include "Spider_MoveState.h"

class Spider_MoveLeftAndDown : public Spider_MoveState
{
public:
	Spider_MoveLeftAndDown();
	virtual const Spider_MoveState* GetNextState(Spider *s) const override;
};

#endif

