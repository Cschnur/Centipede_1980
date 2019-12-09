#ifndef _SPIDER_MOVERIGHTANDDOWN
#define _SPIDER_MOVERIGHTANDDOWN


#include "Spider_MoveState.h"

class Spider_MoveRightAndDown : public Spider_MoveState
{
public:
	Spider_MoveRightAndDown();
	virtual const Spider_MoveState* GetNextState(Spider *s) const override;
};

#endif

