#pragma once

#include "Board.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "Command.h"
#include "MakeMoveCommand.h"

#include <vector>
#include <memory>
#include <iostream>
#include <limits>

class Game {
    private: 
        // attributes
        Board board;
        HumanPlayer playerX;
        HumanPlayer playerO;
        Player* currentPlayer;

        std::vector<std::unique_ptr<Command>> undoStack;
        std::vector<std::unique_ptr<Command>> redoStack;

        // methods
        void displayMenu() const;
        void processMoveInput();
        void executeCommand(std::unique_ptr<Command> command);
        void undo();
        void redo();

        bool isGameOver() const;
        void switchPlayer();
        void displayGameResult(char lastPlayerMark) const;

    public:
        Game();
        void play();

};