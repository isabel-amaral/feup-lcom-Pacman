#ifndef PACMAN_MODEL_H
#define PACMAN_MODEL_H

#include <lcom/lcf.h>

#include "position.h"

typedef struct {
    Position pos;
} Pacman;

void setPosition(Pacman p);

#endif
