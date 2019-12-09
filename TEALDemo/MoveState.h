#ifndef _MOVESTATE
#define _MOVESTATE


struct OffsetArray;
class Centipede_Head;
class Centipede_Body;
class MushroomManager;

class MoveState
{
public:
	MoveState() {};
	const OffsetArray* GetMoveOffsets() const { return MyMoveOffsets; }
	virtual const MoveState* GetNextState(Centipede_Head* chead) const = 0;
	virtual const MoveState* BreakState(Centipede_Body* b) const = 0;

protected:
	const OffsetArray* MyMoveOffsets;
};

#endif
