#include "pacman_movements.h"

extern Pacman pacman;
extern Position maze_pos;

void pacmanMoveLeft(){
    pacman.pos.left_x -= PACMAN_STEP;
    pacman.pos.right_x -= PACMAN_STEP;
}

void pacmanMoveRight(){
    pacman.pos.left_x += PACMAN_STEP;
    pacman.pos.right_x += PACMAN_STEP;
}

void pacmanMoveUp(){
    pacman.pos.top_y -= PACMAN_STEP;
    pacman.pos.bottom_y -= PACMAN_STEP;
}

void pacmanMoveDown(){
    pacman.pos.top_y += PACMAN_STEP;
    pacman.pos.bottom_y += PACMAN_STEP;
}
