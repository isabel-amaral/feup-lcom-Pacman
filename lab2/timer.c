#include <lcom/lcf.h>
#include <lcom/timer.h>

#include <stdint.h>

#include "i8254.h"


int (timer_set_frequency)(uint8_t timer, uint32_t freq) {

  /* The maximum value that can be represented using 16 bits is 0xffff. In other words, 0xffff 
  (=65 535) is the maximum value that can be loaded to the timer address. Therefore any frequency (@freq) lower than 19 is invalid since it would cause an overflow. */
  if (freq < 19 || freq > TIMER_FREQ) 
    return 1;

  uint8_t* st = (uint8_t*) malloc(sizeof(uint8_t));

  if (timer_get_conf(timer, st) != 0) 
    return 1;
  uint8_t mask = 0x0f;
  *st &= mask;
  *st |= BIT(4) | BIT(5);

  int timer_address;
  switch(timer) {
    case 0:
      *st |= TIMER_SEL0;
      timer_address = TIMER_0;
      break;
    case 1:
      *st |= TIMER_SEL1;
      timer_address = TIMER_1;
      break;
    case 2:
      *st |= TIMER_SEL2;
      timer_address = TIMER_2;
      break;
  }

  uint16_t counter_value = (uint16_t) TIMER_FREQ/freq;
  uint8_t* lsb = (uint8_t*) malloc(sizeof(uint8_t));
  uint8_t* msb = (uint8_t*) malloc(sizeof(uint8_t));

  if (util_get_LSB(counter_value, lsb) != 0)
    return 1;
  if (util_get_MSB(counter_value, msb) != 0)
    return 1;

  if (sys_outb(TIMER_CTRL, *st) != 0) 
    return 1;
  if (sys_outb(timer_address, *lsb) != 0) 
    return 1;
  if (sys_outb(timer_address, *msb) != 0) 
    return 1;

  return 0;
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

int (timer_display_conf)(uint8_t timer, uint8_t st, enum timer_status_field field) {
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
