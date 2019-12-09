#include "HUD.h"
#include "FontGlyph.h"
#include "MushroomManager.h"
#include "Score_Manager.h"

HUD* HUD::hudInstance = NULL;

HUD::HUD()
{
	/*Grid pos uses origin in the middle, glyphs are origin top-left
	this offset is used to translate to correct positions*/
	offset = sf::Vector2f(8, 8);
}

void HUD::GlyphDraw(std::string txt, sf::Vector2f pos) //Function used to spawn glyphs
{
	sf::Vector2f tmp = pos;
	for (size_t i = 0; i < txt.length(); i++)
	{
		symbols.push_back(gameFont.GetGlyph(txt.at(i), tmp));
		tmp.x += gameFont.CellWidth();
	}
}

void HUD::GlyphDrawBackwards(std::string txt, sf::Vector2f pos) //Function used to spawn glyphs
{
	sf::Vector2f tmp = pos;
	for (int i = txt.length()-1; i >= 0; i--)
	{
		symbols.push_back(gameFont.GetGlyph(txt.at(i), tmp));
		tmp.x -= gameFont.CellWidth();
	}
}

void HUD::BlockGlyphDraw(std::string txt, sf::Vector2f pos, sf::Vector2i gridpos) //function used to spawn glyphs that block
{
	sf::Vector2f tmpP = pos;
	sf::Vector2i tmpG = gridpos;
	for (int i = txt.length()-1; i >= 0; i--)
	{
		symbols.push_back(gameFont.GetGlyph(txt.at(i), tmpP));
		MushroomManager::ReportBlock(tmpG);
		tmpP.x -= gameFont.CellWidth();
		tmpG.y--;
	}
}

void HUD::privPlayer1UpdateScore(int val)
{
	std::string text = Tools::ToString(val);
	if (val < 10) text.insert(0, 1, '0');
	int temp = 6 - text.length();
	std::string buff = "     ";
	text.insert(0, buff, 0, temp);
	nextpos = sf::Vector2f(0, 0);

	GlyphDraw(text, nextpos);
}

void HUD::privPlayer1LifeUpdate(int val)
{
	std::string text = "";
	std::string lives = "++++++";
	std::string buff = "      ";
	int temp = 6 - val;
	text.insert(0, buff, 0, temp);
	text.insert(0, lives, 0, val);
	nextpos = sf::Vector2f(96, 0);

	GlyphDraw(text, nextpos);
}

