#include "collisions-controller.h"

bool pacman_ghost_collision(Position pacman_pos, Position ghost_pos) {
    if(pacman_pos.right_x == ghost_pos.left_x ||
       pacman_pos.left_x == ghost_pos.right_x ||
       pacman_pos.bottom_y == ghost_pos.top_y ||
       pacman_pos.top_y == ghost_pos.bottom_y) return true;

    return false;
}

bool pacman_maze_collision(Position pacman_pos, Position maze_pos) {
    if(pacman_pos.right_x == maze_pos.left_x ||
       pacman_pos.left_x == maze_pos.right_x ||
       pacman_pos.bottom_y == maze_pos.top_y ||
       pacman_pos.top_y == maze_pos.bottom_y) return true;

    return false;
}

bool pacman_coin_collision(Position pacman_pos, Position coin_pos) {
    if(pacman_pos.right_x == coin_pos.left_x ||
       pacman_pos.left_x == coin_pos.right_x ||
       pacman_pos.bottom_y == maze_pos.top_y ||
       pacman_pos.top_y == maze_pos.bottom_y) return true;

    return false;
}

bool ghosts_collision(Position ghost1_pos, Position ghost2_pos) {
    if(ghost1_pos.right_x == ghost2_pos.left_x ||
       ghost1_pos.left_x == ghost2_pos.right_x ||
       ghost1_pos.bottom_y == ghost2_pos.top_y ||
       ghost1_pos.top_y == ghost2_pos.bottom_y) return true;

    return false;
}

bool ghost_maze_collision(Position ghost_pos, Position maze_pos) {
    if(ghost_pos.right_x == maze_pos.left_x ||
       ghost_pos.left_x == maze_pos.right_x ||
       ghost_pos.bottom_y == maze_pos.top_y ||
       ghost_pos.top_y == maze_pos.bottom_y) return true;

    return false;
}

bool ghost_coin_collision(Position ghost_pos, Position coin_pos) {
    if(ghost_pos.right_x == coin_pos.left_x ||
       ghost_pos.left_x == coin_pos.right_x ||
       ghost_pos.bottom_y == maze_pos.top_y ||
       ghost_pos.top_y == maze_pos.bottom_y) return true;

    return false;
}