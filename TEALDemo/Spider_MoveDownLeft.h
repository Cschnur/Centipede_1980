#ifndef _SPIDER_DOWNLEFT
#define _SPIDER_DOWNLEFT


#include "Spider_MoveState.h"

class Spider_MoveDownLeft : public Spider_MoveState
{
public:
	Spider_MoveDownLeft();
	virtual const Spider_MoveState* GetNextState(Spider *s) const override;
};

#endif

