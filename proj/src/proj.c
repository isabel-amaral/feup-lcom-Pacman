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
  
  uint16_t x1 = 100, x2 = 200, x3 = 300, x4 = 400, x5 = 500, x6 = 600, x7 = 700, x8 = 800, x9 = 900; 
  uint16_t y = 350;

  xpm_image_t img_info;
  uint8_t* pixmap = xpm_load(digit1, XPM_INDEXED, &img_info);
  draw_xpm(pixmap, img_info, x1, y);
  pixmap = xpm_load(digit2, XPM_INDEXED, &img_info);
  draw_xpm(pixmap, img_info, x2, y);
  pixmap = xpm_load(digit3, XPM_INDEXED, &img_info);
  draw_xpm(pixmap, img_info, x3, y);
  pixmap = xpm_load(digit4, XPM_INDEXED, &img_info);
  draw_xpm(pixmap, img_info, x4, y);
  pixmap = xpm_load(digit5, XPM_INDEXED, &img_info);
  draw_xpm(pixmap, img_info, x5, y);
  pixmap = xpm_load(digit6, XPM_INDEXED, &img_info);
  draw_xpm(pixmap, img_info, x6, y);
  pixmap = xpm_load(digit7, XPM_INDEXED, &img_info);
  draw_xpm(pixmap, img_info, x7, y);
  pixmap = xpm_load(digit8, XPM_INDEXED, &img_info);
  draw_xpm(pixmap, img_info, x8, y);
  pixmap = xpm_load(digit9, XPM_INDEXED, &img_info);
  draw_xpm(pixmap, img_info, x9, y);

  sleep(5);
  if (vg_exit() != 0)
    return 1;
  return 0;
}
