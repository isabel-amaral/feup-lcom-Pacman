#ifndef COLLISIONS_CONTROLLER_H
#define COLLISIONS_CONTROLLER_H

bool (pacman_ghost_collision)(Position pacman_pos, Position ghost_pos);

bool (pacman_maze_collision)(Position pacman_pos, Position maze_pos);

bool (pacman_coin_collision)(Position pacman_pos, Position coin_pos);

bool (ghosts_collision)(Position ghost1_pos, Position ghost2_pos);

bool (ghost_maze_collision)(Position ghost_pos, Position maze_pos);

bool (ghost_coin_collision)(Position ghost_pos, Position coin_pos);

#endif
