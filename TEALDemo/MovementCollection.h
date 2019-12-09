#ifndef _MOVEMENTCOLLECTION
#define _MOVEMENTCOLLECTION

struct OffsetArray;

class MovementCollection
{
public:
	static const OffsetArray OffsetsStraightRight;
	static const OffsetArray OffsetsTurnUpEndRight;
	static const OffsetArray OffsetsTurnDownEndRight;
	static const OffsetArray OffsetsStraightLeft;
	static const OffsetArray OffsetsTurnUpEndLeft;
	static const OffsetArray OffsetsTurnDownEndLeft;
};

#endif _MOVEMENTCOLLECTION
