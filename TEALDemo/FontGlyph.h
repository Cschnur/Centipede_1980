#ifndef _FONTGLYPH
#define _FONTGLYPH

#include "SFML\Graphics.hpp"

class SpriteSheet;

class FontGlyph
{
public:
	FontGlyph();
	FontGlyph(SpriteSheet* sheet, int cellInd, sf::Vector2f pos);
	void Draw();

private:
	SpriteSheet* sprsheet;
	int cellIndex;
	sf::Vector2f position;
};

#endif
