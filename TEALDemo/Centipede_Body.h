#include "Centipede.h"
#include "Game Components\TEAL\CommonElements.h"

class MoveState;
class Centipede_Manager;
class Centipede_Head;

class Centipede_Body : public Centipede
{
public:
	Centipede_Body();
	void Initialize(sf::Vector2i start, void *prevSeg, bool head, int ispeed);
	void SetNext(Centipede_Body *nextSeg);
	void SetHead(Centipede_Head *head);
	Centipede_Body* getNext();
	Centipede_Body* getPrev();
	void HeadDeath();
	void BecomeHead();
	void nowFirst();
	virtual void Delete() override;
	void Draw();
	void Destroy();
	void Death();
	int getRow();
	void Update();
	void MovementUpdate(const MoveState* state);
	~Centipede_Body();
private:
	const MoveState* pCurrentState;
	int tempVal;
	int countSeg = 16;
	bool first;
	bool headless;
	bool active;
	Centipede_Body *next;
	Centipede_Body *prev;
	Centipede_Head *head;
};
