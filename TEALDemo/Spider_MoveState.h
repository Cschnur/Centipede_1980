#ifndef _SPIDER_MOVESTATE
#define _SPIDER_MOVESTATE


struct Spider_OffsetArray;
class Spider;

class Spider_MoveState
{
public:
	Spider_MoveState() {};
	const Spider_OffsetArray* GetMoveOffsets() const { return MyMoveOffsets; }
	virtual const Spider_MoveState* GetNextState(Spider *s) const = 0;

protected:
	const Spider_OffsetArray* MyMoveOffsets;
};

#endif
