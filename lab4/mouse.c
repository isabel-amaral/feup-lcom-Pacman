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

int (my_mouse_enable_data_reporting)() {
  for (int i = 0; i < 3; i++) {
    uint8_t* status = (uint8_t*) malloc(sizeof(uint8_t));
    if (util_sys_inb(ST_REG, status) != 0)
      return 1;

    if (*status & IBF)
      return 1;

    if (sys_outb(KBC_CMD_REG, WRITE_MOUSE_BYTE) != 0)
      return 1;
    if (sys_outb(KBC_CMD_REG, ENABLE_DATA) != 0)
      return 1;

    uint8_t* acknowledgement = (uint8_t*) malloc(sizeof(uint8_t));
    if (util_sys_inb(OUT_BUF_REG, acknowledgement) != 0)
      return 1;
    if (acknowledgement == ACK)
      return 0;
    if (acknowledgement == ERROR)
      return 1;
  }
  return 1;
}

int (my_mouse_disable_data_reporting)() {
  for (int i = 0; i < 3; i++) {
    uint8_t* status = (uint8_t*) malloc(sizeof(uint8_t));
    if (util_sys_inb(ST_REG, status) != 0)
      return 1;

    if (*status & IBF)
      return 1;

    if (sys_outb(KBC_CMD_REG, WRITE_MOUSE_BYTE) != 0)
      return 1;
    if (sys_outb(KBC_CMD_REG, DISABLE_DATA) != 0)
      return 1;

    uint8_t* acknowledgement = (uint8_t*) malloc(sizeof(uint8_t));
    if (util_sys_inb(OUT_BUF_REG, acknowledgement) != 0)
      return 1;
    if (acknowledgement == ACK)
      return 0;
    if (acknowledgement == ERROR)
      return 1;
  }
  return 1;
}