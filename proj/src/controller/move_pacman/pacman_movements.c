#include "pacman_movements.h"

void moveLeft(Position pacman_pos){
    pacman_pos.left_x --;
    pacman_pos.right_x --;
}

void moveRight(Position pacman_pos){
    pacman_pos.left_x ++;
    pacman_pos.right_x ++;
}

void moveUp(Position pacman_pos){
    pacman_pos.top_y --;
    pacman_pos.bottom_y --;
}

void moveDown(Position pacman_pos){
    pacman_pos.top_y ++;
    pacman_pos.bottom_y ++;
}