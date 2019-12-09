#include "FontGlyph.h"

#include "SpriteSheet.h"
#include "Game Components\TEAL\ResourceManager.h"

FontGlyph::FontGlyph()
{
	sprsheet = 0;
	cellIndex = 0;
	position = sf::Vector2f(0, 0);
}


FontGlyph::FontGlyph(SpriteSheet* sheet, int cellInd, sf::Vector2f pos)
{
	sprsheet = sheet;
	position = pos;
	cellIndex = cellInd;
}

void FontGlyph::Draw()
{
	sprsheet->Draw(cellIndex, position);
}
