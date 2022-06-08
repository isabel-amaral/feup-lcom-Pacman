#ifndef PACMAN_MOVEMENTS_H
#define PACMAN_MOVEMENTS_H

#include <lcom/lcf.h>

#include "position.h"

#define PACMAN_STEP 5

void moveUp(Position pacman_pos);

void moveDown(Position pacman_pos);

void moveLeft(Position pacman_pos);

void moveRight(Position pacman_pos);

#endif