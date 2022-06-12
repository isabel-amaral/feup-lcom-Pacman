#include <lcom/lcf.h>

#include "collisions-controller.h"

bool (pacman_ghost_collision)(Pacman pacman, Ghost ghost[]) {
    for(int i = 0; i < 4; i++) {
        if (pacman.pos.right_x == ghosts[i].pos.left_x ||
        pacman.pos.left_x == ghosts[i].pos.right_x ||
        pacman.pos.bottom_y == ghosts[i].pos.top_y ||
        pacman.pos.top_y == ghosts[i].pos.bottom_y) 
            return true;
    }
    return false;
}

/*bool (pacman_maze_collision)(Pacman pacman, uint8_t* maze_pixmap) {
    for(int i = 0; i < 728; i++)
        if(maze_pixmap[i] == )
    if (pacman.pos.right_x == maze_pixmap ||
        pacman.pos.left_x == maze_pixmap ||
        pacman.pos.bottom_y == maze_pixmap ||
        pacman.pos.top_y == maze_pixmap) 
            return true;
    return false;
}*/

bool (pacman_small_coin_collision)(Pacman pacman, SmallCoin small_coins[]) {
    for(int i = 0; i < 323; i++)
        if (pacman.pos.right_x == small_coins[i].pos.left_x ||
        pacman.pos.left_x == small_coins[i].pos.right_x ||
        pacman.pos.bottom_y == small_coins[i].pos.top_y ||
        pacman.pos.top_y == small_coins[i].pos.bottom_y) 
            return true;
    return false;
}

bool (pacman_big_coin_collision)(Pacman pacman, BigCoin big_coins[]) {
    for(int i = 0; i < 5; i++)
        if (pacman.pos.right_x == big_coins[i].pos.left_x ||
        pacman.pos.left_x == big_coins[i].pos.right_x ||
        pacman.pos.bottom_y == big_coins[i].pos.top_y ||
        pacman.pos.top_y == big_coins[i].pos.bottom_y) 
            return true;
    return false;
}

bool (ghosts_collision)(Ghost ghost[]) {
    for(int i = 0; i < 4; i++)
        for(int j = i + 1; j < 4; j++)
            if (ghosts[i].pos.right_x == ghosts[j].pos.left_x ||
            ghosts[i].pos.left_x == ghosts[j].pos.right_x ||
            ghosts[i].pos.bottom_y == ghosts[j].pos.top_y ||
            ghosts[i].pos.top_y == ghosts[j].pos.bottom_y) 
                return true;
    return false;
}

/*bool (ghost_maze_collision)(Ghost ghosts[], uint8_t* maze_pixmap) {
    if (ghost_pos.right_x ==  ||
        ghost_pos.left_x ==  ||
        ghost_pos.bottom_y ==  ||
        ghost_pos.top_y == ) 
        return true;
    return false;
} */

bool (ghost_small_coin_collision)(Ghost ghost[], SmallCoin small_coins[]) {
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 323; j++)
            if (ghosts[i].pos.right_x == small_coins[j].pos.left_x ||
            ghosts[i].pos.left_x == small_coins[j].pos.right_x ||
            ghosts[i].pos.bottom_y == small_coins[j].pos.top_y ||
            ghosts[i].pos.top_y == small_coins[j].pos.bottom_y) 
                return true;
    return false;
}

bool (ghost_big_coin_collision)(Ghost ghost[], BigCoin big_coins[]) {
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 5; j++)
            if (ghosts[i].pos.right_x == big_coins[j].pos.left_x ||
            ghosts[i].pos.left_x == big_coins[j].pos.right_x ||
            ghosts[i].pos.bottom_y == big_coins[j].pos.top_y ||
            ghosts[i].pos.top_y == big_coins[j].pos.bottom_y) 
                return true;
    return false;
}