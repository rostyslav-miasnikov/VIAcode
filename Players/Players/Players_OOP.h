#pragma once

namespace OOP 
{
	struct Player
	{
		virtual ~Player() {}
		virtual void doAction() const = 0;
	};

	class FootbalPlayer : public Player
	{
	public:
		void doAction() const;
	};

	class HockeyPlayer : public Player
	{
	public:
		void doAction() const;
		~HockeyPlayer();
	};

} // namespace OOP