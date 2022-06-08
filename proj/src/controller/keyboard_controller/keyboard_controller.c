#include "keyboard_controller.h"
#include "pacman_movements.h"

#include <stdint.h>

extern bool make_code;
extern int num_bytes;
extern uint8_t scan_bytes[2];
extern bool full_scancode;
extern Position position;

void chooseKey(){
    if(full_scancode && make_code){

        if(num_bytes == 1){
            if(scan_bytes[0] == SPACEBAR_MCODE){
                /* CHAMAR A FUNÇÃO PARA A PAUSA */
            }
        }

        else if(num_bytes == 2 && scan_bytes[0] == SCAN_MSB){
            switch(scan_bytes[1]){
                case ARROW_UP_MCODE: moveUp(position); break;
                case ARROW_DOWN_MCODE: moveDown(position); break;
                case ARROW_RIGHT_MCODE: moveRight(position); break;
                case ARROW_LEFT_MCODE: moveLeft(position); break;
                default: return;
            }
        }
    }
}
