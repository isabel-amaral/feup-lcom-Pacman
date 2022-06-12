#include <lcom/lcf.h>

#include "../../model/pacman_model/pacman.h"
#include "../collisions_controller/collisions-controller.h"
#include "pacman_movement_controller.h"

extern Pacman pacman;

void (pacmanMoveLeft)() {
    pacman.pos.left_x -= PACMAN_STEP;
    pacman.pos.right_x -= PACMAN_STEP;
}

void (pacmanMoveRight)() {
    pacman.pos.left_x += PACMAN_STEP;
    pacman.pos.right_x += PACMAN_STEP;
}

void (pacmanMoveUp)() {
    pacman.pos.top_y -= PACMAN_STEP;
    pacman.pos.bottom_y -= PACMAN_STEP;
}

void (pacmanMoveDown)() {
    pacman.pos.top_y += PACMAN_STEP;
    pacman.pos.bottom_y += PACMAN_STEP;
}
