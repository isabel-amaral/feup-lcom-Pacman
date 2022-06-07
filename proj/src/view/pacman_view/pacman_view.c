#include <lcom/lcf.h>

#include <stdint.h>

#include "../../devices/graphics/vbe.h"
#include "../../devices/graphics/graphics.h"
#include "../../model/pacman.h"
#include "../initialize_pixmaps.h"
#include "pacman_view.h"

extern Pacman pacman;
extern uint8_t* pacman_pixmap;
extern xpm_image_t pacman_info;

void (draw_pacman)() {
    draw_xpm(pacman_pixmap, pacman_info, pacman.pos.left_x, pacman.pos.top_y);
}

void (erase_pacman)() {
    draw_rectangle(pacman.pos.left_x, pacman.pos.top_y, pacman_info.width, pacman_info.height, BACKGROUND);
}
