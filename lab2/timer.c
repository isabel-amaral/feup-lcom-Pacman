#include <lcom/lcf.h>
#include <lcom/timer.h>

#include <stdint.h>

#include "i8254.h"

int (timer_set_frequency)(uint8_t timer, uint32_t freq) {
  /* To be implemented by the students */
  printf("%s is not yet implemented!\n", __func__);

  return 1;
}

int (timer_subscribe_int)(uint8_t *bit_no) {
    /* To be implemented by the students */
  printf("%s is not yet implemented!\n", __func__);

  return 1;
}

int (timer_unsubscribe_int)() {
  /* To be implemented by the students */
  printf("%s is not yet implemented!\n", __func__);

  return 1;
}

void (timer_int_handler)() {
  /* To be implemented by the students */
  printf("%s is not yet implemented!\n", __func__);
}

/* To be implemented by the students */
int (timer_get_conf)(uint8_t timer, uint8_t *st) {  
  if (timer != 0 && timer != 1 && timer != 2)
    return 1;
  
  uint8_t read_back_cmd = TIMER_RB_CMD | TIMER_RB_COUNT_| TIMER_RB_SEL(timer);
  sys_outb(0x43, (uint32_t) read_back_cmd);
  
  switch (timer) {
  case 0:
    if (util_sys_inb(TIMER_0, st) != 0)
      return 1;
    break;
  case 1:
    if (util_sys_inb(TIMER_1, st) != 0)
      return 1;
    break;
  case 2:
    if (util_sys_inb(TIMER_2, st) != 0)
      return 1;
  }
  return 0;
}

int (timer_display_conf)(uint8_t timer, uint8_t st,
                        enum timer_status_field field) {
  union timer_status_field_val u;

  if (timer != 0 && timer != 1 && timer != 2)
    return 1;

  if (field == tsf_all)
    u.byte = st;

  else if (field == tsf_initial) {
    uint8_t mask = 0x30; // 0011 0000
    st &= mask;
    st >> 4;

    switch (st) {
    case 1: u.in_mode = LSB_only;
      break;
    case 2: u.in_mode = MSB_only;
      break;
    case 3: u.in_mode = MSB_after_LSB;
      break;
    default: u.in_mode = INVAL_val; 
    }
  }

  else if (field == tsf_mode) {
    uint8_t mask = 0x0e; // 0000 1110
    st &= mask;
    st >> 1;

    if (st != 6 && st != 7)
      u.count_mode = st;
    else if (st == 6)
      u.count_mode = 2;
    else if (st == 7)
      u.count_mode = 3;
  }

  else if (field == tsf_base) {
    uint8_t mask = 0x01; // 0000 0001
    st &= mask;
    u.bcd = st;
  }

  return timer_print_config(timer, field, u);
}
