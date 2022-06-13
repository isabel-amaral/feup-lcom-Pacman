#ifndef MENU_VIEW_H
#define MENU_VIEW_H

#define MENU_WIDTH 1024
#define MENU_HEIGHT 768

#define PACMAN_TEXT_X 244
#define PACMAN_TEXT_Y 100
#define PACMAN_TEXT_WIDTH 536
#define PACMAN_TEXT_HEIGHT 100

#define RULES_TEXT_X 366
#define RULES_TEXT_Y 276
#define RULES_TEXT_WIDTH 292
#define RULES_TEXT_HEIGHT 80

#define PLAY_TEXT_X 389
#define PLAY_TEXT_Y 432
#define PALY_TEXT_WIDTH 246
#define PLAY_TEXT_HEIGHT 80

#define EXIT_TEXT_X 392
#define EXIT_TEXT_Y 588
#define EXIT_TEXT_WIDTH 240
#define EXIT_TEXT_HEIGHT 80

#define WIN_TEXT_X 401
#define WIN_TEXT_Y 100

#define GAME_OVER_TEXT_X 191
#define GAME_OVER_TEXT_Y 100

#define SCORE_TEXT_X 339
#define SCORE_TEXT_Y 300

#define PAUSE_TEXT_X 355
#define PAUSE_TEXT_Y 344

#define RULES_DESCRIPTION1_X 65
#define RULES_DESCRIPTION1_Y 65
#define RULES_DESCRIPTION2_X 65
#define RULES_DESCRIPTION2_Y 165
#define RULES_DESCRIPTION3_X 65
#define RULES_DESCRIPTION3_Y 265
#define RULES_DESCRIPTION4_X 65
#define RULES_DESCRIPTION4_Y 365
#define RULES_DESCRIPTION5_X 65
#define RULES_DESCRIPTION5_Y 465
#define RULES_DESCRIPTION6_X 65
#define RULES_DESCRIPTION6_Y 565

#define BACK_TO_MENU_X 65
#define BACK_TO_MENU_Y 865
#define BACK_TO_MENU_WIDTH 180
#define BACK_TO_MENU_HEIGHT 22

void (draw_pacman_text)();

void (draw_rules_text)();

void (draw_play_text)();

void (draw_exit_text)();

void (draw_win_text)();

void (draw_game_over_text)();

void (draw_score_text)();

void (draw_pause_text)();

void (draw_menu)();

void (erase_menu)();

void (draw_rules_description)();

void (draw_win_menu)();

void (draw_game_over_menu)();

#endif
