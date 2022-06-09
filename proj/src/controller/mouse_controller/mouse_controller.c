#include <lcom/lcf.h>

#include <stdint.h>

#include "../../devices/kbc/mouse/mouse.h"
#include "mouse_controller.h"

int mouse_x = 0;
int mouse_y = 0;

extern int packet_index;
extern uint8_t packet_bytes[3];

void (check_button)() {
    //IMPLEMENT: CHECK IF ONE OF THE MENU BUTTONS WAS CLICKED
}

void (update_cursor)(struct packet pp) {
    mouse_x += pp.delta_x;
    mouse_y += pp.delta_y;
    if (pp.lb)
        check_button();
}

void (mouse_interrupt_handler)() {
    mouse_int_handler();
    if (packet_index == 3) {
        struct packet pp;
        parse_mouse_packet(&pp);
        packet_index = 0;
    }        
}
