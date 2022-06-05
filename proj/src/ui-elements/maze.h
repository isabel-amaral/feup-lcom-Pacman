#ifndef MAZE_H
#define MAZE_H

#include <lcom/lcf.h>

typedef struct {
    uint8_t* walls;    
} Maze;

void set_maze_walls();

#endif
