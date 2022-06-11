#ifndef MENU_VIEW_H
#define MENU_VIEW_H


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


void (draw_pacman_text)();
void (draw_rules_text)();
void (draw_play_text)();
void (draw_exit_text)();
void (erase_menu)();
void (draw_menu)();

#endif
