#pragma once

#include "Command.h"
#include "Board.h"
#include <vector>
#include <utility>

class MakeMoveCommand : public Command {
    private:
        Board * board;
        int row, col;
        char playerMark;
        std::vector<std::vector<char>> previousBoardState;

    public:
        MakeMoveCommand(Board * b, int r, int c, char mark);
        void execute() override;
        void undo() override;
};