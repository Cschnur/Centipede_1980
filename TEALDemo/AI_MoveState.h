#ifndef _AI_MOVESTATE
#define _AI_MOVESTATE


struct AI_OffsetArray;
class BlasterAI;
class MushroomManager;

class AI_MoveState
{
public:
	AI_MoveState() {};
	const AI_OffsetArray* GetMoveOffsets() const { return MyMoveOffsets; }
	virtual const AI_MoveState* GetNextState(BlasterAI *b) const = 0;

protected:
	const AI_OffsetArray* MyMoveOffsets;
};

#endif
