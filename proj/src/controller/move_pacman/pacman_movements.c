#include "pacman_movements.h"

void moveLeft(Position pacman_pos){
    pacman_pos.left_x -= PACMAN_STEP;
    pacman_pos.right_x -= PACMAN_STEP;
}

void moveRight(Position pacman_pos){
    pacman_pos.left_x += PACMAN_STEP;
    pacman_pos.right_x += PACMAN_STEP;
}

void moveUp(Position pacman_pos){
    pacman_pos.top_y -= PACMAN_STEP;
    pacman_pos.bottom_y -= PACMAN_STEP;
}

void moveDown(Position pacman_pos){
    pacman_pos.top_y += PACMAN_STEP;
    pacman_pos.bottom_y += PACMAN_STEP;
}