// IMPORTANT: you must include the following line in all your C files
#include <lcom/lcf.h>
#include <lcom/lab5.h>

#include "i8254.h"
#include "i8042.h"
#include "keyboard.h"
#include "video_gr.h"
#include <stdint.h>
#include <stdio.h>

extern int vg_init_success;
extern unsigned int int_counter;
extern int ih_success;
extern bool make_code;
extern int num_bytes;
extern uint8_t scan_bytes[2];
extern bool full_scancode;

// Any header files included below this line should have been created by you

int main(int argc, char *argv[]) {
  // sets the language of LCF messages (can be either EN-US or PT-PT)
  lcf_set_language("EN-US");

  // enables to log function invocations that are being "wrapped" by LCF
  // [comment this out if you don't want/need it]
  lcf_trace_calls("/home/lcom/labs/lab5/trace.txt");

  // enables to save the output of printf function calls on a file
  // [comment this out if you don't want/need it]
  lcf_log_output("/home/lcom/labs/lab5/output.txt");

  // handles control over to LCF
  // [LCF handles command line arguments and invokes the right function]
  if (lcf_start(argc, argv))
    return 1;

  // LCF clean up tasks
  // [must be the last statement before return]
  lcf_cleanup();

  return 0;
}

int(video_test_init)(uint16_t mode, uint8_t delay) {
  vg_init(mode);
  if (vg_init_success)
    return 1;

  sleep(delay);

  if (vg_exit() != 0)
    return 1;
  return 0;
}

int(video_test_rectangle)(uint16_t mode, uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint32_t color) {
  vg_init_success = 0;
  vg_init(mode);
  if (vg_init_success)
    return 1;
    
  if (verify_screen_limits(mode, x, y, width, height) != 0) {
    return 1;
  }
  if (vg_draw_rectangle(x, y, width, height, color) != 0)
    return 1;

  uint8_t* bit_no = (uint8_t*) malloc(sizeof(uint8_t));
  if (keyboard_subscribe_int(bit_no) != 0)
    return 1;

  message msg;
  int ipc_status, r;
  uint32_t irq_set = BIT(*bit_no);

  while (scan_bytes[0] != ESC_CODE) {
    if ((r = driver_receive(ANY, &msg, &ipc_status)) != 0 ) {
      printf("driver_receive failed with: %d", r);
      continue;
    }

    if (is_ipc_notify(ipc_status)) {
      switch (_ENDPOINT_P(msg.m_source)) {
        case HARDWARE:
        if (msg.m_notify.interrupts & irq_set) {
          kbc_ih();

          if (ih_success != 0)
            continue;
          if (full_scancode)
            num_bytes = 0;
        }
        break;
        default:
          break;
      }
    }
  }

  if (keyboard_unsubscribe_int() != 0)
    return 1;

  if (vg_exit() != 0)
    return 1;
  return 0;
}

int(video_test_pattern)(uint16_t mode, uint8_t no_rectangles, uint32_t first, uint8_t step) {
  vg_init_success = 0;
  vg_init(mode);
  if (vg_init_success) {
    vg_exit();
    return 1;
  }

  uint8_t* bit_no = (uint8_t*) malloc(sizeof(uint8_t));
  if (keyboard_subscribe_int(bit_no) != 0) {
    vg_exit();
    return 1;
  }

  if (vg_draw_pattern(no_rectangles, first, step) != 0) {
    vg_exit();
    return 1;
  }

  message msg;
  int ipc_status, r;
  uint32_t irq_set = BIT(*bit_no);

  while (scan_bytes[0] != ESC_CODE) {
    if ((r = driver_receive(ANY, &msg, &ipc_status)) != 0 ) {
      printf("driver_receive failed with: %d", r);
      continue;
    }

    if (is_ipc_notify(ipc_status)) {
      switch (_ENDPOINT_P(msg.m_source)) {
        case HARDWARE:
        if (msg.m_notify.interrupts & irq_set) {
          kbc_ih();

          if (ih_success != 0)
            continue;
          if (full_scancode)
            num_bytes = 0;
        }
        break;
        default:
          break;
      }
    }
  }

  if (keyboard_unsubscribe_int() != 0) {
    vg_exit();
    return 1;
  }

  if (vg_exit() != 0)
    return 1;
  return 0;
}

