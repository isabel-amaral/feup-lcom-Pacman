#include "ghost.h"

Ghost ghosts[4];
// red - blue - pink - orange

void setBluePosition() {
    ghosts[1].pos.left_x = 427;
    ghosts[1].pos.right_x = 452;
    ghosts[1].pos.top_y = 377;
    ghosts[1].pos.bottom_y = 352;
}

void setOrangePosition() {
    ghosts[3].pos.left_x = 547;
    ghosts[3].pos.right_x = 752;
    ghosts[3].pos.top_y = 377;
    ghosts[3].pos.bottom_y = 352;
}

void setPinkPosition() {
    ghosts[2].pos.left_x = 487;
    ghosts[2].pos.right_x = 512;
    ghosts[2].pos.top_y = 377;
    ghosts[2].pos.bottom_y = 352;
}

void setRedPosition() {
    ghosts[0].pos.left_x = 487;
    ghosts[0].pos.right_x = 512;
    ghosts[0].pos.top_y = 302;
    ghosts[0].pos.bottom_y = 327;
}

void setGhostsPositions() {
    setRedPosition();
    setOrangePosition();
    setPinkPosition();
    setBluePosition();
}
