#include "CmdScoreByDistance.h"
#include <iostream>
#include "Score_Manager.h"

CmdScoreByDistance::CmdScoreByDistance(int val, int d)
	: CmdScore(val), dist(d)
{
	printf("Score by distance command created: if dist < %i pixels\n", d);
}

void CmdScoreByDistance::Execute()
{
	CmdScore::Execute();
}
