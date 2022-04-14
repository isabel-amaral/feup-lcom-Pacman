#include <lcom/lcf.h>
#include <lcom/lab3.h>

#include <stdbool.h>
#include <stdint.h>

#include "keyboard.h"
#include "i8042.h"

extern uint32_t cnt;
extern int* kb_hook_id;
extern int ih_success;
extern bool make_code;
extern int num_bytes;
extern uint8_t scan_bytes[2];
extern bool full_scancode;

int main(int argc, char *argv[]) {
  // sets the language of LCF messages (can be either EN-US or PT-PT)
  lcf_set_language("EN-US");

  // enables to log function invocations that are being "wrapped" by LCF
  // [comment this out if you don't want/need it]
  lcf_trace_calls("/home/lcom/labs/lab3/trace.txt");

  // enables to save the output of printf function calls on a file
  // [comment this out if you don't want/need it]
  lcf_log_output("/home/lcom/labs/lab3/output.txt");

  // handles control over to LCF
  // [LCF handles command line arguments and invokes the right function]
  if (lcf_start(argc, argv))
    return 1;

  // LCF clean up tasks
  // [must be the last statement before return]
  lcf_cleanup();

  return 0;
}

int(kbd_test_scan)() {
  uint8_t* bit_no = (uint8_t*) malloc(sizeof(uint8_t));
  if (keyboard_subscribe_int(bit_no) != 0) {
    printf("Failed keyboard_subscribe_int\n");
    return 1;
  }

  cnt = 0;
  num_bytes = 0;
  uint32_t irq_set = BIT(*bit_no);
  int ipc_status, r;
  message msg;

  while(scan_bytes[0] != ESC_CODE) {
    if((r = driver_receive(ANY, &msg, &ipc_status)) != 0) {
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
          if (full_scancode) {
            kbd_print_scancode(make_code, num_bytes, scan_bytes);
            num_bytes = 0;
          }
        }
        break;
        default:
          break;
      }
    }
  }

  if (kbd_print_no_sysinb(cnt) != 0) {
    printf("Failed kbd_print_no_sysinb\n");
    return 1;
  }
  if (keyboard_unsubscribe_int() != 0) {
    printf("Failed keyboard_unsubscribe_int\n");
    return 1;
  }

  return 0;
}

int(kbd_test_poll)() {
  cnt = 0;
  num_bytes = 0;

  while(scan_bytes[0] != ESC_CODE) {
    kbc_ih();

    if (ih_success != 0)
      continue;
    if (full_scancode) {
      kbd_print_scancode(make_code, num_bytes, scan_bytes);
      num_bytes = 0;
    }
  }

  if (kbd_print_no_sysinb(cnt) != 0) {
    printf("Failed kbd_print_no_sysinb\n");
    return 1;
  }

  if (kbc_enable_int() != 0) {
    printf("Failed kbc_enable_int\n");    
    return 1;
  }
  return 0;
}

int(kbd_test_timed_scan)(uint8_t n) {
  /* To be completed by the students */
  printf("%s is not yet implemented!\n", __func__);

  return 1;
}
