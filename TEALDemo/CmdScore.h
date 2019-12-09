#ifndef _CMDSCORE
#define _CMDSCORE

#include "CommandBased.h"

class CmdScore : public CommandBase
{
protected:
	int points;	

public:
	CmdScore() = delete;
	CmdScore(int val);

	virtual void Execute() override;

};

#endif
