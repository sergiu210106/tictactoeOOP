# Tic-Tac-Toe OOP Game

A command-line Tic-Tac-Toe game built with C++ using Object-Oriented Programming (OOP) principles, featuring two-player mode and undo/redo functionality.

---

## Features

* **Two-Player Mode**: Play against a friend on the same console.

* **OOP Design**: Organized and extensible code using classes for `Board`, `Player`, `HumanPlayer`, `Command`, `MakeMoveCommand`, and `Game`.

* **Undo/Redo Functionality**: Go back multiple moves or re-apply previously undone moves, thanks to the **Command Pattern**.

---

## How to Compile

To compile the game, you'll need a C++ compiler (like g++).

1.  **Navigate to the project root**:

    ```bash
    cd /mnt/d/facultate/code/projects/tictactoeOOP
    ```

2.  **Compile the source files**:
    Use the following command to compile all `.cpp` files in the `src` directory, including the `include` directory for headers:

    ```bash
    g++ -Iinclude src/*.cpp -o app
    ```

    This will create an executable named `app` (or whatever you specify after `-o`).

---

## How to Run

After successful compilation, you can run the game from your terminal:

```bash
./app
```

---

## Gameplay

The game will display the board and prompt the current player for their move (row and column). You can also choose to undo or redo moves.

### Available Commands:

* `m` (Make Move): Enter the row and column (e.g., `0 0` for the top-left cell).

* `u` (Undo Last Move): Reverts the last move made. You can undo multiple times.

* `r` (Redo Last Undone Move): Re-applies a move that was undone.

* `q` (Quit Game): Exit the game.

### Example Interaction:

```
Initial Board:

   |   |
---+---+---
   |   |
---+---+---
   |   |

Current Player: X
Menu:
  (m) Make Move
  (u) Undo Last Move
  (r) Redo Last Undone Move
  (q) Quit Game
Enter your choice: m
Player X, enter your move (row and column, e.g., 0 1 for top middle): 0 0
Board after Player X's move:

 X |   |
---+---+---
   |   |
---+---+---
   |   |

Current Player: O
Menu:
  (m) Make Move
  (u) Undo Last Move
  (r) Redo Last Undone Move
  (q) Quit Game
Enter your choice: u
Last move undone.
Current Player: X
Menu:
  (m) Make Move
  (u) Undo Last Move
  (r) Redo Last Undone Move
  (q) Quit Game
Enter your choice:
