#ifndef MAZE_MODEL_H
#define MAZE_MODEL_H

#include <lcom/lcf.h>

typedef struct {
    uint8_t* walls;    
} Maze;

void set_maze_walls();

#endif
