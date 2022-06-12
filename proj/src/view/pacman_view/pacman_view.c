#include <lcom/lcf.h>

#include <stdint.h>

#include "../../devices/graphics/vbe.h"
#include "../../devices/graphics/graphics.h"
#include "../../model/pacman_model/pacman.h"
#include "../initialize_pixmaps.h"
#include "pacman_view.h"

extern Pacman pacman;
extern uint8_t* pacman_left_pixmap;
extern uint8_t* pacman_right_pixmap;
extern uint8_t* pacman_up_pixmap;
extern uint8_t* pacman_down_pixmap;
extern xpm_image_t pacman_left_info;
extern xpm_image_t pacman_right_info;
extern xpm_image_t pacman_up_info;
extern xpm_image_t pacman_down_info;

uint8_t* pacman_pixmap;
xpm_image_t pacman_info;
extern unsigned int count;

void (draw_pacman)() {
    if(count == 1){
        pacman_pixmap = pacman_right_pixmap;
        pacman_info = pacman_right_info;
    }
    draw_xpm(pacman_pixmap, pacman_info, pacman.pos.left_x, pacman.pos.top_y);
}

void (erase_pacman)() {
    draw_rectangle(pacman.pos.left_x, pacman.pos.top_y, pacman_right_info.width, pacman_right_info.height, BACKGROUND);
}
