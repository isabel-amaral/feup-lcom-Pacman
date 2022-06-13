#ifndef COLLISIONS_CONTROLLER_H
#define COLLISIONS_CONTROLLER_H

#include "../../model/position.h"
#include "../../model/coins_model/coin.h"
#include "../../model/ghosts_model/ghost.h"
#include "../../model/pacman_model/pacman.h"

bool (pacman_ghost_collision)();

bool (ghost_pacman_collision)(Position ghost_pos);

bool (maze_collision)(Position position);

bool (pacman_small_coin_collision)();

bool (pacman_big_coin_collision)();

bool (ghosts_collision)(Position newPosition, int ghostIndex);

#endif
