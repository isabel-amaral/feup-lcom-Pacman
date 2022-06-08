#ifndef GHOST_MODEL_H
#define GHOST_MODEL_H

#include <lcom/lcf.h>

#include "position.h"

typedef struct {
    Position pos; 
} Ghost;

void set_blue_position();

void set_orange_position();

void set_pink_position();

void set_red_position();

void set_ghosts_positions();

#endif
