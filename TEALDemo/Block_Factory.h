#ifndef _BLOCK_FACTORY
#define _BLOCK_FACTORY

#include <stack>
#include "Game Components\TEAL\CommonElements.h"

class Block;

class Block_Factory
{
public:
	static Block* CreateBlock(sf::Vector2i start) { return Instance().privCreateBlock(start); };
	static void RecycleBlock(GameObject* b) { Instance().privRecycleBlock(b); };

	static void Terminate();

private:
	static Block_Factory* ptrInstance;

	Block_Factory() = default;
	Block_Factory(const Block_Factory&) = delete;
	Block_Factory& operator=(const Block_Factory&) = delete;
	~Block_Factory();

	static Block_Factory& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new Block_Factory;
		return *ptrInstance;
	};

	std::stack<Block*> recycledItems;

	Block* privCreateBlock(sf::Vector2i start);
	void privRecycleBlock(GameObject* b);
};

#endif

