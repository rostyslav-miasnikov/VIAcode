#include "StdAfx.h"
#include "Players_OOP.h"

#include <iostream>

namespace OOP
{
	void FootbalPlayer::doAction() const
	{
		std::cout << "Footbal player sings song." << std::endl;
	}

	void HockeyPlayer::doAction() const
	{
		std::cout << "Hockey player eats something." << std::endl;
	}

	HockeyPlayer::~HockeyPlayer()
	{
		std::cout << "HockeyPlayer::~HockeyPlayer()" << std::endl;
	}
}
