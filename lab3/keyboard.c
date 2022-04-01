#include <lcom/lcf.h>
#include <keyboard.h>

#include <stdint.h>

int (keyboard_subscribe_int)(uint8_t *bit_no) {
  // hook_id = (int*) malloc(sizeof(int));
  // *hook_id = TIMER0_IRQ;
  // *bit_no = TIMER0_IRQ;
  // if (sys_irqsetpolicy(TIMER0_IRQ, IRQ_REENABLE, hook_id) != 0)
  //   return 1;
  // return 0;
}

int (timer_unsubscribe_int)() {
  // if (sys_irqrmpolicy(hook_id) != 0)
  //   return 1;
  // return 0;
}


void (kbc_ih)() {
  /* To be completed */
}

#include "i8042.h"
