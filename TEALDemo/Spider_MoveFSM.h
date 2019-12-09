#ifndef _SPIDER_MOVEFSM
#define _SPIDER_MOVEFSM

#include "Spider_MoveLeftAndDown.h"
#include "Spider_MoveLeftAndUp.h"
#include "Spider_MoveRightAndDown.h"
#include "Spider_MoveRightAndUp.h"
#include "Spider_MoveDownRight.h"
#include "Spider_MoveUpRight.h"
#include "Spider_MoveDownLeft.h"
#include "Spider_MoveUpLeft.h"

class Spider_MoveFSM
{
public:
	static const Spider_MoveLeftAndDown StateSpider_MoveLeftAndDown;
	static const Spider_MoveLeftAndUp StateSpider_MoveLeftAndUp;
	static const Spider_MoveRightAndDown StateSpider_MoveRightAndDown;
	static const Spider_MoveRightAndUp StateSpider_MoveRightAndUp;
	static const Spider_MoveDownRight StateSpider_MoveDownRight;
	static const Spider_MoveUpRight StateSpider_MoveUpRight;
	static const Spider_MoveDownLeft StateSpider_MoveDownLeft;
	static const Spider_MoveUpLeft StateSpider_MoveUpLeft;
};

#endif
