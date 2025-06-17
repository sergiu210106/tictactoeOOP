#include "../include/MakeMoveCommand.h"
#include <iostream>

MakeMoveCommand::MakeMoveCommand(Board * b, int r, int c, char mark) : 
board(b), row(r), col(c), playerMark(mark) {}

void MakeMoveCommand::execute() {
    if (board) {
        previousBoardState = board->getBoardState();
        board->makeMove(row, col, playerMark);
    } else {
        std::cerr << "Error: Board pointer is null in MakeMoveCommand::execute()\n";
    }
}

void MakeMoveCommand::undo() {
    if (board) {
        board->setBoardState(previousBoardState);
    } else {
        std::cerr << "Error: Board pointer is null in MakeMoveCommand::undo()\n";
    }
}