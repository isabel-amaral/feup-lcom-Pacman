#include <lcom/lcf.h>

#include "../../model/pacman_model/pacman.h"
#include "../collisions_controller/collisions-controller.h"
#include "pacman_movement_controller.h"

extern Pacman pacman;
extern uint8_t* pacman_left_pixmap;
extern uint8_t* pacman_right_pixmap;
extern uint8_t* pacman_up_pixmap;
extern uint8_t* pacman_down_pixmap;
extern uint8_t* pacman_pixmap;
extern xpm_image_t pacman_left_info;
extern xpm_image_t pacman_right_info;
extern xpm_image_t pacman_up_info;
extern xpm_image_t pacman_down_info;
extern xpm_image_t pacman_info;

void (pacmanMoveLeft)() {
    pacman.pos.left_x -= PACMAN_STEP;
    pacman.pos.right_x -= PACMAN_STEP;
    pacman_pixmap = pacman_left_pixmap;
    pacman_info = pacman_left_info;
    //pacmanHandlerCollisions();
}

void (pacmanMoveRight)() {
    pacman.pos.left_x += PACMAN_STEP;
    pacman.pos.right_x += PACMAN_STEP;
    pacman_pixmap = pacman_right_pixmap;
    pacman_info = pacman_right_info;
    //pacmanHandlerCollisions();
}

void (pacmanMoveUp)() {
    pacman.pos.top_y -= PACMAN_STEP;
    pacman.pos.bottom_y -= PACMAN_STEP;
    pacman_pixmap = pacman_up_pixmap;
    pacman_info = pacman_up_info;
    //pacmanHandlerCollisions();
}

void (pacmanMoveDown)() {
    pacman.pos.top_y += PACMAN_STEP;
    pacman.pos.bottom_y += PACMAN_STEP;
    pacman_pixmap = pacman_down_pixmap;
    pacman_info = pacman_down_info;
    //pacmanHandlerCollisions();
}

void (pacmanHandlerCollisions)(){

    /*if(pacman_maze_collision()){
        pacman.pos = posAux;
    }

    if(pacman_ghost_collision()){
    }

    if(pacman_coin_collision()){
        if(coin){
            points ++;
        }
        else if(bigCoin){
            points ++;
        }
    }*/
}
