#ifndef _SPIDER_UPLEFT
#define _SPIDER_UPLEFT


#include "Spider_MoveState.h"

class Spider_MoveUpLeft : public Spider_MoveState
{
public:
	Spider_MoveUpLeft();
	virtual const Spider_MoveState* GetNextState(Spider *s) const override;
};

#endif


