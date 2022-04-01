#include <lcom/lcf.h>
#include <keyboard.h>

#include <stdint.h>

int* kb_hook_id;

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
  /* To be completed */
}

#include "i8042.h"
