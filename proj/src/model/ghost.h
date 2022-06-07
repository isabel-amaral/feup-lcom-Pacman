#ifndef GHOST_MODEL_H
#define GHOST_MODEL_H

#include <lcom/lcf.h>

#include "position.h"

typedef struct {
    Position pos; 
} Ghost;

void setBluePosition(Ghost g);
void setOrangePosition(Ghost g);
void setPinkPosition(Ghost g);
void setRedPosition(Ghost g);

#endif
