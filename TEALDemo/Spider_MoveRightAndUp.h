#ifndef _SPIDER_MOVERIGHTANDUP
#define _SPIDER_MOVERIGHTANDUP


#include "Spider_MoveState.h"

class Spider_MoveRightAndUp : public Spider_MoveState
{
public:
	Spider_MoveRightAndUp();
	virtual const Spider_MoveState* GetNextState(Spider *s) const override;
};

#endif

