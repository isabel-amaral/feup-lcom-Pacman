#include <lcom/lcf.h>
#include <lcom/proj.h>

#include "devices/timer/timer.h"
#include "devices/kbc/keyboard/keyboard.h"
#include "devices/kbc/mouse/mouse.h"
#include "devices/graphics/graphics.h"
#include "devices/kbc/i8042.h"

#include "../assets/digits/digit1.xpm"
#include "../assets/digits/digit2.xpm"
#include "../assets/digits/digit3.xpm"
#include "../assets/digits/digit4.xpm"
#include "../assets/digits/digit5.xpm"
#include "../assets/digits/digit6.xpm"
#include "../assets/digits/digit7.xpm"
#include "../assets/digits/digit8.xpm"
#include "../assets/digits/digit9.xpm"

#include "../assets/ui-elements/maze_105.xpm"
#include "../assets/ui-elements/pacman_105.xpm"
#include "../assets/ui-elements/ghost_red_105.xpm"
#include "../assets/ui-elements/ghost_orange_105.xpm"
#include "../assets/ui-elements/ghost_pink_105.xpm"
#include "../assets/ui-elements/ghost_blue_105.xpm"
#include "../assets/ui-elements/small_coin_105.xpm"
#include "../assets/ui-elements/big_coin_105.xpm"

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
  // uint8_t* pixmap = xpm_load(maze_105, XPM_INDEXED, &img_info);
  // draw_xpm(pixmap, img_info, 148, 20);
  uint8_t* pixmap = xpm_load(pacman, XPM_INDEXED, &img_info);
  draw_xpm(pixmap, img_info, 500, 200);
  pixmap = xpm_load(ghost_red, XPM_INDEXED, &img_info);
  draw_xpm(pixmap, img_info, 500, 300);
  pixmap = xpm_load(ghost_orange, XPM_INDEXED, &img_info);
  draw_xpm(pixmap, img_info, 500, 400);
  pixmap = xpm_load(ghost_pink, XPM_INDEXED, &img_info);
  draw_xpm(pixmap, img_info, 500, 500);
  pixmap = xpm_load(ghost_blue, XPM_INDEXED, &img_info);
  draw_xpm(pixmap, img_info, 500, 600);
  pixmap = xpm_load(small_coin, XPM_INDEXED, &img_info);
  draw_xpm(pixmap, img_info, 480, 100);
  draw_xpm(pixmap, img_info, 490, 100);
  draw_xpm(pixmap, img_info, 500, 100);
  draw_xpm(pixmap, img_info, 510, 100);
  draw_xpm(pixmap, img_info, 520, 100);
  pixmap = xpm_load(big_coin, XPM_INDEXED, &img_info);
  draw_xpm(pixmap, img_info, 530, 100);
  draw_xpm(pixmap, img_info, 540, 100);

  sleep(5);
  if (vg_exit() != 0)
    return 1;
  return 0;
}
