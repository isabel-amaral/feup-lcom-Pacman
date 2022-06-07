#include <lcom/lcf.h>

#include <stdint.h>

#include "include_xpms.h"

uint8_t* maze_pixmap;
uint8_t* pacman_pixmap;
uint8_t* ghost_red_pixmap;
uint8_t* ghost_orange_pixmap;
uint8_t* ghost_pink_pixmap;
uint8_t* ghost_blue_pixmap;
uint8_t* small_coin_pixmap;
uint8_t* big_coin_pixmap;

uint8_t* cursor_pixmap;
uint8_t* digit0_pixmap, digit1_pixmap, digit2_pixmap, digit3_pixmap, digit4_pixmap, 
    digit5_pixmap, digit6_pixmap, digit7_pixmap, digit8_pixmap, digit9_pixmap;
uint8_t* time_divider_pixmap;
uint8_t* pacman_text_pixmap, play_text_pixmap, rules_text_pixmap, exit_text_pixmap,
    win_text_pixmap, score_text_pixmap, game_over_text_pixmap;

xpm_image_t maze_info;
xpm_image_t pacman_info;
xpm_image_t ghost_red_info;
xpm_image_t ghost_orange_info;
xpm_image_t ghost_pink_info;
xpm_image_t ghost_blue_info;
xpm_image_t small_coin_info;
xpm_image_t big_coin_info;

xpm_image_t cursor_info;
xpm_image_t digit0_info, digit1_info, digit2_info, digit3_info, digit4_info,
    digit5_info, digit6_info, digit7_info, digit8_info, digit9_info;
xpm_image_t time_divider_info;
xpm_image_t pacman_text_info, play_text_info, rules_text_info, exit_text_info,
    win_text_info, score_text_info, game_over_text_info;

void (initialize_maze_pixmap)() {
    maze_pixmap = xpm_load(maze, XPM_INDEXED, &maze_info);
}

void (initialize_pacman_pixmap)() {
    pacman_pixmap = xpm_load(pacman, XPM_INDEXED, &pacman_info);
}

void (initialize_ghost_pixmaps)() {
    ghost_red_pixmap = xpm_load(ghost_red, XPM_INDEXED, &ghost_red_info);
    ghost_orange_pixmap = xpm_load(ghost_orange, XPM_INDEXED, &ghost_orange_info);
    ghost_pink_pixmap = xpm_load(ghost_pink, XPM_INDEXED, &ghost_pink_info);
    ghost_blue_pixmap = xpm_load(ghost_blue, XPM_INDEXED, &ghost_blue_info);
}

void (initialize_coin_pixmaps)() {
    small_coin_pixmap = xpm_load(small_coin, XPM_INDEXED, &small_coin_info);
    big_coin_pixmap = xpm_load(big_coin, XPM_INDEXED, &big_coin_info);
}

void (initialize_menu_button_pixmaps)() {
    pacman_text_pixmap = xpm_load(pacman_text, XPM_INDEXED, &pacman_text_info);
    play_text_pixmap = xpm_load(play_text, XPM_INDEXED, &play_text_info);
    rules_text_pixmap = xpm_load(rules_text, XPM_INDEXED, &rules_text_info);
    exit_text_pixmap = xpm_load(exit_text, XPM_INDEXED, &exit_text_info);
    win_text_pixmap = xpm_load(win_text, XPM_INDEXED, &win_text_info);
    score_text_pixmap = xpm_load(score_text, XPM_INDEXED, &score_text_info);
    game_over_text_pixmap = xpm_load(game_over_text, XPM_INDEXED, &game_over_text_info);
}

void (initialize_util_pixmaps)() {
    cursor_pixmap = xpm_load(cursor, XPM_INDEXED, &cursor_info);

    digit0_pixmap = xpm_load(digit0, XPM_INDEXED, &digit0_info);
    digit1_pixmap = xpm_load(digit1, XPM_INDEXED, &digit1_info);
    digit2_pixmap = xpm_load(digit2, XPM_INDEXED, &digit2_info);
    digit3_pixmap = xpm_load(digit3, XPM_INDEXED, &digit3_info);
    digit4_pixmap = xpm_load(digit4, XPM_INDEXED, &digit4_info);
    digit5_pixmap = xpm_load(digit5, XPM_INDEXED, &digit5_info);
    digit6_pixmap = xpm_load(digit6, XPM_INDEXED, &digit6_info);
    digit7_pixmap = xpm_load(digit7, XPM_INDEXED, &digit7_info);
    digit8_pixmap = xpm_load(digit8, XPM_INDEXED, &digit8_info);
    digit9_pixmap = xpm_load(digit9, XPM_INDEXED, &digit9_info);

    time_divider_pixmap = xpm_load(time_divider, XPM_INDEXED, &time_divider_info);
}

void (initialize_all_pixmaps)() {
    initialize_maze_pixmap();
    initialize_pacman_pixmap();
    initialize_ghost_pixmaps();
    initialize_coin_pixmaps();

    initialize_menu_button_pixmaps();
    initialize_util_pixmaps();
}
