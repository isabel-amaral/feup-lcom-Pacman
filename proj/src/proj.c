#include <lcom/lcf.h>
#include <lcom/proj.h>

#include "devices/timer/timer.h"
#include "devices/kbc/keyboard/keyboard.h"
#include "devices/kbc/mouse/mouse.h"
#include "devices/graphics/graphics.h"
#include "devices/kbc/i8042.h"

#include "../assets/utils/digits/digit1.xpm"
#include "../assets/utils/digits/digit2.xpm"
#include "../assets/utils/digits/digit3.xpm"
#include "../assets/utils/digits/digit4.xpm"
#include "../assets/utils/digits/digit5.xpm"
#include "../assets/utils/digits/digit6.xpm"
#include "../assets/utils/digits/digit7.xpm"
#include "../assets/utils/digits/digit8.xpm"
#include "../assets/utils/digits/digit9.xpm"
#include "../assets/utils/time/time-divider.xpm"

#include "../assets/utils/words/pacman_text.xpm"
#include "../assets/utils/words/play_text.xpm"
#include "../assets/utils/words/rules_text.xpm"
#include "../assets/utils/words/exit_text.xpm"
#include "../assets/utils/words/win_text.xpm"
#include "../assets/utils/words/score_text.xpm"
#include "../assets/utils/words/game_over_text.xpm"

#include "../assets/utils/cursor/cursor.xpm"

#include "../assets/ui-elements/maze.xpm"
#include "../assets/ui-elements/pacman.xpm"
#include "../assets/ui-elements/ghost_red.xpm"
#include "../assets/ui-elements/ghost_orange.xpm"
#include "../assets/ui-elements/ghost_pink.xpm"
#include "../assets/ui-elements/ghost_blue.xpm"
#include "../assets/ui-elements/small_coin.xpm"
#include "../assets/ui-elements/big_coin.xpm"

#include <stdio.h>

int main(int argc, char *argv[]) {
  // sets the language of LCF messages (can be either EN-US or PT-PT)
  lcf_set_language("EN-US");

  // enables to log function invocations that are being "wrapped" by LCF
  // [comment this out if you don't want/need/ it]
  lcf_trace_calls("/home/lcom/labs/lab4/trace.txt");

  // enables to save the output of printf function calls on a file
  // [comment this out if you don't want/need it]
  lcf_log_output("/home/lcom/labs/lab4/output.txt");

  // handles control over to LCF
  // [LCF handles command line arguments and invokes the right function]
  if (lcf_start(argc, argv))
    return 1;

  // LCF clean up tasks
  // [must be the last statement before return]
  lcf_cleanup();

  return 0;
}

int (proj_main_loop)(int argc, char *argv[]) {
  uint16_t mode = 0x105;
  if (graphics_init(mode) != 0) {
    vg_exit();
    return 1;
  }

  xpm_image_t img_info;
  // uint8_t* pixmap = xpm_load(pacman_text, XPM_INDEXED, &img_info);
  // draw_xpm(pixmap, img_info, 244, 100);
  // pixmap = xpm_load(play_text, XPM_INDEXED, &img_info);
  // draw_xpm(pixmap, img_info, 389, 250);
  // pixmap = xpm_load(rules_text, XPM_INDEXED, &img_info);
  // draw_xpm(pixmap, img_info, 366, 350);
  // pixmap = xpm_load(exit_text, XPM_INDEXED, &img_info);
  // draw_xpm(pixmap, img_info, 392, 450);

  // uint8_t* pixmap = xpm_load(win_text, XPM_INDEXED, &img_info);
  // draw_xpm(pixmap, img_info, 401, 150);
  // pixmap = xpm_load(score_text, XPM_INDEXED, &img_info);
  // draw_xpm(pixmap, img_info, 339, 250);
  // pixmap = xpm_load(game_over_text, XPM_INDEXED, &img_info);
  // draw_xpm(pixmap, img_info, 191, 350);

  uint8_t* pixmap = xpm_load(cursor, XPM_INDEXED, &img_info);
  draw_xpm(pixmap, img_info, 500, 350);

  sleep(5);
  if (vg_exit() != 0)
    return 1;
  return 0;
}
