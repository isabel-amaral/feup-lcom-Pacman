#include <lcom/lcf.h>

#include <stdint.h>

#include "game_controller.h"
#include "../devices/timer/timer.h"
#include "../devices/kbc/keyboard/keyboard.h"
#include "../devices/kbc/mouse/mouse.h"

#include "model/pacman_model/pacman.h"
#include "model/ghosts_model/ghost.h"
#include "controller/timer_controller/timer_controller.h"
#include "view/initialize_pixmaps.h"
#include "view/maze_view/maze_view.h"
#include "view/pacman_view/pacman_view.h"
#include "view/ghosts_view/ghosts_view.h"
#include "view/timer_view/timer_view.h"

bool game_is_on = true;

uint8_t* timer_bit_no;

int (subscribe_devices)() {
    timer_bit_no = (uint8_t*) malloc(sizeof(uint8_t));
    if (timer_subscribe_int(timer_bit_no) != 0)
        return 1;
    //ADD OTEHR DEVICES
    return 0;
}

int (unsubscribe_devices)() {
    if (timer_unsubscribe_int() != 0)
        return 1;
    //ADD OTEHR DEVICES
    return 0;
}

void (initialize_game_elements)() {
    set_pacman_position();
    set_ghosts_positions();

    initialize_game_time();

    initialize_all_pixmaps();
    draw_maze();
    draw_pacman();
    draw_ghosts();
    draw_timer();
}
