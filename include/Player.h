#pragma once
#include <utility>
#include <iostream>
#include <limits>

class Player {
	protected:
		char playerMark;
	
	public:
		Player(char mark);
		virtual ~Player() = default;
		char getMark() const;
		virtual std::pair<int, int> getMove() const = 0;
};
