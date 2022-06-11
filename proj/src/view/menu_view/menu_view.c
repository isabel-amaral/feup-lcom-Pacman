#include <lcom/lcf.h>

#include <stdint.h>

#include "../../devices/graphics/vbe.h"
#include "../../devices/graphics/graphics.h"
#include "../initialize_pixmaps.h"
#include "menu_view.h"

extern uint8_t* pacman_text_pixmap;
extern uint8_t* play_text_pixmap; 
extern uint8_t* rules_text_pixmap; 
extern uint8_t* exit_text_pixmap;

extern xpm_image_t pacman_text_info;
extern xpm_image_t play_text_info;
extern xpm_image_t rules_text_info;
extern xpm_image_t exit_text_info;

void (draw_pacman_text)() {
    draw_xpm(pacman_text_pixmap, pacman_text_info, PACMAN_TEXT_X, PACMAN_TEXT_Y);
}

void (draw_rules_text)() {
    draw_xpm(rules_text_pixmap, rules_text_info, RULES_TEXT_X, RULES_TEXT_Y);
}

void (draw_play_text)() {
    draw_xpm(play_text_pixmap, play_text_info, PLAY_TEXT_X, PLAY_TEXT_Y);
}
void (draw_exit_option)() {
    draw_xpm(exit_text_pixmap, exit_text_info, EXIT_TEXT_X, EXIT_TEXT_Y);
}

void (draw_menu)() {
    draw_pacman_text();
    draw_rules_text();
    draw_play_text();
    draw_exit_option();
}

void (erase_menu)() {
    draw_rectangle(0, 0, 1024, 768, BACKGROUND);
}
