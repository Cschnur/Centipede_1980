#include "Spider_MoveRightAndDown.h"

#include "Spider_MoveFSM.h"
#include "Spider_MovementCollection.h"
#include "Spider_OffsetArray.h"
#include "MushroomManager.h"

#include "Spider.h"



Spider_MoveRightAndDown::Spider_MoveRightAndDown()
{
	MyMoveOffsets = &Spider_MovementCollection::RightAndDown;
}

const Spider_MoveState* Spider_MoveRightAndDown::GetNextState(Spider *s) const
{
	const Spider_MoveState* pNextState;
	int tempR;
	int r = s->getRow();
	int c = s->getColumn();
	sf::Vector2i gridPos = sf::Vector2i(r, c);
	int tempVal = MushroomManager::CheckGrid(gridPos);

	if (tempVal == 0 || tempVal == 1)
	{
		if((tempR = rand() % 2) == 0)
			MushroomManager::DestroyMushroom(gridPos);
	}
	if (r == MushroomManager::BOTTOM_ROW)
	{
		pNextState = &Spider_MoveFSM::StateSpider_MoveRightAndUp;
		s->spaceReset();
	}
	else if (s->getSpaces() == 0)
	{
		tempR = rand() % 10 + 1;
		if (tempR > 5)
			pNextState = &Spider_MoveFSM::StateSpider_MoveRightAndUp;
		else
			pNextState = &Spider_MoveFSM::StateSpider_MoveUpRight;
		s->spaceReset();
	}
	else
	{
		s->spaceDec();
		pNextState = &Spider_MoveFSM::StateSpider_MoveRightAndDown;
	}
	
	return pNextState;
}
