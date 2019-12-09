#ifndef _OFFSETARRAY
#define _OFFSETARRAY

struct OffsetArray
{
	int xMove;
	int yMove;
	float rot;
	int rowOffset;

	OffsetArray(int x, int y, float r, int rO) : xMove(x), yMove(y), rot(r), rowOffset(rO) {};
};


#endif // !_OFFSETARRAY