#ifndef _AI_OFFSETARRAY
#define _AI_OFFSETARRAY

struct AI_OffsetArray
{
	int xMove;
	int yMove;

	AI_OffsetArray(int x, int y) : xMove(x), yMove(y) {};
};


#endif
