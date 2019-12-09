#include "CmdScore.h"
#include <iostream>
#include "Score_Manager.h"
#include "Game Components\TEAL\CommonElements.h"

CmdScore::CmdScore(int val)
	: points(val)
{
	ConsoleMsg::WriteLine("Score Command created: Points = " + Tools::ToString(val));
}

void CmdScore::Execute()
{
	Score_Manager::AddScore(points);
}
