#ifndef COLLISIONS_CONTROLLER_H
#define COLLISIONS_CONTROLLER_H

#include "../../model/position.h"
#include "../../model/coins_model/coin.h"
#include "../../model/ghosts_model/ghost.h"
#include "../../model/pacman_model/pacman.h"

bool (pacman_ghost_collision)(Position pacman_pos, Position ghost_pos);

bool (pacman_maze_collision)(Position pacman_pos);

bool (pacman_small_coin_collision)(Position pacman_pos);

bool (pacman_big_coin_collision)(Position pacman_pos);

bool (ghosts_collision)(Position ghost1_pos, Position ghost2_pos);

bool (ghost_maze_collision)(Position ghost_pos);

bool (ghost_small_coin_collision)(Position ghost_pos);

bool (ghost_big_coin_collision)(Position ghost_pos);

#endif
