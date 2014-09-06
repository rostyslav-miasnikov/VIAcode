#include "StdAfx.h"
#include "Players_Strategies.h"

#include <iostream>

namespace T
{
	void FootbalPlayer::doAction()
	{
		std::cout << "Footbal player kick the ball." << std::endl;
	}

	void HockeyPlayer::doAction()
	{
		std::cout << "Hockey player kick the puck." << std::endl;
	}

	void PianoPlayer::doAction()
	{
		std::cout << "Piano player plays music." << std::endl;
	}
}
