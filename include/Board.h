#pragma once
#include <iostream>
#include <vector>
#include <utility>

class Board {
	private:
		char grid[3][3];
	
	public:
		Board();
		void display() const;
		bool isValidMove(int row, int col) const;
		void makeMove(int row, int col, char playerMark);
		bool checkWin(char playerMark) const;
		bool isFull() const;
		std::vector<std::vector<char>> getBoardState() const;
		void setBoardState(const std::vector<std::vector<char>>& state);
};
