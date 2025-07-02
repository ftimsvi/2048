# 2048 Persian – Console-Based Number Puzzle Game

This project is a Persian-language console-based version of the classic **2048 game**, developed as part of my university programming coursework.

The game enhances the standard 2048 experience by offering multiple difficulty levels, save/load functionality, scoring history, and undo options.

## 🎮 Game Features

- **Move Tiles:** Use arrow keys (Up, Down, Left, Right) to move the blocks.
- **Merge Tiles:** Blocks with the same number merge when they collide.
- **Random Block Generation:** After every move, a new block (2, 4, 8, 16, 32) appears based on defined probabilities.

### Block Generation Probabilities:

| Block | Probability |
|-------|-------------|
| 2     | 65%         |
| 4     | 25%         |
| 8     | 6%          |
| 16    | 2%          |
| 32    | 2%          |

## 🧩 Game Modes

Start a new game with one of the following difficulty levels:

- **Easy:** 6×6 grid
- **Medium:** 5×5 grid
- **Hard:** 4×4 grid
- **Custom:** User-defined grid size

## 💾 Save & Load

- Save the game progress along with difficulty level, max score, and timestamp.
- Load a saved game at any time.

## 🕹️ Gameplay Functionality

- **Undo:** Return up to 5 moves back.
- **Reset:** Restart the game from the beginning.
- **Exit:** Quit and return to the main menu.
- **Auto-save:** Game automatically saves at key events.

## 📈 Score and Leaderboard

- Tracks the top 5 scores per difficulty level.
- If a new score is higher than the lowest saved score, it is recorded and saved.

## 📜 Game History

- View past games including:
  - Final score
  - Win/Loss outcome
  - Game duration
  - Date and time

## 📚 Educational Purpose

This project was developed as part of my **Basic Programming** course to practice:

- Game logic implementation
- File I/O
- Control flow
- Array and matrix manipulation
- Random number generation
- Working with custom data structures

---
