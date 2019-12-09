#include "SpriteSheet.h"
#include "FontGlyph.h"
#include "Game Components\TEAL\WindowManager.h"


SpriteSheet::SpriteSheet(sf::Texture& tex, int cellCountHor, int CellCountVert)
{
	MainSprite = sf::Sprite(tex);

	//MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);

	cellWidth = tex.getSize().x / cellCountHor;
	cellHeight = tex.getSize().y / CellCountVert;

	cells.resize(cellCountHor * CellCountVert);

	int left;
	int top;
	for (int j = 0; j < CellCountVert; j++)
	{
		top = j * cellHeight;
		for (int i = 0; i < cellCountHor; i++)
		{
			left = i * cellWidth;
			cells[j*cellCountHor + i] = sf::IntRect(left, top, cellWidth, cellHeight);
		}
	}
}

int SpriteSheet::CellWidth()
{
	return cellWidth;
}

int SpriteSheet::CellHeight()
{
	return cellHeight;
}

FontGlyph SpriteSheet::GetGlyph(char c, sf::Vector2f pos)
{
	return FontGlyph(this, CharToIndex(c), pos);
}

void SpriteSheet::Draw(int i, sf::Vector2f pos)
{
	MainSprite.setTextureRect(cells[i]);
	MainSprite.setPosition(pos);

	WindowManager::MainWindow.draw(MainSprite);
}
