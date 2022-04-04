#include <lcom/lcf.h>

#include "i8042.h"
#include "keyboard.h"
#include <stdint.h>

int* kb_hook_id;
int ih_success;
bool make_code;
int num_bytes;
int scan_bytes[2];

int (keyboard_subscribe_int)(uint8_t *bit_no) {
  kb_hook_id = (int*) malloc(sizeof(int));
  *kb_hook_id = KEYBOARD_IRQ;
  *bit_no = KEYBOARD_IRQ;
  if (sys_irqsetpolicy(KEYBOARD_IRQ, IRQ_REENABLE | IRQ_EXCLUSIVE, kb_hook_id) != 0)
    return 1;
  return 0;
}

int (keyboard_unsubscribe_int)() {
  if (sys_irqrmpolicy(kb_hook_id) != 0)
    return 1;
  return 0;
}

void (kbc_ih)() {
  ih_success = 0;

  // Tries to read the OUT_BUF 3 times
  for (int i = 0; i < 3; i++) {
      uint8_t* status = (uint8_t*) malloc(sizeof(uint8_t));
    if (util_sys_inb(ST_REG, status) != 0) {
      ih_success = 1;
      return;
    }

    if (!(*status & OBF)) {
      num_bytes = 0;
      return;
    }

    uint8_t* scancode = (uint8_t*) malloc(sizeof(uint8_t));
    if (util_sys_inb(OUT_BUF_REG, scancode) != 0) {
      ih_success = 1;
      return;
    }

    if (*status & (PAR_ERR | TO_ERR)) {
      num_bytes = 0;
      return;
    }

    if (*scancode == SCAN_MSB) {
      num_bytes = 2;
      scan_bytes[1] = SCAN_MSB;
    }
    else {
      scan_bytes[0] = *scancode;
      if (*scancode & BIT(7))
        make_code = false;
      else
        make_code = true;
    }
  }
}
