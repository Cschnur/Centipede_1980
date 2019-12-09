#include "Block_Factory.h"
#include "Game Components\TEAL\CommonElements.h"
#include "Block.h"

Block_Factory* Block_Factory::ptrInstance = NULL;

Block* Block_Factory::privCreateBlock(sf::Vector2i start)
{
	Block *b;

	if (recycledItems.empty())
	{

		b = new Block();
		b->SetExternalManagement(RecycleBlock);
	}
	else
	{
		b = recycledItems.top();
		recycledItems.pop();


		b->RegisterToCurrentScene();
	}

	b->Initialize(start);

	return b;
}

void Block_Factory::privRecycleBlock(GameObject* b)
{
	recycledItems.push((Block*)b);
}

void Block_Factory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}


Block_Factory::~Block_Factory()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}
