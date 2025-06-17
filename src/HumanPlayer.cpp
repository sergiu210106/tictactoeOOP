#include "../include/HumanPlayer.h"

HumanPlayer::HumanPlayer(char mark) : Player(mark) {}

std::pair<int, int> HumanPlayer::getMove() const {
	int row, col;
	std::cout << "Player " << playerMark << ", enter your move (row and column, e.g., 0 1 for top middle): ";
	while (!(std::cin >> row >> col)) {
		std::cout << "Invalid Input. Please enter numbers for row and column: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	return {row, col};
}


