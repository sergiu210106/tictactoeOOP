#include "../include/Game.h"

Game::Game() : playerX('X'), playerO('O'), currentPlayer(&playerX) {}

void Game::play() {
    char choice;
    bool gameRunning = true;

    while (gameRunning) {
        board.display();

        if (isGameOver()) {
            displayGameResult(currentPlayer->getMark());
            gameRunning = false;
            continue;
        }

        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 'm':
        case 'M':
            processMoveInput();
            if (!isGameOver()) {
                switchPlayer();
            }
            break;
        
        case 'u':
        case 'U':
            undo();
            break;

        case 'r':
        case 'R':
            redo();
            break;
        
        case 'q':
        case 'Q':
            std::cout << "Exiting game... Goodbye!\n";
            gameRunning = false;
            break;
        
        default:
            std::cout << "Invalid choice. Please try again.\n";

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }
}

void Game::displayMenu() const {
    std::cout << "Current Player: " << currentPlayer->getMark() << "\n";
    std::cout << "Menu:\n";
    std::cout << "\t(m) Make Move\n";
    std::cout << "\t(u) Undo Last Move\n";
    std::cout << "\t(r) Redo Last Undone Move\n";
    std::cout << "\t(q) Quit Game\n";
}

void Game::processMoveInput() {
    std::pair<int, int> move;
    bool validMoveMade = false;

    while (!validMoveMade) {
        move = currentPlayer->getMove();

        if (board.isValidMove(move.first, move.second)) {
            executeCommand(std::make_unique<MakeMoveCommand>(&board, move.first, move.second, currentPlayer->getMark()));
            validMoveMade = true;
        } else {
            std::cout << "Invalid move! The cell is either out of bounds or already occupied. Please try again.\n";
        }
    }
}

void Game::executeCommand(std::unique_ptr<Command> command) {
    command->execute();
    undoStack.push_back(std::move(command));

    redoStack.clear();
}

void Game::undo() {
    if (! undoStack.empty()) {
        std::unique_ptr<Command> lastCommand = std::move(undoStack.back());
        undoStack.pop_back();

        lastCommand->undo();
        redoStack.push_back(std::move(lastCommand));

        switchPlayer();
        std::cout << "Last move undone.\n";
    } else {
        std::cout << "No moves to undo.\n";
    }
}

void Game::redo() {
    if (! redoStack.empty()) {
        std::unique_ptr<Command> lastUndoneCommand = std::move(redoStack.back());
        redoStack.pop_back();

        lastUndoneCommand->execute();
        undoStack.push_back(std::move(lastUndoneCommand));

        switchPlayer();
        std::cout << "Last move redone.\n";
    } else {
        std::cout << "No moves to redo.\n";
    }
}

bool Game::isGameOver() const {
    if (board.checkWin('X') || board.checkWin('O')) {
        return true;
    }

    if (board.isFull()) {
        return true;
    }

    return false;
}

void Game::switchPlayer() {
    currentPlayer = (currentPlayer == &playerO) ? &playerX : &playerO;
}

void Game::displayGameResult(char lastPlayerMark) const {
    if (board.checkWin(lastPlayerMark)) {
        std::cout << "\nPlayer " << lastPlayerMark << " wins! Congratulations!\n";
    } else if (board.isFull()) {
        std::cout << "\nIt's a draw! The board is full.\n";
    }
    board.display();
}