void HUD::privMenuInitialize()
{
	//--------------------------Player 1----------------------------------//
	//Score
	int sc = Score_Manager::getLastScore();
	std::string text = Tools::ToString(sc);
	if (sc < 10) text.insert(0, 1, '0');
	int temp = 6 - text.length();
	std::string buff = "     ";
	text.insert(0, buff, 0, temp);

	gridPos = sf::Vector2i(0, 0);
	nextpos = (sf::Vector2f)MushroomManager::PosConverter(gridPos.x, gridPos.y);
	nextpos -= offset;

	GlyphDraw(text, nextpos);
	//----------------------------------------------------------------------//
	

	//--------------------------Player 2----------------------------------//
	//Score
	text = "    00";
	nextpos = (sf::Vector2f)MushroomManager::PosConverter(0, 24);
	nextpos -= offset;

	GlyphDraw(text, nextpos);
	//----------------------------------------------------------------------//


	//--------------------------Top Score----------------------------------//
	text = Tools::ToString(Score_Manager::getHighScore());
	nextpos = (sf::Vector2f)MushroomManager::PosConverter(0, 13);
	nextpos -= offset;

	GlyphDraw(text, nextpos);
	//----------------------------------------------------------------------//



	//--------------------------High Scores----------------------------------//
	int tmpITR = 0;
	int ROW = 3;

	text = "High Scores";
	gridPos = sf::Vector2i(ROW, 20);
	nextpos = (sf::Vector2f)MushroomManager::PosConverter(gridPos.x, gridPos.y);
	nextpos -= offset;
	BlockGlyphDraw(text, nextpos, gridPos);
	ROW++;

	//next score
	text = Tools::ToString(Score_Manager::getHighScore());
	gridPos = sf::Vector2i(ROW, 15);
	nextpos = (sf::Vector2f)MushroomManager::PosConverter(gridPos.x, gridPos.y);
	nextpos -= offset;
	BlockGlyphDraw(text, nextpos, gridPos);

	text = Tools::ToString(Score_Manager::getHighScoreInitials());
	gridPos = sf::Vector2i(ROW, 19);
	nextpos = (sf::Vector2f)MushroomManager::PosConverter(gridPos.x, gridPos.y);
	nextpos -= offset;
	BlockGlyphDraw(text, nextpos, gridPos);
	ROW++;

	//next score
	text = Tools::ToString(Score_Manager::getHighScoreList(tmpITR));
	gridPos = sf::Vector2i(ROW, 15);
	nextpos = (sf::Vector2f)MushroomManager::PosConverter(gridPos.x, gridPos.y);
	nextpos -= offset;
	BlockGlyphDraw(text, nextpos, gridPos);

	text = Tools::ToString(Score_Manager::getHighScoreListInitials(tmpITR));
	gridPos = sf::Vector2i(ROW, 19);
	nextpos = (sf::Vector2f)MushroomManager::PosConverter(gridPos.x, gridPos.y);
	nextpos -= offset;
	BlockGlyphDraw(text, nextpos, gridPos);
	tmpITR++;
	ROW++;

	//next score
	text = Tools::ToString(Score_Manager::getHighScoreList(tmpITR));
	gridPos = sf::Vector2i(ROW, 15);
	nextpos = (sf::Vector2f)MushroomManager::PosConverter(gridPos.x, gridPos.y);
	nextpos -= offset;
	BlockGlyphDraw(text, nextpos, gridPos);

	text = Tools::ToString(Score_Manager::getHighScoreListInitials(tmpITR));
	gridPos = sf::Vector2i(ROW, 19);
	nextpos = (sf::Vector2f)MushroomManager::PosConverter(gridPos.x, gridPos.y);
	nextpos -= offset;
	BlockGlyphDraw(text, nextpos, gridPos);
	tmpITR++;
	ROW++;

	//next score
	text = Tools::ToString(Score_Manager::getHighScoreList(tmpITR));
	gridPos = sf::Vector2i(ROW, 15);
	nextpos = (sf::Vector2f)MushroomManager::PosConverter(gridPos.x, gridPos.y);
	nextpos -= offset;
	BlockGlyphDraw(text, nextpos, gridPos);

	text = Tools::ToString(Score_Manager::getHighScoreListInitials(tmpITR));
	gridPos = sf::Vector2i(ROW, 19);
	nextpos = (sf::Vector2f)MushroomManager::PosConverter(gridPos.x, gridPos.y);
	nextpos -= offset;
	BlockGlyphDraw(text, nextpos, gridPos);
	tmpITR++;
	ROW++;

	//next score
	text = Tools::ToString(Score_Manager::getHighScoreList(tmpITR));
	gridPos = sf::Vector2i(ROW, 15);
	nextpos = (sf::Vector2f)MushroomManager::PosConverter(gridPos.x, gridPos.y);
	nextpos -= offset;
	BlockGlyphDraw(text, nextpos, gridPos);

	text = Tools::ToString(Score_Manager::getHighScoreListInitials(tmpITR));
	gridPos = sf::Vector2i(ROW, 19);
	nextpos = (sf::Vector2f)MushroomManager::PosConverter(gridPos.x, gridPos.y);
	nextpos -= offset;
	BlockGlyphDraw(text, nextpos, gridPos);
	tmpITR++;
	ROW++;

	//next score
	text = Tools::ToString(Score_Manager::getHighScoreList(tmpITR));
	gridPos = sf::Vector2i(ROW, 15);
	nextpos = (sf::Vector2f)MushroomManager::PosConverter(gridPos.x, gridPos.y);
	nextpos -= offset;
	BlockGlyphDraw(text, nextpos, gridPos);

	text = Tools::ToString(Score_Manager::getHighScoreListInitials(tmpITR));
	gridPos = sf::Vector2i(ROW, 19);
	nextpos = (sf::Vector2f)MushroomManager::PosConverter(gridPos.x, gridPos.y);
	nextpos -= offset;
	BlockGlyphDraw(text, nextpos, gridPos);
	tmpITR++;
	ROW++;

	//next score
	text = Tools::ToString(Score_Manager::getHighScoreList(tmpITR));
	gridPos = sf::Vector2i(ROW, 15);
	nextpos = (sf::Vector2f)MushroomManager::PosConverter(gridPos.x, gridPos.y);
	nextpos -= offset;
	BlockGlyphDraw(text, nextpos, gridPos);

	text = Tools::ToString(Score_Manager::getHighScoreListInitials(tmpITR));
	gridPos = sf::Vector2i(ROW, 19);
	nextpos = (sf::Vector2f)MushroomManager::PosConverter(gridPos.x, gridPos.y);
	nextpos -= offset;
	BlockGlyphDraw(text, nextpos, gridPos);
	tmpITR++;
	ROW++;

	//next score
	text = Tools::ToString(Score_Manager::getHighScoreList(tmpITR));
	gridPos = sf::Vector2i(ROW, 15);
	nextpos = (sf::Vector2f)MushroomManager::PosConverter(gridPos.x, gridPos.y);
	nextpos -= offset;
	BlockGlyphDraw(text, nextpos, gridPos);

	text = Tools::ToString(Score_Manager::getHighScoreListInitials(tmpITR));
	gridPos = sf::Vector2i(ROW, 19);
	nextpos = (sf::Vector2f)MushroomManager::PosConverter(gridPos.x, gridPos.y);
	nextpos -= offset;
	BlockGlyphDraw(text, nextpos, gridPos);
	tmpITR++;
	ROW++;

	//next text
	text = "CREDTIS 2";
	gridPos = sf::Vector2i(14, 18);
	nextpos = (sf::Vector2f)MushroomManager::PosConverter(gridPos.x, gridPos.y);
	nextpos -= offset;
	BlockGlyphDraw(text, nextpos, gridPos);

	//next text
	text = "BONUS EVERY 12000";
	gridPos = sf::Vector2i(15, 23);
	nextpos = (sf::Vector2f)MushroomManager::PosConverter(gridPos.x, gridPos.y);
	nextpos -= offset;
	BlockGlyphDraw(text, nextpos, gridPos);
	//----------------------------------------------------------------------//


	//--------------------------Copyright----------------------------------//
	text = "[1980 ATARI";
	nextpos = (sf::Vector2f)MushroomManager::PosConverter(32, 10);
	nextpos -= offset;

	GlyphDraw(text, nextpos);
	//----------------------------------------------------------------------//
}

void HUD::privPlayer1Initialize()
{
	//--------------------------Player 1----------------------------------//
	//Score
	std::string text = "    00";
	nextpos = (sf::Vector2f)MushroomManager::PosConverter(0, 0);
	nextpos -= offset;

	GlyphDraw(text, nextpos);


	//--------------------------Top Score----------------------------------//
	text = Tools::ToString(Score_Manager::getHighScore());
	nextpos = (sf::Vector2f)MushroomManager::PosConverter(0, 13);
	nextpos -= offset;

	GlyphDraw(text, nextpos);

	//----------------------------------------------------------------------//
}


void HUD::Draw()
{
	std::list<FontGlyph>::iterator it;
	for (it = symbols.begin(); it != symbols.end(); it++)
		it->Draw();
}

HUD::~HUD()
{
	hudInstance = nullptr;
}

void HUD::Terminate()
{
	hudInstance->MarkForDestroy();
}
