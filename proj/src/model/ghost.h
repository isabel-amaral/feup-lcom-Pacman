#ifndef GHOST_MODEL_H
#define GHOST_MODEL_H

#include <lcom/lcf.h>

#include "position.h"

typedef struct {
    Position pos; 
} Ghost;

void setBluePosition();

void setOrangePosition();

void setPinkPosition();

void setRedPosition();

void setGhostsPositions();

#endif
