#include <lcom/lcf.h>

#include <stdint.h>

#include "../../devices/kbc/mouse/mouse.h"
#include "../../view/cursor_view/cursor_view.h"
#include "../../view/menu_view/menu_view.h"
#include "mouse_controller.h"

int mouse_x = 0;
int mouse_y = 0;

extern int packet_index;
extern uint8_t packet_bytes[3];
extern xpm_image_t cursor_info;

void (check_button)() {
    //IMPLEMENT: CHECK IF ONE OF THE MENU BUTTONS WAS CLICKED
}

void (update_cursor)(struct packet pp) {
    erase_cursor();

    if ((mouse_x + pp.delta_x) < 0)
        mouse_x = 0;
    else if ((mouse_x + cursor_info.width + pp.delta_x) >= MENU_WIDTH)
        mouse_x = MENU_WIDTH - cursor_info.width - 1;
    else
        mouse_x += pp.delta_x;

    if ((mouse_y - pp.delta_y) < 0)
        mouse_y = 0;
    else if ((mouse_y + cursor_info.height - pp.delta_y) >= MENU_HEIGHT)
        mouse_y = MENU_HEIGHT - cursor_info.height - 1;
    else
        mouse_y -= pp.delta_y;

    draw_cursor();
    // if (pp.lb)
    //     check_button();
}

void (mouse_interrupt_handler)() {
    mouse_int_handler();
    if (packet_index == 3) {
        struct packet pp;
        parse_mouse_packet(&pp);
        update_cursor(pp);
        packet_index = 0;
    }        
}
