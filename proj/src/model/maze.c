#include "maze.h"

extern Maze maze;

void set_maze_walls() {
    xpm_image_t img_info;
    maze.walls = xpm_load(maze_105, XPM_INDEXED, &img_info);
}