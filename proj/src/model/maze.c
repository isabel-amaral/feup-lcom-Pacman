#include "maze.h"
#include "../view/initialize_pixmaps.h"

extern Maze maze;

void set_maze_walls() {
    maze.walls = maze_pixmap;
}