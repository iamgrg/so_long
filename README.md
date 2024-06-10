![So Long](https://github.com/iamgrg/so_long/assets/80717523/81abc4f6-061f-4e2d-986f-57284bdc7049)

# So Long - 2D Game Project

## Overview

`So Long` is a small 2D game that combines simple gameplay mechanics with basic graphic rendering. The project focuses on handling textures, sprites, and other game elements using the MiniLibX library.

## Objectives

The primary goals of this project are to:
- Learn to manage windows and handle events in a graphical environment.
- Understand and apply textures and sprites in game development.
- Enhance skills in C programming and use of the MiniLibX library.

## Build Instructions

Compile the game using the Makefile provided. Ensure you have MiniLibX installed on your system. To compile the project, execute:

```bash
make all
```

##  Gameplay
To start the game, run the following command with a map file:

```bash
./so_long your_map.ber
```

## Controls

WASD keys to move the player up, left, down, and right.
ESC or clicking the close button will exit the game.

##  Game Rules
Collect all collectibles on the map to unlock the exit.
Avoid walls and navigate through the map to reach the exit.
The game counts and displays the number of moves in the terminal.

## Map Configuration

Maps are defined with the following characters:

0 for empty space
1 for walls
C for collectibles
E for exit
P for player's starting position
Maps should be rectangular and enclosed by walls. A valid path from the player to the exit must exist.

##  Features

Simple collision detection.
Count and display the number of moves.
Smooth window management and exit.

##  Contributors

- @iamgrg

## License

![MIT License](https://img.shields.io/badge/license-MIT-green)
Distributed under the MIT License.
