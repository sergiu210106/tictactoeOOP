#include "../include/Board.h"

Board::Board() {
	for (int i = 0; i < 3; i ++) {
		for (int j = 0; j < 3; j ++) {
			grid[i][j] = ' ';
		}
	}
}

void Board::display() const {
	std::cout << '\n';

	for (int i = 0; i < 3; i ++) {
		for (int j = 0; j < 3; j ++) {
			std::cout << ' ' << grid[i][j];

			if (j < 2) {
				std::cout << " |";
			}
		}
		if (i < 2) {
			std::cout << "\n---+---+---\n";
		}
	}

	std::cout << '\n';
}

bool Board::isValidMove(int row, int col) const {
	return (0 <= row and row < 3 and 0 <= col and col < 3 and grid[row][col] == ' ');
}

void Board::makeMove(int row, int col, char playerMark) {
	grid[row][col] = playerMark;
}

bool Board::checkWin(char playerMark) const {
	// check rows
	for (int row = 0; row < 3; row ++) {
		if (grid[row][0] == playerMark and grid[row][1] == playerMark and grid[row][2] == playerMark) {
			return true;
		}
	}

	// check cols
	for (int col = 0; col < 3; col ++) {
		if (grid[0][col] == playerMark and grid[1][col] == playerMark and grid[2][col] == playerMark) {
			return true;
		}
	}

	// check diagonals
	if (grid[0][0] == playerMark and grid[1][1] == playerMark and grid[2][2] == playerMark) {
		return true;
	}
	if (grid[0][2] == playerMark and grid[1][1] == playerMark and grid[2][0] == playerMark) {
		return true;
	}
	return false;
}

bool Board::isFull() const {
	for (int row = 0; row < 3; row ++) {
		for (int col = 0; col < 3; col ++) {
			if (grid[row][col] == ' ') {
				return false;
			}
		}
	}
	return true;
}

std::vector<std::vector<char>> Board::getBoardState() const {
	std::vector<std::vector<char>> state(3, std::vector<char>(3));

	for (int row = 0; row < 3; row ++) {
		for (int col = 0; col < 3; col ++) {
			state[row][col] = grid[row][col];
		}
	}

	return state;
}

void Board::setBoardState(const std::vector<std::vector<char>>& state) {
	for (int row = 0; row < 3; row ++) {
		for (int col = 0; col < 3; col ++) {
			grid[row][col] = state[row][col];
		}
	}
}



