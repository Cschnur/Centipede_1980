#ifndef _CENTIPEDE_FONT
#define _CENTIPEDE_FONT

#include "SpriteSheet.h"

class Centipede_Font : public SpriteSheet
{
public:
	Centipede_Font();

	Centipede_Font(const Centipede_Font&) = delete;
	Centipede_Font& operator=(const Centipede_Font&) = delete;
	virtual ~Centipede_Font() = default;

private:
	virtual int CharToIndex(char& c);
};


#endif

