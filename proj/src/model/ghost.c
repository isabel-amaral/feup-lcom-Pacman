#include "ghost.h"

Ghost ghosts[4];
// red - blue - pink - orange

void setBluePosition() {
    ghosts[1].pos.left_x = 440;
    ghosts[1].pos.right_x = 465;
    ghosts[1].pos.top_y = 370;
    ghosts[1].pos.bottom_y = 345;
}

void setOrangePosition() {
    ghosts[3].pos.left_x = 560;
    ghosts[3].pos.right_x = 585;
    ghosts[3].pos.top_y = 370;
    ghosts[3].pos.bottom_y = 345;
}

void setPinkPosition() {
    ghosts[2].pos.left_x = 500;
    ghosts[2].pos.right_x = 525;
    ghosts[2].pos.top_y = 370;
    ghosts[2].pos.bottom_y = 345;
}

void setRedPosition() {
    ghosts[0].pos.left_x = 500;
    ghosts[0].pos.right_x = 525;
    ghosts[0].pos.top_y = 310;
    ghosts[0].pos.bottom_y = 330;
}

void setGhostsPositions() {
    setRedPosition();
    setOrangePosition();
    setPinkPosition();
    setBluePosition();
}
