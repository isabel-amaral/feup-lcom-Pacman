#include <lcom/lcf.h>

#include "../../model/ghosts_model/ghost.h"
#include "../../model/pacman_model/pacman.h"
#include "../../view/initialize_pixmaps.h"
#include "ghosts_movement_controller.h"
#include "../collisions_controller/collisions-controller.h"

extern Pacman pacman;
extern Ghost ghosts[4];

bool (moveLeft) (int ghostIndex) {
    Position newPos = ghosts[ghostIndex].pos;
    newPos.left_x -= GHOST_STEP;
    newPos.right_x -= GHOST_STEP;

    if (!maze_collision(newPos) && !ghosts_collision(newPos, ghostIndex)) {
        ghosts[ghostIndex].pos = newPos;
        return true;
    }
    return false;
}

bool (moveRight)(int ghostIndex) {
    Position newPos = ghosts[ghostIndex].pos;
    newPos.left_x += GHOST_STEP;
    newPos.right_x += GHOST_STEP;

    if (!maze_collision(newPos) && !ghosts_collision(newPos, ghostIndex)) {
        ghosts[ghostIndex].pos = newPos;
        return true;
    }
    return false;
}

bool (moveUp)(int ghostIndex) {
    Position newPos = ghosts[ghostIndex].pos;

    newPos.bottom_y -= GHOST_STEP;
    newPos.top_y -= GHOST_STEP;

    if (!maze_collision(newPos) && !ghosts_collision(newPos, ghostIndex)) {
        ghosts[ghostIndex].pos = newPos;
        return true;
    }
    return false;
}

bool (moveDown)(int ghostIndex) {
    Position newPos = ghosts[ghostIndex].pos;
    newPos.bottom_y += GHOST_STEP;
    newPos.top_y += GHOST_STEP;

    if (!maze_collision(newPos) && !ghosts_collision(newPos, ghostIndex)) {
        ghosts[ghostIndex].pos = newPos;
        return true;
    }
    return false;
}

void (move_ghosts)() {
    for (int i=0; i < 4; i++ ) {        
        // Same line and ghost at the left of pacman
        if (ghosts[i].pos.bottom_y == pacman.pos.bottom_y && 
        ghosts[i].pos.right_x < pacman.pos.right_x) 
            moveRight(i);

        //Same line and ghost at the right of pacman
        else if (ghosts[i].pos.bottom_y == pacman.pos.bottom_y && 
        ghosts[i].pos.right_x > pacman.pos.right_x) 
            moveLeft(i);

        //Same column and ghost at the top of pacman
        else if (ghosts[i].pos.left_x == pacman.pos.left_x && 
        ghosts[i].pos.top_y < pacman.pos.top_y)
            moveDown(i);    

        //Same column and ghost at the bottom of pacman
        else if (ghosts[i].pos.left_x == pacman.pos.left_x && 
        ghosts[i].pos.top_y > pacman.pos.top_y)
            moveUp(i); 

        //Pacman at the top left diagonal
        else if (pacman.pos.top_y < ghosts[i].pos.top_y && 
        pacman.pos.right_x < ghosts[i].pos.right_x)
            moveLeft(i);
            
        //Pacman at the top right diagonal
        else if (pacman.pos.top_y < ghosts[i].pos.top_y &&
        pacman.pos.right_x > ghosts[i].pos.right_x)
            moveRight(i);
            
        //Pacman at the bottom left diagonal 
        else if (pacman.pos.top_y > ghosts[i].pos.top_y &&
        pacman.pos.right_x < ghosts[i].pos.right_x) 
            moveLeft(i);
            
        //Pacman at the bottom right diagonal
        else 
            moveRight(i);
    }
}
