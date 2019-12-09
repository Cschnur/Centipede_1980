#ifndef _CENTIPEDE_HEAD
#define _CENTIPEDE_HEAD
#include "Game Components\TEAL\CommonElements.h"
#include "Centipede.h"

class Bullet;
class MushroomManager;
class Centipede_Body;
class Centipede_Manager;
class MoveState;

class Centipede_Head : public Centipede
{
public:
	Centipede_Head();
	void Initialize(sf::Vector2i istart, const MoveState* state, Centipede_Body *inext, int ilength, float rot, int ispeed);
	virtual void Draw();
	virtual void Delete() override;
	virtual void Destroy();
	void Death();
	void SpawnSegments(int length);
	virtual void Update();
	sf::Vector2i GetPos();
	int GetRow();
	int GetCol();
	void SetNext();
	~Centipede_Head();
private:
	const MoveState* pCurrentState;
	bool vert = true;
	bool bounded;
	bool poisoned;
	int tempVal;
	Centipede_Body *next;

	//----Test Variable----//
	bool first = true;
};

#endif 