int(video_test_xpm)(xpm_map_t xpm, uint16_t x, uint16_t y) {
  vg_init_success = 0;
  vg_init(0x105);
  if (vg_init_success) {
    vg_exit();
    return 1;
  }

  if (verify_screen_limits(0x105, x, y, 0, 0) != 0)
    return 1;

  uint8_t* bit_no = (uint8_t*) malloc(sizeof(uint8_t));
  if (keyboard_subscribe_int(bit_no) != 0) {
    vg_exit();
    return 1;
  }

  if (vg_draw_xpm(xpm, x, y) != 0) {
    vg_exit();
    return 1;    
  }

  message msg;
  int ipc_status, r;
  uint32_t irq_set = BIT(*bit_no);

  while (scan_bytes[0] != ESC_CODE) {
    if ((r = driver_receive(ANY, &msg, &ipc_status)) != 0 ) {
      printf("driver_receive failed with: %d", r);
      continue;
    }

    if (is_ipc_notify(ipc_status)) {
      switch (_ENDPOINT_P(msg.m_source)) {
        case HARDWARE:
        if (msg.m_notify.interrupts & irq_set) {
          kbc_ih();

          if (ih_success != 0)
            continue;
          if (full_scancode)
            num_bytes = 0;
        }
        break;
        default:
          break;
      }
    }
  }

  if (keyboard_unsubscribe_int() != 0) {
    vg_exit();
    return 1;
  }

  if (vg_exit() != 0)
    return 1;
  return 0;
}

int(video_test_move)(xpm_map_t xpm, uint16_t xi, uint16_t yi, uint16_t xf, uint16_t yf, int16_t speed, uint8_t fr_rate) {
  vg_init_success = 0;
  vg_init(0x105);
  if (vg_init_success) {
    vg_exit();
    return 1;
  }

  if (verify_screen_limits(0x105, xi, yi, 0, 0) != 0)
    return 1;
  if (verify_screen_limits(0x105, xf, yf, 0, 0) != 0)
    return 1;

  if (timer_set_frequency(0, fr_rate) != 0)
    return 1;

  uint8_t* kbc_bit_no = (uint8_t*) malloc(sizeof(uint8_t));
  uint8_t* timer_bit_no = (uint8_t*) malloc(sizeof(uint8_t));
  if (keyboard_subscribe_int(kbc_bit_no) != 0) {
    vg_exit();
    return 1;
  }
  if (timer_subscribe_int(timer_bit_no) != 0) {
    printf("Failed keyboard_subscribe_int\n");
    return 1;
  }

  message msg;
  int ipc_status, r;
  uint32_t kbc_irq_set = BIT(*kbc_bit_no);
  uint32_t timer_irq_set = BIT(*timer_bit_no);

  uint16_t x = xi, y = yi;

  while (scan_bytes[0] != ESC_CODE) {
    if ((r = driver_receive(ANY, &msg, &ipc_status)) != 0 ) {
      printf("driver_receive failed with: %d", r);
      continue;
    }

    if (is_ipc_notify(ipc_status)) {
      switch (_ENDPOINT_P(msg.m_source)) {
        case HARDWARE:
        if (msg.m_notify.interrupts & timer_irq_set) {
          if (vg_move_xpm(xpm, xi, yi, xf, yf, &x, &y, speed) != 0) {
            vg_exit();
            return 1;
          }
        }
        if (msg.m_notify.interrupts & kbc_irq_set) {
          kbc_ih();

          if (ih_success != 0)
            continue;
          if (full_scancode)
            num_bytes = 0;
        }
        break;
        default:
          break;
      }
    }
  }

  if (keyboard_unsubscribe_int() != 0) {
    vg_exit();
    return 1;
  }

  if (vg_exit() != 0)
    return 1;
  return 0;
}
