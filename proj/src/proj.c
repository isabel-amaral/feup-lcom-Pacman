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
#include "../assets/ui-elements/pacman.xpm"

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
  draw_xpm(pixmap, img_info, 500, 350);

  sleep(5);
  if (vg_exit() != 0)
    return 1;
  return 0;
}
