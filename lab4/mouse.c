#include <lcom/lcf.h>

#include "mouse.h"
#include "i8042.h"
#include <stdint.h>

int* mouse_hook_id;

int (mouse_subscribe_int)(uint8_t *bit_no) {
  mouse_hook_id = (int*) malloc(sizeof(int));
  *mouse_hook_id = MOUSE_IRQ;
  *bit_no = MOUSE_IRQ;
  if (sys_irqsetpolicy(MOUSE_IRQ, IRQ_REENABLE | IRQ_EXCLUSIVE, mouse_hook_id) != 0)
    return 1;
  return 0;
}

int (mouse_unsubscribe_int)() {
  if (sys_irqrmpolicy(mouse_hook_id) != 0)
    return 1;
  return 0;
}