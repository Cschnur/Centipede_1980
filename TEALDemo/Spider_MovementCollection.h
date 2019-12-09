#ifndef _SPIDER_MOVEMENTCOLLECTION
#define _SPIDER_MOVEMENTCOLLECTION

struct Spider_OffsetArray;

class Spider_MovementCollection
{
public:
	static const Spider_OffsetArray LeftAndUp;
	static const Spider_OffsetArray LeftAndDown;
	static const Spider_OffsetArray RightAndUp;
	static const Spider_OffsetArray RightAndDown;
	static const Spider_OffsetArray Down;
	static const Spider_OffsetArray Up;
};

#endif

