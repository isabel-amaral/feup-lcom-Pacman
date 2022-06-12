#include <lcom/lcf.h>
#include <lcom/proj.h>

#include <stdio.h>
#include <stdint.h>

#include "devices/timer/timer.h"
#include "devices/kbc/keyboard/keyboard.h"
#include "devices/kbc/mouse/mouse.h"
#include "devices/graphics/graphics.h"
#include "devices/kbc/i8042.h"

#include "controller/game_controller.h"
#include "controller/timer_controller/timer_controller.h"
#include "controller/keyboard_controller/keyboard_controller.h"
#include "controller/mouse_controller/mouse_controller.h"

#include "view/initialize_pixmaps.h"
#include "view/maze_view/maze_view.h"
#include "view/pacman_view/pacman_view.h"
#include "view/ghosts_view/ghosts_view.h"
#include "view/timer_view/timer_view.h"
#include "view/cursor_view/cursor_view.h"
#include "view/menu_view/menu_view.h"

extern bool game_is_on;

extern uint8_t* timer_bit_no;
extern uint8_t* keyboard_bit_no;
extern uint8_t* mouse_bit_no;
unsigned int count = 1;

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

void (menu_loop)() {
  draw_menu();

  message msg;
  int ipc_status, r;
  int mouse_irq_set = BIT(*mouse_bit_no);
  while (game_is_on) {
    if ((r = driver_receive(ANY, &msg, &ipc_status)) != 0 ) { 
      printf("driver_receive failed with: %d", r);
      continue;
    }
    if (is_ipc_notify(ipc_status)) {
      switch (_ENDPOINT_P(msg.m_source)) {
        case HARDWARE:        
            if (msg.m_notify.interrupts & mouse_irq_set) {
              mouse_interrupt_handler();
            }
            break;
        default:
            break;
      }
    }
  }

  erase_menu();
}

void (game_loop)() {
  draw_game_elements();
  count ++;

  message msg;
  int ipc_status, r;
  int timer_irq_set = BIT(*timer_bit_no);
  int keyboard_irq_set = BIT(*keyboard_bit_no);
  while (game_is_on) {
    if ((r = driver_receive(ANY, &msg, &ipc_status)) != 0 ) { 
      printf("driver_receive failed with: %d", r);
      continue;
    }
    if (is_ipc_notify(ipc_status)) {
      switch (_ENDPOINT_P(msg.m_source)) {
        case HARDWARE:        
            if (msg.m_notify.interrupts & timer_irq_set) {
              timer_interrupt_handler();
              erase_timer();
              draw_timer();
            }
            if (msg.m_notify.interrupts & keyboard_irq_set) {
              keyboard_int_handler();
              processKey();
            }
            break;
        default:
            break;
      }
    }
  }
}

int (proj_main_loop)(int argc, char *argv[]) {
  uint16_t mode = 0x105;
  if (graphics_init(mode) != 0) {
    vg_exit();
    return 1;
  }
  initialize_game_elements();
  if (subscribe_devices() != 0) {
    vg_exit();
    return 1;
  }

  menu_loop();
  //game_loop();

  if (unsubscribe_devices() != 0)
    return 1;
  if (vg_exit() != 0)
    return 1;
  return 0;
}


