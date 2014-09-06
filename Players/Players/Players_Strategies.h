#pragma once

#include <memory>

namespace T
{
	template<class ConcretPlayer>
	class Player
	{
		typedef std::tr1::shared_ptr<ConcretPlayer> PlayerPointerType;
	public:
		Player()
		{
			_player = PlayerPointerType(new ConcretPlayer);
		}
	
		~Player() {}

		void doAction()
		{
			_player->doAction();
		}

	private:
		PlayerPointerType _player;
	};

	struct FootbalPlayer
	{
		void doAction();
	};

	struct HockeyPlayer
	{
		void doAction();
	};

	struct PianoPlayer
	{
		void doAction();
	};
}
