#ifndef PACMAN_MOVEMENTS_H
#define PACMAN_MOVEMENTS_H

#include <lcom/lcf.h>

#include "../../model/pacman.h"
#include "../collisions_controller/collisions-controller.h"

#define PACMAN_STEP 10

void pacmanMoveUp();

void pacmanMoveDown();

void pacmanMoveLeft();

void pacmanMoveRight();

#endif
