#pragma once
#include "Player.h"

class HumanPlayer : public Player {
	public:
		HumanPlayer(char mark);
		std::pair<int, int> getMove() const override;
};
