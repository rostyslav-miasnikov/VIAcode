// Player_strategies.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Players_Strategies.h"
#include "Players_OOP.h"


int _tmain(int argc, _TCHAR* argv[])
{
	T::Player<T::FootbalPlayer> t_player;
	t_player.doAction();

	T::Player<OOP::FootbalPlayer> oop_player;
	oop_player.doAction();

	OOP::Player *footbalPlayer = new OOP::FootbalPlayer();
	footbalPlayer->doAction();
	delete footbalPlayer;

	std::tr1::shared_ptr<OOP::Player> hockeyPlayer(new OOP::HockeyPlayer());
	hockeyPlayer->doAction();

	T::PianoPlayer pianoPlayer;
	pianoPlayer.doAction();

	return 0;
}

