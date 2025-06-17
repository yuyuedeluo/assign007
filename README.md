# Pixel Drawing Mimic Game (C++ Console Project)

This is a console-based pixel art mimic game implemented in C++. The player is shown a randomly generated colored pattern on the left side, and must reproduce it on the right side using a brush cursor and color controls.

---

## Gameplay Overview

- A 5x5 pixel grid is randomly generated as a "target image"
- The player uses a movable cursor to "paint" or "erase" on their own canvas
- Submit your result to check for correctness and move to the next level
- More colors are unlocked as levels progress

---

## Features

- Fully playable in Windows terminal (with ANSI color)
- 5 brush colors:  
  - `1` White  
  - `2` Blue  
  - `3` Green  
  - `4` Yellow  
  - `5` Red  
- Brush selection menu (`F`) with dynamic color options depending on level
- Level difficulty increases by unlocking more colors
- Side-by-side board display: target vs player board
- Cursor-aware display with color overlay
- Game scoring and level progression
- Keyboard-controlled, smooth user interaction

---

## Controls

| Key     | Action                          |
|---------|---------------------------------|
| `WASD`  | Move cursor                     |
| `E`     | Paint current square with color |
| `SPACE` | Erase current square            |
| `F`     | Change brush color              |
| `C`     | Submit and compare to target    |
| `R`     | Reset current canvas            |
| `Q`     | Quit the game                   |

---

## Development Structure

- `Board`    – handles answer generation, player state, validation
- `Cursor`   – tracks and moves player cursor
- `View`     – handles visual display with ANSI color output
- `main.cpp` – game loop, input handling, level control

---

## Example Screenshot

```
Level: 3 
Target             Your Board
+-----+            +-----+
|██   |            |██   |
|████ |            |████ |
|  ██ |            |  ██ |
|    |             | X   |
|    |             |     |
+-----+            +-----+
[WASD] Move  [E] Paint
[Space] Erase
[F] Change brush color
[C] Submit   [R] Reset   [Q] Quit
```

---

## Requirements

- Windows with ANSI-compatible terminal (e.g., Windows Terminal or CMD with UTF-8)
- `g++` compiler (MinGW recommended)
- No external libraries required

---

## Repository Structure

```
src/
├── Board.h / Board.cpp
├── Cursor.h / Cursor.cpp
├── View.h / View.cpp
└── main.cpp
```

---

## To Compile

```bash
g++ src/*.cpp -o game.exe
.\game.exe
```

---

## License

This project is for educational use and coursework demonstration only.
