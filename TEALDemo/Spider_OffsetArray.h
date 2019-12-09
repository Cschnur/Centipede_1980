#ifndef _SPIDER_OFFSETARRAY
#define _SPIDER_OFFSETARRAY

struct Spider_OffsetArray
{
	int xMove;
	int yMove;

	Spider_OffsetArray(int x, int y) : xMove(x), yMove(y) {};
};


#endif