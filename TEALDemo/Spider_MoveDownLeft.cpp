#include "Spider_MoveDownLeft.h"

#include "Spider_MoveFSM.h"
#include "Spider_MovementCollection.h"
#include "Spider_OffsetArray.h"
#include "MushroomManager.h"

#include "Spider.h"



Spider_MoveDownLeft::Spider_MoveDownLeft()
{
	MyMoveOffsets = &Spider_MovementCollection::Down;
}

const Spider_MoveState* Spider_MoveDownLeft::GetNextState(Spider *s) const
{
	const Spider_MoveState* pNextState;
	int tempR;
	int r = s->getRow();
	int c = s->getColumn();
	sf::Vector2i gridPos = sf::Vector2i(r, c);
	int tempVal = MushroomManager::CheckGrid(gridPos);

	if (tempVal == 0 || tempVal == 1)
	{
		if ((tempR = rand() % 2) == 0)
			MushroomManager::DestroyMushroom(gridPos);
	}
	if (r == MushroomManager::BOTTOM_ROW)
	{
		s->spaceDec();
		pNextState = &Spider_MoveFSM::StateSpider_MoveLeftAndUp;
	}
	else if (s->getSpaces() == 0)
	{
		tempR = rand() % 10 + 1;
		if (tempR > 5)
			pNextState = &Spider_MoveFSM::StateSpider_MoveLeftAndUp;
		else
			pNextState = &Spider_MoveFSM::StateSpider_MoveDownLeft;
		s->spaceReset();
	}
	else
	{
		s->spaceDec();
		pNextState = &Spider_MoveFSM::StateSpider_MoveDownLeft;
	}

	return pNextState;
}
