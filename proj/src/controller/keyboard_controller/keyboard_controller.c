#include <lcom/lcf.h>

#include <stdint.h>

#include "../../devices/kbc/keyboard/keyboard.h"
#include "../../devices/kbc/i8042.h"
#include "keyboard_controller.h"
#include "../move_pacman/pacman_movements.h"
#include "view/pacman_view/pacman_view.h"

extern bool make_code;
extern int num_bytes;
extern uint8_t scan_bytes[2];
extern bool full_scancode;
extern bool game_is_on;
bool show = true;

void chooseKey(){
    
    if(num_bytes == 1){
        if(scan_bytes[0] == ESC_MCODE){
            game_is_on = false;
        }
    }

    else if(num_bytes == 2 && scan_bytes[0] == SCAN_MSB){
        switch(scan_bytes[1]){
            case ARROW_UP_MCODE: erase_pacman(); pacmanMoveUp(); break;
            case ARROW_DOWN_MCODE: erase_pacman(); pacmanMoveDown(); break;
            case ARROW_RIGHT_MCODE: erase_pacman(); pacmanMoveRight(); break;
            case ARROW_LEFT_MCODE: erase_pacman(); pacmanMoveLeft(); break;
        }
    }

    if(full_scancode){
        num_bytes = 0;
    }

}
