#ifndef _SPIDER_UPRIGHT
#define _SPIDER_UPRIGHT


#include "Spider_MoveState.h"

class Spider_MoveUpRight : public Spider_MoveState
{
public:
	Spider_MoveUpRight();
	virtual const Spider_MoveState* GetNextState(Spider *s) const override;
};

#endif
