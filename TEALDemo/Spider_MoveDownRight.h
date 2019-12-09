#ifndef _SPIDER_DOWNRIGHT
#define _SPIDER_DOWNRIGHT


#include "Spider_MoveState.h"

class Spider_MoveDownRight : public Spider_MoveState
{
public:
	Spider_MoveDownRight();
	virtual const Spider_MoveState* GetNextState(Spider *s) const override;
};

#endif

