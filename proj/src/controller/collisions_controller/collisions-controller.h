#ifndef COLLISIONS_CONTROLLER_H
#define COLLISIONS_CONTROLLER_H

#include "../../model/pacman_model/pacman.h"
#include "../../model/ghosts_model/ghost.h"
#include "../../model/coins_model/coin.h"

bool (pacman_ghost_collision)(Pacman pacman, Ghost ghost[]);

bool (pacman_maze_collision)(Pacman pacman, uint8_t* maze_pixmap);

bool (pacman_small_coin_collision)(Pacman pacman, SmallCoin small_coins[]);

bool (pacman_big_coin_collision)(Pacman pacman, BigCoin big_coins[]);

bool (ghosts_collision)(Ghost ghost[]);

bool (ghost_maze_collision)(Ghost ghosts[], uint8_t* maze_pixmap);

bool (ghost_small_coin_collision)(Ghost ghost[], SmallCoin small_coins[]);

bool (ghost_big_coin_collision)(Ghost ghost[], BigCoin big_coins[]);

#endif
