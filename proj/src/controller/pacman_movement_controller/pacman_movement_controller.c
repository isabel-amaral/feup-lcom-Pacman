#include <lcom/lcf.h>

#include "pacman_movement_controller.h"
#include "../collisions_controller/collisions-controller.h"
#include "../timer_controller/timer_controller.h"
#include "../../model/pacman_model/pacman.h"
#include "../../view/menu_view/menu_view.h"

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
extern unsigned int score;
Position pacmanPosAux;

void (pacmanMoveLeft)() {
    pacmanPosAux = pacman.pos;
    pacman.pos.left_x -= PACMAN_STEP;
    pacman.pos.right_x -= PACMAN_STEP;
    pacman_pixmap = pacman_left_pixmap;
    pacman_info = pacman_left_info;
    pacmanHandlerCollisions();
}

void (pacmanMoveRight)() {
    pacmanPosAux = pacman.pos;
    pacman.pos.left_x += PACMAN_STEP;
    pacman.pos.right_x += PACMAN_STEP;
    pacman_pixmap = pacman_right_pixmap;
    pacman_info = pacman_right_info;
    pacmanHandlerCollisions();
}

void (pacmanMoveUp)() {
    pacmanPosAux = pacman.pos;
    pacman.pos.top_y -= PACMAN_STEP;
    pacman.pos.bottom_y -= PACMAN_STEP;
    pacman_pixmap = pacman_up_pixmap;
    pacman_info = pacman_up_info;
    pacmanHandlerCollisions();
}

void (pacmanMoveDown)() {
    pacmanPosAux = pacman.pos;
    pacman.pos.top_y += PACMAN_STEP;
    pacman.pos.bottom_y += PACMAN_STEP;
    pacman_pixmap = pacman_down_pixmap;
    pacman_info = pacman_down_info;
    pacmanHandlerCollisions();
}

void (pacmanHandlerCollisions)(){

    if(pacman_maze_collision(pacman.pos)){
        pacman.pos = pacmanPosAux;
    }

    /*if(pacman_ghost_collision(pacman.pos)){
        // devolta à posição inicial;
    }*/

    if(pacman_small_coin_collision(pacman.pos)){  
        score += SCORE;
    }

    if(pacman_big_coin_collision(pacman.pos)){
        //increase_time();
    }
}
