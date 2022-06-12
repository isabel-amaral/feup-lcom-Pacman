#include <lcom/lcf.h>

#include <stdint.h>

#include "../../devices/kbc/keyboard/keyboard.h"
#include "../../devices/kbc/i8042.h"
#include "../pacman_movement_controller/pacman_movement_controller.h"
#include "../../view/pacman_view/pacman_view.h"
#include "keyboard_controller.h"

extern bool make_code;
extern int num_bytes;
extern uint8_t scan_bytes[2];
extern bool full_scancode;
extern bool game_is_on;

void (processKey)() {
    printf("Hello\n");
    
    if (num_bytes == 1 && scan_bytes[0] == ESC_MCODE) {
        game_is_on = false;
        return;
    }

    if (num_bytes == 2 && scan_bytes[0] == SCAN_MSB){
        switch (scan_bytes[1]) {
            case ARROW_UP_MCODE: 
                erase_pacman(); 
                pacmanMoveUp();
                draw_pacman();
                break;
            case ARROW_DOWN_MCODE: 
                erase_pacman(); 
                pacmanMoveDown(); 
                draw_pacman();
                break;
            case ARROW_RIGHT_MCODE: 
                erase_pacman(); 
                pacmanMoveRight(); 
                draw_pacman();
                break;
            case ARROW_LEFT_MCODE: 
                erase_pacman(); 
                pacmanMoveLeft(); 
                draw_pacman();
                break;
        }
    }

    if (full_scancode)
        num_bytes = 0;
}
