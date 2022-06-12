#include <lcom/lcf.h>

#include "collisions-controller.h"

Ghost ghosts[4];
BigCoin big_coins[5];
SmallCoin small_coins[329];
uint8_t* maze_pixmap;

bool (pacman_ghost_collision)(Position pacman_pos, Position ghost_pos) {
    if (pacman_pos.right_x == ghost_pos.left_x ||
    pacman_pos.left_x == ghost_pos.right_x ||
    pacman_pos.bottom_y == ghost_pos.top_y ||
    pacman_pos.top_y == ghost_pos.bottom_y) 
        return true;
    return false;
}

bool (pacman_maze_collision)(Position pacman_pos) {
    for(int i = 0; i < 728) {
        for(int j = 0; j < 728; j++) {
            if(maze_pixmap == 1) {
                if(ghost_pos.top_y <= j && ghost_pos.bottom_y >= j) {
                        if(pacman_pos.right_x <= i && pacman_pos.left_x >= i) {
                            return true;
                        }
                }
            maze_pixmap++;
            }
        }
    }
    return false;
}

bool (pacman_small_coin_collision)(Position pacman_pos) {
    for(int i = 0; i < 323; i++)
        if (pacman_pos.right_x == small_coins[i].pos.left_x ||
        pacman_pos.left_x == small_coins[i].pos.right_x ||
        pacman_pos.bottom_y == small_coins[i].pos.top_y ||
        pacman_pos.top_y == small_coins[i].pos.bottom_y) 
            return true;
    return false;
}

bool (pacman_big_coin_collision)(Position pacman_pos) {
    for(int i = 0; i < 5; i++)
        if (pacman_pos.right_x == big_coins[i].pos.left_x ||
        pacman_pos.left_x == big_coins[i].pos.right_x ||
        pacman_pos.bottom_y == big_coins[i].pos.top_y ||
        pacman_pos.top_y == big_coins[i].pos.bottom_y) 
            return true;
    return false;
}

bool (ghosts_collision)(Position ghost1_pos, Position ghost2_pos) {
    if (ghost1_pos.right_x == ghost2_pos.left_x ||
    ghost1_pos.left_x == ghost2_pos.right_x ||
    ghost1_pos.bottom_y == ghost2_pos.top_y ||
    ghost1_pos.pos.top_y == ghost2_pos.bottom_y) 
        return true;
    return false;
}

bool (ghost_maze_collision)(Position ghost_pos) {
    for(int i = 0; i < 728) {
        for(int j = 0; j < 728; j++) {
            if(maze_pixmap == 1) {
                if(ghost_pos.top_y <= j && ghost_pos.bottom_y >= j) {
                    if(ghost_pos.right_x <= i && ghost_pos.left_x >= i) {
                        return true;
                    }
                }
            }
            maze_pixmap++;
        }
    }

    return false;
}

bool (ghost_small_coin_collision)(Position ghost_pos) {
    for(int j = 0; j < 323; j++)
        if (ghost_pos.right_x == small_coins[j].pos.left_x ||
        ghost_pos.left_x == small_coins[j].pos.right_x ||
        ghost_pos.bottom_y == small_coins[j].pos.top_y ||
        ghost_pos.pos.top_y == small_coins[j].pos.bottom_y) 
            return true;
    return false;
}

bool (ghost_big_coin_collision)(Position ghost_pos) {
    for(int j = 0; j < 5; j++)
        if (ghost_pos.pos.right_x == big_coins[j].pos.left_x ||
        ghost_pos.pos.left_x == big_coins[j].pos.right_x ||
        ghost_pos.pos.bottom_y == big_coins[j].pos.top_y ||
        ghost_pos.pos.top_y == big_coins[j].pos.bottom_y) 
            return true;
    return false;
}