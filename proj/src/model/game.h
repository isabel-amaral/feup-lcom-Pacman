#ifndef MAZE_MODEL_H
#define MAZE_MODEL_H

#include <lcom/lcf.h>

#include "maze.h"
#include "pacman.h"
#include "ghost.h"
#include "coin.h"

typedef struct {
    Maze maze;
    Pacman pacman;
    Ghost ghosts[4];
    Coin coin;
} Game;

void set_game_elements();

#endif