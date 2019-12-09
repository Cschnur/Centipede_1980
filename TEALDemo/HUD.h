#ifndef _HUD
#define _HUD

#include "Game Components\TEAL\CommonElements.h"
#include <list>
#include "Centipede_Font.h"


class HUD : public GameObject
{
public:
	static void Player1UpdateScore(int val) { Instance().privPlayer1UpdateScore(val); };
	static void MenuIntialize() { Instance().privMenuInitialize(); };
	static void Player1Initialize() { Instance().privPlayer1Initialize(); };
	static void Player1LifeUpdate(int val) { Instance().privPlayer1LifeUpdate(val); };
	virtual void Draw();

	void GlyphDraw(std::string txt, sf::Vector2f pos);
	void GlyphDrawBackwards(std::string txt, sf::Vector2f pos);
	void BlockGlyphDraw(std::string txt, sf::Vector2f pos, sf::Vector2i gridpos);

	static void Terminate();

private:
	static HUD* hudInstance;

	HUD();
	HUD(const HUD&) = delete;
	HUD& operator=(const HUD&) = delete;
	~HUD();

	static HUD& Instance()
	{
		if (!hudInstance)
			hudInstance = new HUD;
		return *hudInstance;
	};

	Centipede_Font gameFont;
	std::list<FontGlyph> symbols;
	sf::Vector2f nextpos;
	sf::Vector2i gridPos;
	sf::Vector2f offset;

	void privPlayer1UpdateScore(int val);
	void privMenuInitialize();
	void privPlayer1Initialize();
	void privPlayer1LifeUpdate(int val);
};

#endif
