#ifndef _CMDSCOREBYDISTANCE
#define _CMDSCOREBYDISTANCE

#include "CmdScore.h"

class CmdScoreByDistance : public CmdScore
{
private:
	int dist;

public:
	CmdScoreByDistance() = delete;
	CmdScoreByDistance(int val, int d);

	int GetDistance() { return dist; }

	virtual void Execute() override;


};

#endif _CMDSCOREBYDISTANCE

