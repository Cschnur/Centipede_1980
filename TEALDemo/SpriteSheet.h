#ifndef _SPRITESHEET
#define _SPRITESHEET

#include "SFML\Graphics.hpp"
#include <vector>

class FontGlyph;

class SpriteSheet
{
public:
	SpriteSheet(sf::Texture& tex, int CellCountHor, int CellCountVert);
	int CellWidth();
	int CellHeight();
	void Draw(int i, sf::Vector2f pos);
	FontGlyph GetGlyph(char c, sf::Vector2f pos);

	virtual ~SpriteSheet() = default;

private:
	std::vector<sf::IntRect> cells;
	sf::Sprite MainSprite;
	int cellWidth;
	int cellHeight;

	virtual int CharToIndex(char& c) = 0;
};

#endif

